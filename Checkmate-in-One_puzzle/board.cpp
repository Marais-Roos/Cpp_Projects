#include "board.h"

board::board(std::string pieceList)
{
    std::ifstream file(pieceList, std::ios::in);

    if (file.fail())
    {
        std::cout << "Error: Could not open " << pieceList << std::endl;
        exit(1);
    }

    std::string line;

    getline(file, line); //get the first line - being the side that will make the move
    this->sideToMove = line[0];

    getline(file, this->move); //get the second line - being the move that will be made

    this->numBlackPieces = 0;
    this->numWhitePieces = 0;

    this->whitePieces = new piece*[16]; // assuming maximum of 16 white pieces
    this->blackPieces = new piece*[16]; // assuming maximum of 16 black pieces

    this->chessboard = new std::string*[8];
    for (int i = 0; i < 8; i++)
    {
        chessboard[i] = new std::string[8];
    }

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
            chessboard[i][j] = "-";
    }

    while (!file.eof())
    {
        getline(file, line);
        std::istringstream iss(line);

        std::vector<std::string> words{std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>{}};

        char side = words[0][0];
        std::string type = words[1];
        int x = stoi(words[2]);
        int y = stoi(words[3]);

        std::string code = std::to_string(side) + type[0];

        if (side == 'w')
        {
            this->whitePieces[numWhitePieces] = new piece(type, side, x, y);
            this->chessboard[x][y] = code;
            this->numWhitePieces++;
        }

        if (side == 'b')
        {
            this->blackPieces[numBlackPieces] = new piece(type, side, x, y);
            this->chessboard[x][y] = code;
            this->numBlackPieces++;
        }
    }

    file.close();
}

board::~board()
{
    for (int i = 0; i < this->numBlackPieces; i++)
    {
        delete this->blackPieces[i];
    }
    delete [] this->blackPieces;

    for (int i = 0; i < this->numWhitePieces; i++)
    {
        delete this->whitePieces[i];
    }
    delete [] this->whitePieces;

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            this->chessboard[i][j].std::string::erase();
        }
        delete [] this->chessboard[i];
    }
    delete [] this->chessboard;

    std::cout << "Num Pieces Removed: " << this->numBlackPieces + this->numWhitePieces << std::endl;
}

board& board::operator++()
{
    std::istringstream iss(this->move);
    std::vector<std::string> coords{std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>{}};

    int x1 = stoi(coords[0]);
    int y1 = stoi(coords[1]);
    int x2 = stoi(coords[2]);
    int y2 = stoi(coords[3]);

    std::string code;

    if (this->sideToMove == 'w')
    {
        for (int i = 0; i < this->numWhitePieces; i++)
        {
            if (this->whitePieces[i]->getX() == x1 && this->whitePieces[i]->getY() == y1)
            {
                *this->whitePieces[i] + (std::to_string(x2) + "," + std::to_string(y2));

                code = this->whitePieces[i]->getSide() + this->whitePieces[i]->getPieceType()[0];

                break;
            }
        }
    }
    
    if (this->sideToMove == 'b')
    {
        for (int i = 0; i < this->numWhitePieces; i++)
        {
            if (this->blackPieces[i]->getX() == x1 && this->blackPieces[i]->getY() == y1)
            {
                *this->blackPieces[i] + (std::to_string(x2) + "," + std::to_string(y2));

                code = this->blackPieces[i]->getSide() + this->blackPieces[i]->getPieceType()[0];

                break;
            }
        }
    }


    this->chessboard[x2][y2] = code;
    this->chessboard[x1][y1] = "-";

    return *this;
}

board& board::operator--()
{
    std::string opp = (sideToMove == 'w') ? "b" : "w";
    int kingX, kingY;
    bool checkmate = true;
    bool check = false;
    // find the position of the opposing king
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            if(chessboard[i][j] == (opp + "K"))
            {
                kingX = i;
                kingY = j;
                break;
            }
        }
    }
    // check if the current move is a check to the opposing king
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            if(chessboard[i][j].at(0) == sideToMove)
            {
                if(checkIfPieceHasCheck(chessboard[i][j].substr(1), i, j, kingX, kingY))
                {
                    check = true;
                    break;
                }
            }
        }
    }
    // check if the opposing king has any possible move that would not be in check
    if(check)
    {
        for(int i = kingX - 1; i <= kingX + 1; i++)
        {
            if(i < 0 || i > 7) continue;

            for(int j = kingY-1; j <= kingY+1; j++)
            {
                if(j < 0 || j > 7) continue;

                if(!checkIfPieceHasCheck(chessboard[i][j].substr(2),i,j,kingX,kingY))
                {
                    checkmate = false;
                    break;
                }
            }
        }
    }
    // output the result
    if(checkmate)
    {
        std::cout << "Success: Checkmate of " << opp << " King at [" << kingX << "," << kingY << "]" << std::endl;
    } else 
    {
        std::cout << "Failed: No Checkmate of " << opp << " King" << std::endl;
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
    if (pieceType != "pawn" && pieceType != "queen" && pieceType != "knight" && pieceType != "bishop" && pieceType != "rook")
    {
        return false;
    }

    bool check = false;

    if(pieceType == "pawn")
    {
        if(xPos+1 == kingX && abs(yPos-kingY) == 1) check = true;
    }
    else if(pieceType == "knight")
    {
        if((abs(xPos-kingX) == 2 && abs(yPos-kingY) == 1) || (abs(xPos-kingX) == 1 && abs(yPos-kingY) == 2)) check = true;
    }
    else if(pieceType == "bishop" || pieceType == "queen")
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
    }else if(pieceType == "rook" || pieceType == "queen")
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
    }
    return check;
}