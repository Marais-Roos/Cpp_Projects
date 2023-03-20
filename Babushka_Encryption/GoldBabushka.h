#ifndef GOLD_BABUSHKA_H
#define GOLD_BABUSHKA_H

#include "Babushka.h"
#include "OverflowException.h"
#include "UnderflowException.h"

class GoldBabushka : public Babushka
{
    private:
        unsigned char xorValue;
    public:
        GoldBabushka(const unsigned char* id, unsigned char xorValue);
        virtual void decrypt(unsigned char* data, int size);
        virtual void encrypt(unsigned char* data, int size);
};
#endif