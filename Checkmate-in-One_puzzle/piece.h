#ifndef PIECE_H
#define PIECE_H

#include <iostream>
#include <string>

class piece
{
private:
    std::string pieceType;
    char side;
    unsigned xPos;
    unsigned yPos;
public:
    piece();
    piece(piece* newPiece);
    piece(std::string pType, char side, int x, int y);
    ~piece();
    char getSide();
    std::string getPieceType();
    unsigned getX();
    unsigned getY();
    void setX(int x);
    void setY(int y);
    friend std::ostream& operator<<(std::ostream& output, const piece& t);
    void operator[](int pos);
    piece& operator+(std::string move);
};

#endif