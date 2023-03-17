#include "solver.h"

std::pair<unsigned*, board**> add(board** oldBoards, unsigned* oldPriorities, unsigned size, unsigned p, std::string f)
{
    unsigned newSize = size + 1;

    board** newBoards = new board*[newSize];
    unsigned* newPriorities = new unsigned[newSize];

    if (oldBoards != nullptr && oldPriorities != nullptr)
    {
        for (unsigned i = 0; i < size; i++)
        {
            newBoards[i] = oldBoards[i];
            newPriorities[i] = oldPriorities[i];
        }
    }
    
    newBoards[newSize - 1] = new board(f);
    newPriorities[newSize - 1] = p;

    std::pair<unsigned*, board**> result(newPriorities, newBoards);
    return result;
}

void sort(unsigned* priorities, board** boards, unsigned size)
{
    for (unsigned i = 0; i < size - 1; i++)
    {
        for (unsigned j = 0; j < size - i - 1; j++)
        {
            if (priorities[j] > priorities[j + 1])
            {
                //swap the priorities
                unsigned tmpPriority = priorities[j];
                priorities[j] = priorities[j + 1];
                priorities[j + 1] = tmpPriority;

                //swap corresponding boards
                board* tmpBoard = boards[j];
                boards[j] = boards[j + 1];
                boards[j + 1] = tmpBoard;
            }
        }
    }
}

solver::solver(std::string games)
{
    std::ifstream listFile(games, std::ios::in);
    this->numGames = 0;

    unsigned *priorities = new unsigned[this->numGames];
    this->boards = new board*[this->numGames];

    if (!listFile.fail())
    {
        std::cout << "Couldn't open " << games << std::endl;
        exit(1);
    }

    std::string line;

    while(getline(listFile, line))
    {
        std::string file = line.substr(0, line.find(','));
        unsigned priority = stoi(line.substr(line.find(',') + 1));

        std::pair<unsigned*, board**> tmp = add(this->boards, priorities, this->numGames, priority, file);

        delete [] this->boards;
        this->boards = tmp.second;
        delete [] priorities;
        priorities = tmp.first;

        this->numGames++;
    }

    sort(priorities, this->boards, this->numGames);

    for (unsigned i = 0; i < this->numGames; i++)
    {
        std::cout << "[" << priorities[i] << "] ";
        --(*this->boards[i]);
    }
}

solver::~solver()
{
    unsigned int i;
    for (i = 0; i < this->numGames; ++i)
    {
        delete this->boards[i];
        this->numGames--;
    }

    std::cout << "Num Boards Deleted: " << i+1 << std::endl;
}
