#include "InputLayer.h"

InputLayer::InputLayer(int numInputs)
{
    this->numInputs = numInputs;
    this->inputs = nullptr;
}

InputLayer::~InputLayer()
{
    delete [] this->inputs;
    this->inputs = nullptr;
}

double* InputLayer::getInputs()
{
    return this->inputs;
}

int InputLayer::getNumInputs()
{
    return this->numInputs;
}

void InputLayer::setInputs(double* inputs)
{
    if (this->inputs != nullptr)
    {
        for (int i = 0; i < this->numInputs; ++i)
        {
            this->inputs[i] = 0.0;
        }
        delete [] this->inputs;
        delete this->inputs;
        this->inputs = nullptr;
    }

    this->inputs = new double[this->numInputs];

    for (int i = 0; i < this->numInputs; ++i)
    {
        this->inputs[i] = inputs[i];
    }
}

void InputLayer::setNumInputs(int numInputs)
{
    this->numInputs = numInputs;
}

void InputLayer::printLayer()
{
    std::cout << "i:" << this->numInputs << std::endl;
}

void InputLayer::clearLayer()
{
    if (this->inputs != nullptr)
    {
        for (int i = 0; i < this->numInputs; ++i)
        {
            this->inputs[i] = 0.0;
        }
    }
}
