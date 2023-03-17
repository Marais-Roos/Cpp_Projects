#ifndef SOLVER_H
#define SOLVER_H

#include "board.h"

class solver
{
private:
    unsigned numGames;
    board** boards;
public:
    solver(std::string games);
    ~solver();
};

#endif