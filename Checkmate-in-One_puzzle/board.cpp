#include "board.h"

piece** addPiece(piece** oldPieces, unsigned oldSize, piece* newPiece)
{
    int newSize = oldSize + 1;

    piece** newPieces = new piece*[newSize];

    if (oldPieces != nullptr)
    {
        for (unsigned i = 0; i < oldSize; i++)
        {
            newPieces[i] = oldPieces[i];
        }
    }
    
    newPieces[newSize - 1] = newPiece;
    return newPieces;
}

board::board(std::string pieceList)
{
    std::ifstream file(pieceList, std::ios::in);

    if(file.fail())
    {
        std::cout << "Error: " << pieceList << " could not be opened." << std::endl;
        exit(1);
    }

    //initialize piece counters to 0.
    this->numBlackPieces = 0;
    this->numWhitePieces = 0;

    this->whitePieces = new piece*[0]; // assuming maximum of 16 white pieces
    this->blackPieces = new piece*[0]; // assuming maximum of 16 black pieces

    //create empty 8x8 chess board
    this->chessboard = new std::string*[8];
    for (unsigned i = 0; i < 8; i++)
    {
        this->chessboard[i] = new std::string[8];
    }
    for (unsigned i = 0; i < 8; i++)
    {
        for (unsigned j = 0; j < 8; j++)
        {
            this->chessboard[i][j] = "-";
        }
    }

    std::string line;

    //get the side to move from the first line in the text file
    getline(file, line);
    this->sideToMove = line[0];

    //get the move going to be made from the second line
    getline(file, this->move);

    //extract the board setup from the remaining lines of the text file
    while(!file.eof())
    {
        getline(file, line);
        std::stringstream ss(line);

        int count = 0;
        char side;
        std::string type;
        int x, y;

        while(ss.good())
        {
            std::string str;
            getline(ss, str, ',');

            if (count == 0) side = str[0];
            if (count == 1) type = str;
            if (count == 2) x = stoi(str);
            if (count == 3) y = stoi(str);
        
            count++;
        }

        std::string boardCode = std::to_string(side) + type[0];

        if (side == 'b')
        {
            piece* tmp = new piece(type, side, x, y);
            piece** arrTmp = addPiece(this->blackPieces, this->numBlackPieces, tmp);
            delete[] this->blackPieces;
            this->blackPieces = arrTmp;
            this->chessboard[x][y] = boardCode;
            this->numBlackPieces++;
        }

        if (side == 'w')
        {
            piece* tmp = new piece(type, side, x, y);
            piece** arrTmp = addPiece(this->whitePieces, this->numWhitePieces, tmp);
            delete[] this->whitePieces;
            this->whitePieces = arrTmp;
            this->chessboard[x][y] = boardCode;
            this->numWhitePieces++;
        }
    }

    file.close();
}

board::~board()
{
    unsigned numPieces = 0;

    for (unsigned i = 0; i < this->numBlackPieces; i++)
    {
        delete this->blackPieces[i];
        numPieces++;
    }
    this->numBlackPieces = 0;
    delete [] this->blackPieces;

    for (unsigned i = 0; i < this->numWhitePieces; i++)
    {
        delete this->whitePieces[i];
        numPieces++;
    }
    this->numWhitePieces = 0;
    delete [] this->whitePieces;

    for (unsigned i = 0; i < 8; i++)
    {
        for (unsigned j = 0; j < 8; j++)
        {
            this->chessboard[i][j].std::string::erase();
        }
        delete [] this->chessboard[i];
    }
    delete [] this->chessboard;

    std::cout << "Num Pieces Removed: " << numPieces << std::endl;
}

board& board::operator++()
{
    std::stringstream ss(this->move);
    std::string str;
    unsigned initX, initY, destX, destY;
    std::string coords = this->move.substr(4);

    unsigned count = 0;

    while(std::getline(ss, str, ','))
    {
        switch(count)
        { 
            case 0: 
                initX = stoi(str); 
                break;
            case 1: 
                initY = stoi(str); 
                break;
            case 2: 
                destX = stoi(str); 
                break;
            case 3: 
                destY = stoi(str); 
                break;  
        }
        count++;
    }

    std::string boardCode;

    //Assuming movement is correct and not letting king in check.
    if (this->sideToMove == 'b')
    {
        for (unsigned i = 0; i < this->numBlackPieces; i++)
        {
            if(this->blackPieces[i]->getX() == initX && this->blackPieces[i]->getY() == initY)
            {
                //Use the overload operator+ from the piece class
                *this->blackPieces[i] + coords;
                boardCode = this->blackPieces[i]->getSide() + this->blackPieces[i]->getPieceType()[0];
            }
        }
    }
    else if (this->sideToMove == 'w')
    {
        for (unsigned i = 0; i < this->numWhitePieces; i++)
        {
            if(this->whitePieces[i]->getX() == initX && this->whitePieces[i]->getY() == initY)
            {
                //Use the overload operator+ from the piece class
                *this->whitePieces[i] + coords;
                boardCode = this->whitePieces[i]->getSide() + this->whitePieces[i]->getPieceType()[0];
            }
        }
    }

    this->chessboard[destX][destY] = boardCode;
    this->chessboard[initX][initY] = "-";

    return *this;
}

board& board::operator--()
{
    char opponent = (sideToMove == 'w') ? 'b' : 'w';
    unsigned kingX, kingY;
    bool checkmate = false;
    bool check = false;

    //find the opposing king's position
    for (unsigned i = 0; i < 8; i++)
    {
        for(unsigned j = 0; j < 8; j++)
        {
            if(chessboard[i][j] == (opponent + "K"))
            {
                kingX = i;
                kingY = j;
                break;
            }
        }
    }

    //perform move
    ++(*this);

    unsigned xPos = std::stoi(this->move.substr(4,1));
    unsigned yPos = std::stoi(this->move.substr(6,1));
    std::string type;

    if (sideToMove == 'w')
    {
        for (unsigned i = 0; i < this->numWhitePieces; i++)
        {
            if (this->whitePieces[i]->getX() == xPos && this->whitePieces[i]->getY() == yPos)
            {
                type = this->whitePieces[i]->getPieceType();
                break;
            }
        }
    }
    else if (sideToMove == 'b')
    {
        for (unsigned i = 0; i < this->numBlackPieces; i++)
        {
            if (this->blackPieces[i]->getX() == xPos && this->blackPieces[i]->getY() == yPos)
            {
                type = this->blackPieces[i]->getPieceType();
                break;
            }
        }
    }

    check = checkIfPieceHasCheck(type, xPos, yPos, kingX, kingY);
    std::cout << "Check: " << std::boolalpha << check << std::endl;

    //check if the opposing king as any possible move that would not be in check
    if (check)
    {
        for(int i = kingX - 1; i <= kingX + 1; i++)
        {
            //if(i < 0 || i > 7) continue;
            for(int j = kingY-1; j <= kingY+1; j++)
            {
                //if(j < 0 || j > 7) continue;

                if (sideToMove == 'w')
                {
                    for (unsigned k = 0; k < this->numWhitePieces; k++)
                    {
                        if (checkIfPieceHasCheck(this->whitePieces[k]->getPieceType(), this->whitePieces[k]->getX(), this->whitePieces[k]->getY(), i, j))
                        {
                            checkmate = true;
                            break;
                        }
                    }
                }
                else if (sideToMove == 'b')
                {
                    for (unsigned k = 0; k < this->numBlackPieces; k++)
                    {
                        if (checkIfPieceHasCheck(this->blackPieces[k]->getPieceType(), this->blackPieces[k]->getX(), this->blackPieces[k]->getY(), i, j))
                        {
                            checkmate = true;
                            break;
                        }
                    }
                }
            }
        }
    }
    std::cout << "Checkmate: " << std::boolalpha << checkmate << std::endl;
    //output the result
    if(checkmate)
    {
        std::cout << "Success: Checkmate of " << opponent << " King at [" << kingX << "," << kingY << "]" << std::endl;
    } else 
    {
        std::cout << "Failed: No Checkmate of " << opponent << " King" << std::endl;
    }
    return *this;
}

bool board::checkIfPieceHasCheck(std::string pieceType, int xPos, int yPos, int kingX, int kingY)
{
    // Check if the coordinates of the piece and king are within the board boundaries
    if (xPos < 0 || xPos > 7 || yPos < 0 || yPos > 7 || kingX < 0 || kingX > 7 || kingY < 0 || kingY > 7) 
    {
        return false;
    }

    // Check if the piece can check the king
    if (pieceType == "King")
    {
        return false;
    }

    bool check = false;

    enum PieceType {PAWN, KNIGHT, BISHOP, ROOK, QUEEN};

    PieceType p;

    if(pieceType == "pawn")
    {
        p = PAWN;
    }
    else if(pieceType == "knight")
    {
        p = KNIGHT;
    }
    else if(pieceType == "bishop")
    {
        p = BISHOP;
    }
    else if(pieceType == "rook")
    {
        p = ROOK;
    }
    else if(pieceType == "queen")
    {
        p = QUEEN;
    }

    switch (p)
    {
        case PAWN:
        {
            if(xPos+1 == kingX && abs(yPos-kingY) == 1) 
                check = true;
            break;
        }
        case KNIGHT:
        {
            if((abs(xPos-kingX) == 2 && abs(yPos-kingY) == 1) || (abs(xPos-kingX) == 1 && abs(yPos-kingY) == 2)) 
                check = true;
            break;
        }
        case BISHOP:
        {
            if(abs(xPos-kingX) == abs(yPos-kingY))
            {
                int x_d = xPos > kingX ? -1 : 1;
                int y_d = yPos > kingY ? -1 : 1;
                for(int i = xPos+x_d,j = yPos+y_d; i != kingX && j != kingY; i+=x_d,j+=y_d)
                {
                    if(chessboard[i][j] != "-")
                    {
                        check = false;
                        break;
                    }
                    check = true;
                }
            }
            break;
        }
        case ROOK:
        {
            if(xPos == kingX || yPos == kingY)
            {
                int x_d = xPos > kingX ? -1 : 1;
                int y_d = yPos > kingY ? -1 : 1;
                if(xPos == kingX) y_d = 0;
                if(yPos == kingY) x_d = 0;
                for(int i = xPos + x_d, j = yPos + y_d; i != kingX && j != kingY; i += x_d, j += y_d)
                {
                    if(chessboard[i][j] != "-")
                    {
                        check = false;
                        break;
                    }
                    check = true;
                }
            }
            break;
        }
        case QUEEN:
        {
            if(abs(xPos-kingX) == abs(yPos-kingY))
            {
                int x_d = xPos > kingX ? -1 : 1;
                int y_d = yPos > kingY ? -1 : 1;
                for(int i = xPos+x_d,j = yPos+y_d; i != kingX && j != kingY; i+=x_d,j+=y_d)
                {
                    if(chessboard[i][j] != "-")
                    {
                        check = false;
                        break;
                    }
                    check = true;
                }
            }

            if(xPos == kingX || yPos == kingY)
            {
                int x_d = xPos > kingX ? -1 : 1;
                int y_d = yPos > kingY ? -1 : 1;
                if(xPos == kingX) y_d = 0;
                if(yPos == kingY) x_d = 0;
                for(int i = xPos + x_d, j = yPos + y_d; i != kingX && j != kingY; i += x_d, j += y_d)
                {
                    if(chessboard[i][j] != "-")
                    {
                        check = false;
                        break;
                    }
                    check = true;
                }
            }
            break;            
        }
    }


    //std::cout << std::boolalpha << check << std::endl;

    return check;
}