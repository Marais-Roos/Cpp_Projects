#ifndef GREEN_BABUSHKA_H
#define GREEN_BABUSHKA_H

#include "Babushka.h"
#include "DisplacementException.h"

class GreenBabushka : public Babushka
{
    private:
        unsigned int displacement;
    public:
        GreenBabushka(const unsigned char* id, unsigned int displacement);
        void decrypt(unsigned char* data, int size);
        void encrypt(unsigned char* data, int size);
};
#endif