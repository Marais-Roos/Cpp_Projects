#ifndef YELLOW_BABUSHKA_H
#define YELLOW_BABUSHKA_H

#include "Babushka.h"

class YellowBabushka : public Babushka
{
    public:
        YellowBabushka(const unsigned char* id);
        void decrypt(unsigned char* data, int size);
        void encrypt(unsigned char* data, int size);
};
#endif