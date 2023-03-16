#ifndef BOARD_H
#define BOARD_H

#include <fstream>
#include <sstream>

#include "piece.h"

class board
{
private:
    unsigned numWhitePieces;
    unsigned numBlackPieces;
    piece** whitePieces;
    piece** blackPieces;
    std::string** chessboard;
    std::string move;
    char sideToMove;
    board& operator++();
    
public:
    board(std::string pieceList);
    ~board();
    board& operator--();
    bool checkIfPieceHasCheck(std::string pieceType, int xPos, int yPos, int kingX, int kingY);
};

#endif