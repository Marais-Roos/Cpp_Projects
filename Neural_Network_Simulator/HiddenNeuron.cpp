#include "HiddenNeuron.h"
#include "HiddenLayer.h"
HiddenNeuron::HiddenNeuron(int numWeights, double* weights)
{
    this->numWeights = numWeights;
    this->weights = new double[numWeights];
    for (int i = 0; i < numWeights; i++)
    {
        this->weights[i] = weights[i];
    }

    this->value = 0.0;
}

HiddenNeuron::~HiddenNeuron()
{
    delete [] weights;
    weights = nullptr;
}

double HiddenNeuron::getValue()
{
    return this->value;
}

void HiddenNeuron::setValue(double value)
{
    this->value = value;
}

void HiddenNeuron::forward(HiddenLayer* prevLayer)
{
    for (int i = 0; i < this->numWeights; i++)
    {
        this->value += prevLayer->getNeurons()[i]->getValue() * this->weights[i];
    }
}  

void HiddenNeuron::forward(InputLayer* prevLayer)
{
    for (int i = 0; i < this->numWeights; i++)
    {
        this->value += prevLayer->getInputs()[i] * this->weights[i];
    }
}

void HiddenNeuron::activateReLU()
{
    if (!(this->value > 0))
    {
        this->value = 0;
    }
}

void HiddenNeuron::activateSigmoid()
{
    this->value = 1 / (1 + exp(-1 * this->value));
}
