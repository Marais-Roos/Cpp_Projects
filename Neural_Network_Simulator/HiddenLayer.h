#ifndef HIDDEN_LAYER_H
#define HIDDEN_LAYER_H

#include <string>
#include "InputLayer.h"
//#include "HiddenNeuron.h"
class HiddenNeuron;

class HiddenLayer 
{
private:
    int numNeurons;
    HiddenNeuron** neurons;
    std::string activation;
public:
    HiddenLayer(int numNeurons, HiddenNeuron** neurons, std::string activation);
    ~HiddenLayer();
    HiddenNeuron** getNeurons();
    void setNeurons(HiddenNeuron** neurons);
    int getNumNeurons();
    void setNumNeurons(int numNeurons);
    void forward(HiddenLayer* prevLayer);
    void forward(InputLayer* prevLayer);
    void printLayer();
    void clearLayer();
};

#endif