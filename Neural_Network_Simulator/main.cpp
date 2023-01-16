/*
    The main is used to test the successful compilation and
    operation of the different classes used in this program.
*/

#include "InputLayer.h"
#include "HiddenNeuron.h"
#include "HiddenLayer.h"
#include "OutputLayer.h"

using namespace std;

//*********************************************************
//FUNCTION PROTOTYPES
//*********************************************************

void inputLayerConstructor();
void inputLayerDestructor();
void inputLayerSetNumInputs();
void inputLayerSetAndGetNumInputs();
void inputLayerSetInputs();
void inputLayerSetAndGetInputs();
void inputLayerPrint();
void inputLayerClear();

void hiddenNeuronConstructor();
void hiddenNeuronDestructor();
void hiddenNeuronSetValue();
void hiddenNeuronSetAndGetValue();
void hiddenNeuronForwardHiddenLayer();
void hiddenNeuronForwardInputLayer();
void hiddenNeuronActivateReLU();
void hiddenNeuronActivateSigmoid();

void hiddenLayerConstructor();
void hiddenLayerDestructor();
void hiddenLayerSetNeurons();
void hiddenLayerSetAndGetNeurons();
void hiddenLayerSetNumNeurons();
void hiddenLayerSetAndGetNumNeurons();
void hiddenLayerForwardHiddenLayer();
void hiddenLayerForwardInputLayer();
void hiddenLayerPrint();
void hiddenLayerClear();

void outputLayerConstructor();
void outputLayerDestructor();
void outputLayerSetOutputValue();
void outputLayerSetAndGetOutputValue();
void outputLayerForwardLastHiddenLayer();
void outputLayerPrint();
void outputLayerClear();
//*********************************************************

int main()
{
    //Test Input Layer
    cout << "Testing Input Layer" << endl;
    inputLayerConstructor();
    inputLayerDestructor();
    inputLayerSetNumInputs();
    inputLayerSetAndGetNumInputs();
    inputLayerSetInputs();
    inputLayerSetAndGetInputs();
    inputLayerPrint();
    inputLayerClear();

    //Test Hidden Neuron
    cout << "Testing Hidden Neuron" << endl;
    hiddenNeuronConstructor();
    hiddenNeuronDestructor();
    hiddenNeuronSetValue();
    hiddenNeuronSetAndGetValue();
    hiddenNeuronForwardHiddenLayer();
    hiddenNeuronForwardInputLayer();
    hiddenNeuronActivateReLU();
    hiddenNeuronActivateSigmoid();

    //Test Hidden Layer
    cout << "Testing Hidden Layer" << endl;
    hiddenLayerConstructor();
    hiddenLayerDestructor();
    hiddenLayerSetNeurons();
    hiddenLayerSetAndGetNeurons();
    hiddenLayerSetNumNeurons();
    hiddenLayerSetAndGetNumNeurons();
    hiddenLayerForwardHiddenLayer();
    hiddenLayerForwardInputLayer();
    hiddenLayerPrint();
    hiddenLayerClear();
    
    //Test Output Layer
    cout << "Testing Output Layer" << endl;
    outputLayerConstructor();
    outputLayerDestructor();
    outputLayerSetOutputValue();
    outputLayerSetAndGetOutputValue();
    outputLayerForwardLastHiddenLayer();
    outputLayerPrint();
    outputLayerClear();

    return 0;
}

//*********************************************************
//FUNCTION DEFINITIONS
//*********************************************************

void inputLayerConstructor()
{
    cout << "InputLayer Constructor..." << endl;

    int numInputs = 5;
    InputLayer *i = new InputLayer(numInputs);

    cout << "Success!" << endl;
}

void inputLayerDestructor()
{
    cout << "InputLayer Destructor..." << endl;

    int numInputs = 5;
    InputLayer *i = new InputLayer(numInputs);

    delete i;

    cout << "Success!" << endl;
}

void inputLayerSetNumInputs()
{
    cout << "InputLayer set numInputs..." << endl;

    int numInputs = 5;
    InputLayer *i = new InputLayer(numInputs);

    int newInputs = 3;
    i->setNumInputs(newInputs);

    delete i;

    cout << "Success!" << endl;
}

void inputLayerSetAndGetNumInputs()
{
    cout << "InputLayer Set And Get numInputs..." << endl;

    int numInputs = 5;
    InputLayer *i = new InputLayer(numInputs);

    int newInputs = 3;
    i->setNumInputs(newInputs);

    cout << i->getNumInputs() << endl;

    delete i;

    cout << "Success!" << endl;
}

void inputLayerSetInputs()
{
    cout << "InputLayer setInputs function..." << endl;

    int numInputs = 5;
    InputLayer *i = new InputLayer(numInputs);

    double* vals = new double[numInputs];
    vals[0] = 3.14;
    vals[1] = 4.56;
    vals[2] = 5.89;
    vals[3] = 9.234;
    vals[4] = 0.34;

    i->setInputs(vals);

    delete i;

    delete [] vals;
    vals = nullptr;

    cout << "Success!" << endl;
}

void inputLayerSetAndGetInputs()
{
    cout << "InputLayer set and get Inputs function..." << endl;

    int numInputs = 5;
    InputLayer *i = new InputLayer(numInputs);

    double* vals = new double[numInputs];
    vals[0] = 3.14;
    vals[1] = 4.56;
    vals[2] = 5.89;
    vals[3] = 9.234;
    vals[4] = 0.34;

    i->setInputs(vals);

    for (int j = 0; j < numInputs; j++)
    {
        cout << i->getInputs()[j] << endl;
    }

    delete i;

    delete [] vals;
    vals = nullptr;

    cout << "Success!" << endl;
}

void inputLayerPrint()
{
    cout << "InputLayer printLayer..." << endl;

    int numInputs = 5;
    InputLayer *i = new InputLayer(numInputs);

    i->printLayer();

    delete i;

    cout << "Success!" << endl;
}

void inputLayerClear()
{
    cout << "InputLayer clearLayer..." << endl;

    int numInputs = 5;
    InputLayer *i = new InputLayer(numInputs);

    i->clearLayer();

    delete i;

    cout << "Success!" << endl;
}

//*********************************************************

void hiddenNeuronConstructor()
{
    cout << "HiddenNeuron Constructor..." << endl;

    int numWeights = 3;
    double* weights = new double[numWeights];
    weights[0] = 0.023;
    weights[1] = 1.65;
    weights[2] = 0.992;


    HiddenNeuron *hN = new HiddenNeuron(numWeights, weights);

    delete [] weights;

    cout << "Success!" << endl;
}

void hiddenNeuronDestructor()
{
    cout << "HiddenNeuron Destructor..." << endl;

    int numWeights = 3;
    double* weights = new double[numWeights];
    weights[0] = 0.023;
    weights[1] = 1.65;
    weights[2] = 0.992;

    HiddenNeuron *hN = new HiddenNeuron(numWeights, weights);

    delete hN;
    delete [] weights;

    cout << "Success!" << endl;
}

void hiddenNeuronSetValue()
{
    cout << "HiddenNeuron SetValue()..." << endl;

    int numWeights = 3;
    double* weights = new double[numWeights];
    weights[0] = 0.023;
    weights[1] = 1.65;
    weights[2] = 0.992;

    HiddenNeuron *hN = new HiddenNeuron(numWeights, weights);

    hN->setValue(5);

    delete hN;
    delete [] weights;

    cout << "Success!" << endl;
}

void hiddenNeuronSetAndGetValue()
{
    cout << "HiddenNeuron SetValue() & getValue()..." << endl;

    int numWeights = 3;
    double* weights = new double[numWeights];
    weights[0] = 0.023;
    weights[1] = 1.65;
    weights[2] = 0.992;

    HiddenNeuron *hN = new HiddenNeuron(numWeights, weights);

    hN->setValue(5);
    
    double val = hN->getValue();

    cout << "Value: " << val << endl;

    delete hN;
    delete [] weights;

    cout << "Success!" << endl;
}

void hiddenNeuronForwardHiddenLayer()
{
    cout << "HiddenNeuron forward(HiddenLayer* prevLayer)..." << endl;

    int numWeights = 3;
    double* weights = new double[numWeights];
    weights[0] = 0;
    weights[1] = 0;
    weights[2] = 0;

    int numNeurons = 3;
    HiddenNeuron** neurons = new HiddenNeuron*[numNeurons];

    neurons[0] = new HiddenNeuron(numWeights, weights);
    neurons[1] = new HiddenNeuron(numWeights, weights);
    neurons[2] = new HiddenNeuron(numWeights, weights);
    neurons[0]->setValue(0.2);
    neurons[1]->setValue(0.43);
    neurons[2]->setValue(0.5);

    string a = "relu";

    HiddenLayer* hL = new HiddenLayer(numNeurons, neurons, a);

    int nW = 3;
    double* w = new double[nW];
    w[0] = 0.023;
    w[1] = 1.65;
    w[2] = 0.992;

    HiddenNeuron *hN = new HiddenNeuron(nW, w);

    hN->forward(hL);
    
    double val = hN->getValue();

    cout << "Value: " << val << endl;

    delete hN;
    delete [] w;
    for (int i = 0; i < numNeurons; i++)
    {
        delete neurons[i];
    }
    delete [] neurons;
    delete [] weights;

    cout << "Success!" << endl;
}

void hiddenNeuronForwardInputLayer()
{
    cout << "HiddenNeuron forward(InputLayer* prevLayer)..." << endl;

    int numInputs = 3;
    double* inputs = new double[3];
    inputs[0] = 0.2;
    inputs[1] = 0.43;
    inputs[2] = 0.5;

    InputLayer* iL = new InputLayer(numInputs);
    iL->setInputs(inputs);

    int nW = 3;
    double* w = new double[nW];
    w[0] = 0.023;
    w[1] = 1.65;
    w[2] = 0.992;

    HiddenNeuron *hN = new HiddenNeuron(nW, w);

    hN->forward(iL);
    
    double val = hN->getValue();

    cout << "Value: " << val << endl;

    delete iL;
    delete [] inputs;
    delete hN;
    delete [] w;

    cout << "Success!" << endl;
}

void hiddenNeuronActivateReLU()
{
    cout << "HiddenNeuron activateReLU()..." << endl;

    int numWeights = 3;
    double* weights = new double[numWeights];
    weights[0] = 0.023;
    weights[1] = 1.65;
    weights[2] = 0.992;

    HiddenNeuron *hN = new HiddenNeuron(numWeights, weights);
    hN->setValue(1.2102);
    hN->activateReLU();
    double val = hN->getValue();

    cout << "Value: " << val << endl;

    cout << "Success!" << endl;
}

void hiddenNeuronActivateSigmoid()
{
    cout << "HiddenNeuron activateSigmoid()..." << endl;

    int numWeights = 3;
    double* weights = new double[numWeights];
    weights[0] = 0.023;
    weights[1] = 1.65;
    weights[2] = 0.992;

    HiddenNeuron *hN = new HiddenNeuron(numWeights, weights);
    hN->setValue(1.2102);
    hN->activateSigmoid();
    double val = hN->getValue();

    cout << "Value: " << val << endl;

    cout << "Success!" << endl;
}

//*********************************************************

void hiddenLayerConstructor()
{
    cout << "Testing Hidden Layer Constructor" << endl;
    int numWeights = 3;
    double* weights = new double[numWeights];
    weights[0] = 0.023;
    weights[1] = 1.65;
    weights[2] = 0.992;

    int numNeurons = 3;
    HiddenNeuron** neurons = new HiddenNeuron*[numNeurons];
    neurons[0] = new HiddenNeuron(numWeights, weights);
    neurons[1] = new HiddenNeuron(numWeights, weights);
    neurons[2] = new HiddenNeuron(numWeights, weights);

    HiddenLayer* hL = new HiddenLayer(numNeurons, neurons, "relu");

    for (int i = 0; i < numNeurons; i++) 
        delete neurons[i];
    delete [] neurons;
    delete [] weights;

    cout << "Success!" << endl;
}

void hiddenLayerDestructor()
{
    cout << "Testing Hidden Layer Destructor" << endl;

    int numWeights = 3;
    double* weights = new double[numWeights];
    weights[0] = 0.023;
    weights[1] = 1.65;
    weights[2] = 0.992;

    int numNeurons = 3;
    HiddenNeuron** neurons = new HiddenNeuron*[numNeurons];
    neurons[0] = new HiddenNeuron(numWeights, weights);
    neurons[1] = new HiddenNeuron(numWeights, weights);
    neurons[2] = new HiddenNeuron(numWeights, weights);

    HiddenLayer* hL = new HiddenLayer(numNeurons, neurons, "relu");

    delete hL;

    for (int i = 0; i < numNeurons; i++) 
        delete neurons[i];
    delete [] neurons;
    delete [] weights;

    cout << "Success!" << endl;
}

void hiddenLayerSetNeurons()
{
    cout << "Testing Hidden Layer setNeurons" << endl;

    int numWeights = 3;
    double* weights = new double[numWeights];
    weights[0] = 0.023;
    weights[1] = 1.65;
    weights[2] = 0.992;

    int numNeurons = 3;
    HiddenNeuron** neurons = new HiddenNeuron*[numNeurons];
    neurons[0] = new HiddenNeuron(numWeights, weights);
    neurons[1] = new HiddenNeuron(numWeights, weights);
    neurons[2] = new HiddenNeuron(numWeights, weights);

    HiddenLayer* hL = new HiddenLayer(numNeurons, neurons, "relu");

    double* newWeights = new double[numWeights];
    newWeights[0] = 2.3;
    newWeights[1] = 16.5;
    newWeights[2] = 9.92;

    HiddenNeuron** newNeurons = new HiddenNeuron*[numNeurons];
    newNeurons[0] = new HiddenNeuron(numWeights, newWeights);
    newNeurons[1] = new HiddenNeuron(numWeights, newWeights);
    newNeurons[2] = new HiddenNeuron(numWeights, newWeights);

    hL->setNeurons(newNeurons);

    delete hL;

    for (int i = 0; i < numNeurons; i++) 
        delete neurons[i];
    delete [] neurons;
    delete [] weights;
    for (int i = 0; i < numNeurons; i++) 
        delete newNeurons[i];
    delete[] newNeurons;
    delete[] newWeights;

    cout << "Success!" << endl;
}

void hiddenLayerSetAndGetNeurons()
{
    cout << "Testing Hidden Layer setNeurons() & getNeurons()" << endl;

    int numWeights = 3;
    double* weights = new double[numWeights];
    weights[0] = 0.023;
    weights[1] = 1.65;
    weights[2] = 0.992;

    int numNeurons = 3;
    HiddenNeuron** neurons = new HiddenNeuron*[numNeurons];
    neurons[0] = new HiddenNeuron(numWeights, weights);
    neurons[1] = new HiddenNeuron(numWeights, weights);
    neurons[2] = new HiddenNeuron(numWeights, weights);

    HiddenLayer* hL = new HiddenLayer(numNeurons, neurons, "relu");

    double* newWeights = new double[numWeights];
    newWeights[0] = 2.3;
    newWeights[1] = 16.5;
    newWeights[2] = 9.92;

    HiddenNeuron** newNeurons = new HiddenNeuron*[numNeurons];
    newNeurons[0] = new HiddenNeuron(numWeights, newWeights);
    newNeurons[1] = new HiddenNeuron(numWeights, newWeights);
    newNeurons[2] = new HiddenNeuron(numWeights, newWeights);

    newNeurons[0]->setValue(1);
    newNeurons[1]->setValue(2);
    newNeurons[2]->setValue(3);

    hL->setNeurons(newNeurons);

    HiddenNeuron** resultNeurons = hL->getNeurons();
    for (int i = 0; i < numNeurons; ++i)
    {
        cout << "neuron[" << i << "]: " << newNeurons[i]->getValue();
    }

    delete hL;

    resultNeurons = nullptr;

    for (int i = 0; i < numNeurons; i++) 
        delete neurons[i];
    delete [] neurons;
    delete [] weights;
    for (int i = 0; i < numNeurons; i++) 
        delete newNeurons[i];
    delete[] newNeurons;
    delete[] newWeights;

    cout << "Success!" << endl;
}

void hiddenLayerSetNumNeurons()
{
    cout << "Testing Hidden Layer setNumNeurons()" << endl;

    int numWeights = 3;
    double* weights = new double[numWeights];
    weights[0] = 0.023;
    weights[1] = 1.65;
    weights[2] = 0.992;

    int numNeurons = 3;
    HiddenNeuron** neurons = new HiddenNeuron*[numNeurons];
    neurons[0] = new HiddenNeuron(numWeights, weights);
    neurons[1] = new HiddenNeuron(numWeights, weights);
    neurons[2] = new HiddenNeuron(numWeights, weights);

    HiddenLayer* hL = new HiddenLayer(numNeurons, neurons, "relu");

    int newNumNeurons = 5;

    hL->setNumNeurons(newNumNeurons);

    delete hL;

    for (int i = 0; i < numNeurons; i++) 
        delete neurons[i];
    delete [] neurons;
    delete [] weights;
    
    cout << "Success!" << endl;
}

void hiddenLayerSetAndGetNumNeurons()
{
    cout << "Testing Hidden Layer setNumNeurons() & getNumNeurons()" << endl;

    int numWeights = 3;
    double* weights = new double[numWeights];
    weights[0] = 0.023;
    weights[1] = 1.65;
    weights[2] = 0.992;

    int numNeurons = 3;
    HiddenNeuron** neurons = new HiddenNeuron*[numNeurons];
    neurons[0] = new HiddenNeuron(numWeights, weights);
    neurons[1] = new HiddenNeuron(numWeights, weights);
    neurons[2] = new HiddenNeuron(numWeights, weights);

    HiddenLayer* hL = new HiddenLayer(numNeurons, neurons, "relu");

    int newNumNeurons = 5;

    hL->setNumNeurons(newNumNeurons);
    cout << "Number of Neurons: " << hL->getNumNeurons() << endl;

    delete hL;

    for (int i = 0; i < numNeurons; i++) 
        delete neurons[i];
    delete [] neurons;
    delete [] weights;
    
    cout << "Success!" << endl;
}

void hiddenLayerForwardHiddenLayer()
{
    cout << "Testing Hidden Layer forward(HiddenLayer* prevLayer)" << endl;

    int numWeights = 3;
    double* weights = new double[numWeights];
    weights[0] = 0.023;
    weights[1] = 1.65;
    weights[2] = 0.992;

    int numNeurons = 3;
    HiddenNeuron** neurons = new HiddenNeuron*[numNeurons];
    neurons[0] = new HiddenNeuron(numWeights, weights);
    neurons[1] = new HiddenNeuron(numWeights, weights);
    neurons[2] = new HiddenNeuron(numWeights, weights);

    HiddenLayer* hL = new HiddenLayer(numNeurons, neurons, "relu");

    HiddenLayer* newHL = new HiddenLayer(numNeurons, neurons, "sigmoid");

    hL->forward(newHL);

    delete newHL;
    delete hL;

    for (int i = 0; i < numNeurons; i++) 
        delete neurons[i];
    delete [] neurons;
    delete [] weights;
    
    cout << "Success!" << endl;
}

void hiddenLayerForwardInputLayer()
{
    cout << "Testing Hidden Layer forward(InputLayer* prevLayer)" << endl;

    int numWeights = 3;
    double* weights = new double[numWeights];
    weights[0] = 0.023;
    weights[1] = 1.65;
    weights[2] = 0.992;

    int numNeurons = 3;
    HiddenNeuron** neurons = new HiddenNeuron*[numNeurons];
    neurons[0] = new HiddenNeuron(numWeights, weights);
    neurons[1] = new HiddenNeuron(numWeights, weights);
    neurons[2] = new HiddenNeuron(numWeights, weights);

    HiddenLayer* hL = new HiddenLayer(numNeurons, neurons, "relu");

    InputLayer* iL = new InputLayer(numWeights);
    iL->setInputs(weights);

    hL->forward(iL);

    delete hL;

    for (int i = 0; i < numNeurons; i++) 
        delete neurons[i];
    delete [] neurons;
    delete [] weights;
    
    cout << "Success!" << endl;
}

void hiddenLayerPrint()
{
    cout << "Testing Hidden Layer printLayer()" << endl;

    int numWeights = 3;
    double* weights = new double[numWeights];
    weights[0] = 0.023;
    weights[1] = 1.65;
    weights[2] = 0.992;

    int numNeurons = 3;
    HiddenNeuron** neurons = new HiddenNeuron*[numNeurons];
    neurons[0] = new HiddenNeuron(numWeights, weights);
    neurons[1] = new HiddenNeuron(numWeights, weights);
    neurons[2] = new HiddenNeuron(numWeights, weights);

    HiddenLayer* hL = new HiddenLayer(numNeurons, neurons, "relu");

    hL->printLayer();

    delete hL;

    for (int i = 0; i < numNeurons; i++) 
        delete neurons[i];
    delete [] neurons;
    delete [] weights;
    
    cout << "Success!" << endl;
}

void hiddenLayerClear()
{
    cout << "Testing Hidden Layer clearLayer()" << endl;

    int numWeights = 3;
    double* weights = new double[numWeights];
    weights[0] = 0.023;
    weights[1] = 1.65;
    weights[2] = 0.992;

    int numNeurons = 3;
    HiddenNeuron** neurons = new HiddenNeuron*[numNeurons];
    neurons[0] = new HiddenNeuron(numWeights, weights);
    neurons[1] = new HiddenNeuron(numWeights, weights);
    neurons[2] = new HiddenNeuron(numWeights, weights);

    HiddenLayer* hL = new HiddenLayer(numNeurons, neurons, "relu");

    hL->clearLayer();

    delete hL;

    for (int i = 0; i < numNeurons; i++) 
        delete neurons[i];
    delete [] neurons;
    delete [] weights;
    
    cout << "Success!" << endl;
}

//*********************************************************

void outputLayerConstructor()
{
    cout << "Testing Output Layer constructor" << endl;
    int numWeights = 3;
    double* weights = new double[numWeights];

    OutputLayer* oL = new OutputLayer(numWeights, weights);

    delete [] weights;
    cout << "Success!" << endl;
}

void outputLayerDestructor()
{
    cout << "Testing Output Layer destructor" << endl;

    int numWeights = 3;
    double* weights = new double[numWeights];

    OutputLayer* oL = new OutputLayer(numWeights, weights);

    delete oL;

    delete [] weights;
    cout << "Success!" << endl;
}

void outputLayerSetOutputValue()
{
    cout << "Testing Output Layer setOutputValue()" << endl;

    int numWeights = 3;
    double* weights = new double[numWeights];

    OutputLayer* oL = new OutputLayer(numWeights, weights);

    oL->setOutputValue(3.14);

    delete oL;

    delete [] weights;
    cout << "Success!" << endl;
}

void outputLayerSetAndGetOutputValue()
{
    cout << "Testing Output Layer setOutputValue() & getOutputValue()" << endl;

    int numWeights = 3;
    double* weights = new double[numWeights];

    OutputLayer* oL = new OutputLayer(numWeights, weights);

    oL->setOutputValue(3.14);

    cout << "Output: " << oL->getOutputValue() << endl;

    delete oL;

    delete [] weights;

    cout << "Success!" << endl;
}

void outputLayerForwardLastHiddenLayer()
{
    cout << "Testing Output Layer forward(HiddenLayer* lastHiddenLayer)" << endl;

    int numWeights = 3;
    double* weights = new double[numWeights];
    weights[0] = 0.023;
    weights[1] = 1.65;
    weights[2] = 0.992;

    int numNeurons = 3;
    HiddenNeuron** neurons = new HiddenNeuron*[numNeurons];
    neurons[0] = new HiddenNeuron(numWeights, weights);
    neurons[1] = new HiddenNeuron(numWeights, weights);
    neurons[2] = new HiddenNeuron(numWeights, weights);

    HiddenLayer* hL = new HiddenLayer(numNeurons, neurons, "relu");

    OutputLayer* oL = new OutputLayer(numWeights, weights);

    oL->forward(hL);
    cout << "output: " << oL->getOutputValue() << endl;

    delete hL;
    delete oL;
    for (int i = 0; i < numNeurons; i++) 
        delete neurons[i];
    delete [] neurons;
    delete [] weights;

    cout << "Success!" << endl;
}

void outputLayerPrint()
{
    cout << "Testing Output Layer printLayer()" << endl;

    int numWeights = 3;
    double* weights = new double[numWeights];

    OutputLayer* oL = new OutputLayer(numWeights, weights);

    oL->printLayer();

    delete oL;

    delete [] weights;

    cout << "Success!" << endl;
}

void outputLayerClear()
{
    cout << "Testing Output Layer clearLayer()" << endl;

    int numWeights = 3;
    double* weights = new double[numWeights];

    OutputLayer* oL = new OutputLayer(numWeights, weights);

    oL->clearLayer();

    delete oL;

    delete [] weights;

    cout << "Success!" << endl;
}

//*********************************************************