#include "HiddenLayer.h"
#include "HiddenNeuron.h"
HiddenLayer::HiddenLayer(int numNeurons, HiddenNeuron** neurons, std::string activation)
{
    this->numNeurons = numNeurons;
    this->activation = activation;

    this->neurons = new HiddenNeuron*[numNeurons];

    for (int i = 0; i < numNeurons; ++i)
    {
        this->neurons[i] = neurons[i];
    }
}

HiddenLayer::~HiddenLayer()
{
    delete [] this->neurons;
}

HiddenNeuron** HiddenLayer::getNeurons()
{
    return this->neurons;
}

void HiddenLayer::setNeurons(HiddenNeuron** neurons)
{
    if (this->neurons != nullptr)
    {
        delete [] this->neurons;
        this->neurons = nullptr;
    }

    this->neurons = new HiddenNeuron*[this->numNeurons];
    for (int i = 0; i < this->numNeurons; ++i)
    {
        this->neurons[i] = neurons[i];
    }
}

int HiddenLayer::getNumNeurons()
{
    return this->numNeurons;
}

void HiddenLayer::setNumNeurons(int numNeurons)
{
    this->numNeurons = numNeurons;
}

void HiddenLayer::forward(HiddenLayer* prevLayer)
{
    for (int i = 0; i < this->numNeurons; ++i)
    {
        this->neurons[i]->forward(prevLayer);
        
        if (this->activation == "relu") this->neurons[i]->activateReLU();
        if (this->activation == "sigmoid") this->neurons[i]->activateSigmoid();
    }
}

void HiddenLayer::forward(InputLayer* prevLayer)
{
    for (int i = 0; i < this->numNeurons; ++i)
    {
        this->neurons[i]->forward(prevLayer);
        
        if (this->activation == "relu") this->neurons[i]->activateReLU();
        if (this->activation == "sigmoid") this->neurons[i]->activateSigmoid();
    }
}

void HiddenLayer::printLayer()
{
    std::cout << "h:" << this->numNeurons << ":" << this->activation << std::endl;
}

void HiddenLayer::clearLayer()
{
    if (this->neurons != nullptr)
    {
        for (int i = 0; i < this->numNeurons; ++i)
        {
            this->neurons[i]->setValue(0);
        }
    }
}
