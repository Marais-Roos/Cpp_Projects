#include "GoldBabushka.h"

GoldBabushka::GoldBabushka(const unsigned char* id, unsigned char xorValue) : Babushka(id)
{
    this->xorValue = xorValue;
}

void GoldBabushka::decrypt(unsigned char* data, int size)
{
    for (unsigned i = 0; i < size; i++)
    {
        unsigned char newVal = data[i] ^ xorValue;
        if (newVal < MIN_VALUE_INCLUSIVE)
            throw UnderflowException();
        else if (newVal > MAX_VALUE_INCLUSIVE)
            throw OverflowException();
        else 
            data[i] = newVal;
    }
}

void GoldBabushka::encrypt(unsigned char* data, int size)
{
    for (unsigned i = 0; i < size; i++)
    {
        unsigned char newVal = data[i] ^ xorValue;
        if (newVal < MIN_VALUE_INCLUSIVE)
            throw UnderflowException();
        else if (newVal > MAX_VALUE_INCLUSIVE)
            throw OverflowException();
        else 
            data[i] = newVal;
    }
}
