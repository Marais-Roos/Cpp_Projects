#include "RedBabushka.h"

RedBabushka::RedBabushka(const unsigned char* id, unsigned int rotationAmount) : Babushka(id)
{
    this->rotationAmount = rotationAmount;
}

void RedBabushka::decrypt(unsigned char* data, int size)
{
    if (rotationAmount >= size)
        throw RotateException();
    else
    {
        // Create a temporary array to hold the rotated elements
        unsigned char* temp = new unsigned char[rotationAmount];

        // Copy the first rotationAmount elements of the array into the temporary array
        for (int i = 0; i < rotationAmount; i++) 
        {
            temp[i] = data[i];
        }

        // Shift the remaining elements of the array to the left
        for (int i = rotationAmount; i < size; i++) 
        {
            data[i - rotationAmount] = data[i];
        }

        // Copy the rotated elements from the temporary array to the end of the array
        for (int i = size - rotationAmount; i < size; i++) 
        {
            data[i] = temp[i - (size - rotationAmount)];
        }

        // Free the temporary array
        delete[] temp;
    }
}

void RedBabushka::encrypt(unsigned char* data, int size)
{
    if (rotationAmount >= size)
        throw RotateException();
    else
    {
        // Create a temporary array to hold the rotated elements
        unsigned char* temp = new unsigned char[rotationAmount];

        // Copy the last rotationAmount elements of the array into the temporary array
        for (int i = 0; i < rotationAmount; i++) 
        {
            temp[i] = data[size - rotationAmount + i];
        }

        // Shift the remaining elements of the array to the right
        for (int i = size - 1; i >= rotationAmount; i--) 
        {
            data[i] = data[i - rotationAmount];
        }

        // Copy the rotated elements from the temporary array to the beginning of the array
        for (int i = 0; i < rotationAmount; i++) 
        {
            data[i] = temp[i];
        }

        // Free the temporary array
        delete[] temp;
    }
}
