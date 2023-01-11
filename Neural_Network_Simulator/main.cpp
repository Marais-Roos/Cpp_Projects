/*
    The main is used to test the successful compilation and
    operation of the different classes used in this program.
*/

#include "InputLayer.h"

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

//*********************************************************

int main()
{
    inputLayerConstructor();
    inputLayerDestructor();
    inputLayerSetNumInputs();
    inputLayerSetAndGetNumInputs();
    inputLayerSetInputs();
    inputLayerSetAndGetInputs();
    inputLayerPrint();
    inputLayerClear();

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