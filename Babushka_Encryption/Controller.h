#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Babushka.h"
#include "ReturnStruct.h"
#include "DarkBlueBabushka.h"
#include "LightBlueBabushka.h"
#include "GoldBabushka.h"
#include "GreenBabushka.h"
#include "RedBabushka.h"
#include "YellowBabushka.h"
#include "ControllerException.h"

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <cstring>

class Controller
{
    private:
        Babushka** babushkaArr;
        unsigned int numBabushkas;
    public:
        Controller(std::string filePath);
        ~Controller();
        ReturnStruct decrypt(const unsigned char* array, unsigned int size);
        ReturnStruct encrypt(const unsigned char* array, unsigned int size);
        ReturnStruct expandArray(unsigned char* array, unsigned int currentSize, const unsigned char* id, int idSize);
        ReturnStruct reduceArray(unsigned char* array, unsigned int currentSize, const unsigned char* expectedId, int idSize);
        void printArray(unsigned char* array, unsigned int size);
};

#endif