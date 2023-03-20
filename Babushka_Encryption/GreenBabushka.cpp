#include "GreenBabushka.h"

GreenBabushka::GreenBabushka(const unsigned char* id, unsigned int displacement) : Babushka(id)
{
    this->displacement = displacement;
}

void GreenBabushka::decrypt(unsigned char* data, int size)
{
    if (displacement >= size)
        throw DisplacementException();
    else
    {
        for (unsigned i = size - 1; i >= displacement; i--)
        {
            unsigned char temp = data[i];
            data[i] = data[i - displacement];
            data[i - displacement] = temp;
        }
    }
}

void GreenBabushka::encrypt(unsigned char* data, int size)
{
    //assume that displacement is always greater than zero
    if (displacement >= size)
        throw DisplacementException();
    else
    {
        for (unsigned i = 0; i < size - displacement; i++)
        {
            unsigned char temp = data[i];
            data[i] = data[i + displacement];
            data[i + displacement] = temp;
        }
    }
}
