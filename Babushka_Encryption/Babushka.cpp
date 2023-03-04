#include "Babushka.h"

const unsigned int ID_LENGTH = 10;
const unsigned char MAX_VALUE_INCLUSIVE = 126;
const unsigned char MIN_VALUE_INCLUSIVE = 32;

Babushka::Babushka(const unsigned char* id)
{
    this->id = id;
}

Babushka::~Babushka()
{
    delete [] id;
}

const int Babushka::getIdLength()
{
    return ID_LENGTH;
}

const unsigned char* Babushka::getId()
{
    return this->id;
}
