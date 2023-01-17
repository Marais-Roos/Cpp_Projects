#include "OutputLayer.h"

OutputLayer::OutputLayer(int numWeights, double* weights)
{
    this->numWeights = numWeights;
    this->weights = new double[numWeights];
    for (int i = 0; i < numWeights; i++)
    {
        this->weights[i] = weights[i];
    }
    this->outputValue = 0;
}

OutputLayer::~OutputLayer()
{
    delete [] this->weights;
}

double OutputLayer::getOutputValue()
{
    return this->outputValue;
}

void OutputLayer::setOutputValue(double outputValue)
{
    this->outputValue = outputValue;
}

void OutputLayer::forward(HiddenLayer* lastHiddenLayer)
{
    for (int i = 0; i < this->numWeights; i++)
    {
        //this->outputValue += (this->weights[i]) * (lastHiddenLayer->getNeurons()[i]->getValue());
    }
}

void OutputLayer::printLayer()
{
    std::cout << "o:1" << std::endl;
}

void OutputLayer::clearLayer()
{
    this->outputValue = 0;
}