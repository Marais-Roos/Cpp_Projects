#include "DarkBlueBabushka.h"

DarkBlueBabushka::DarkBlueBabushka(const unsigned char* id, unsigned int amount) : BlueBabushka(id, amount) {}

void DarkBlueBabushka::decrypt(unsigned char* data, int size)
{
    for (unsigned i = 0; i < size; i++)
    {
        unsigned char newVal = data[i] + amount;

        if (newVal > MAX_VALUE_INCLUSIVE) 
            throw OverflowException();
        else if (newVal < MIN_VALUE_INCLUSIVE) 
            throw UnderflowException();
        else 
            data[i] = newVal;
    }
}

void DarkBlueBabushka::encrypt(unsigned char* data, int size)
{
    for (unsigned i = 0; i < size; i++)
    {
        unsigned char newVal = data[i] - amount;

        if (newVal > MAX_VALUE_INCLUSIVE)
            throw OverflowException();
        else if (newVal < MIN_VALUE_INCLUSIVE) 
            throw UnderflowException();
        else 
            data[i] = newVal;
    }
}