#ifndef DARK_BLUE_BABUSHKA_H
#define DARK_BLUE_BABUSHKA_H

#include "BlueBabushka.h"

class DarkBlueBabushka : public BlueBabushka
{
    public:
        DarkBlueBabushka(const unsigned char* id, unsigned int amount);
        virtual void decrypt(unsigned char* data, int size);
        virtual void encrypt(unsigned char* data, int size);
};
#endif