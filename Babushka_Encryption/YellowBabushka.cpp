#include "YellowBabushka.h"

YellowBabushka::YellowBabushka(const unsigned char* id) : Babushka(id) {}

void YellowBabushka::decrypt(unsigned char* data, int size)
{
    //same as encryption
    for (unsigned int i = 0; i < size/2; i++)
    {
        //swap the elements at index i and index size - 1 - i
        unsigned char temp = data[i];
        data[i] = data[size - 1 - i];
        data[size - 1 - i] = temp;
    }
}

void YellowBabushka::encrypt(unsigned char* data, int size)
{
    for (unsigned int i = 0; i < size/2; i++)
    {
        //swap the elements at index i and index size - 1 - i
        unsigned char temp = data[i];
        data[i] = data[size - 1 - i];
        data[size - 1 - i] = temp;
    }
}