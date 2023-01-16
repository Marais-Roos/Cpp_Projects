#ifndef HIDDEN_NEURON_H
#define HIDDEN_NEURON_H

#include "InputLayer.h"
#include "HiddenLayer.h"
//class HiddenLayer;

#include <math.h>

class HiddenNeuron 
{
private:
    double value;
    int numWeights;
    double* weights;
public:
    HiddenNeuron(int numWeights, double* weights);
    ~HiddenNeuron();
    double getValue();
    void setValue(double value);
    void forward(HiddenLayer* prevLayer);
    void forward(InputLayer* prevLayer);
    void activateReLU();
    void activateSigmoid();
};

#endif