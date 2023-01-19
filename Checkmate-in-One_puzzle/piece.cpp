#include "piece.h"

bool validateX_Y(int x, int y)
{
    if ((x >= 0 && x <= 7) && (y >= 0 && y <= 7)) return true;
    else return false;

}

piece::piece(){}

piece::piece(piece* newPiece)
{
    this->pieceType = newPiece->getPieceType();
    this->side = newPiece->getSide();
    if (validateX_Y(newPiece->getX(), newPiece->getY()))
    {
        this->setX(newPiece->getX());
        this->setY(newPiece->getY());
    }
}

piece::piece(std::string pType, char side, int x, int y)
{
    this->pieceType = pType;
    this->side = side;
    if (validateX_Y(x, y))
    {
        this->xPos = x;
        this->yPos = y;
    }
    
}

piece::~piece()
{
    std::cout << "(" << this->xPos << "," << this->yPos << ") ";
    this->xPos = 0;
    this->yPos = 0;
    std::cout << this->side;
    this->side = '\0';
    std::cout << " " << this->pieceType << " deleted\n";
    this->pieceType.erase();
}

char piece::getSide()
{
    return this->side;
}

std::string piece::getPieceType()
{
    return this->pieceType;
}

int piece::getX()
{
    return this->xPos;
}

int piece::getY()
{
    return this->yPos;
}

void piece::setX(int x)
{
    this->xPos = x;
}

void piece::setY(int y)
{
    this->yPos = y;
}

void piece::operator[](int pos)
{
    if (pos == 0)
    {
        std::cout << "x coord: " << xPos << std::endl;
    }
    else if (pos == 1)
    {
        std::cout << "y coord: " << yPos << std::endl;
    }
    else
    {
        std::cout << "Invalid Index\n";
    }
}

piece& piece::operator+(std::string move)
{
    int x = move[0] - '0';
    int y = move[2] - '0';

    if (validateX_Y(x, y))
    {
        xPos = x;
        yPos = y;
    }

    return *this;
}

//Friend of class
std::ostream& operator<<(std::ostream& output, const piece& t)
{
    output << t.side;
    output << " " << t.pieceType;
    output << " at [" << t.xPos;
    output << "," << t.yPos << "]\n";
    return output;
}