#include "NeuralNetwork.h"

NeuralNetwork::NeuralNetwork(std::string filePath)
{
    std::ifstream file (filePath, std::ios::in);

    if (file.fail())
    {
        std::cout << "File could not be opened!" << std::endl;
        exit(1);
    }

    std::string line;

    getline(file, line);

    int numInputs = std::stoi(line.substr(line.find(':') + 1)); //extract the number of inputs to be passed into the network

    this->inputLayer = new InputLayer(numInputs); //create a new instance of the input layer

    getline(file, line);

    this->numHiddenLayers = std::stoi(line.substr(line.find(':') + 1)); //extract the number of hidden layers to be passed into the network

    this->hiddenLayers = new HiddenLayer*[this->numHiddenLayers]; //create a new array of hidden layers that matches the number of hidden layers

    int numPrevNeurons = numInputs;

    for (int i = 0; i < this->numHiddenLayers; i++) //get all the data for the hidden layers
    {
        getline(file, line);
        line.erase(0,line.find(':') + 1);

        int numNeurons = std::stoi(line.substr(0, line.find(':')));

        std::string activation = line.substr(line.find(':') + 1);

        HiddenNeuron** neurons = new HiddenNeuron*[numNeurons];
        
        int numWeights = numPrevNeurons;

        for (int j = 0; j < numNeurons; j++)
        {
            double* weights = new double[numWeights];
            getline(file, line);
            std::stringstream ss(line);

            int count = 0;
            while (ss >> weights[count])
            {
                count++;
            }
            neurons[j] = new HiddenNeuron(numWeights, weights);
            
        }
        this->hiddenLayers[i] = new HiddenLayer(numNeurons, neurons, activation);

        numPrevNeurons = numNeurons;
    }

    getline(file, line); //read a line, it is not processed since it contanis no information we need

    int numWeights = numPrevNeurons;
    double* weights = new double[numWeights];

    getline(file, line); //line contains the weights for the output layer
    std::stringstream ss(line);

    int count = 0;
    while (ss >> weights[count])
    {
        count++;
    }

    this->outputLayer = new OutputLayer(numWeights, weights);
}

NeuralNetwork::~NeuralNetwork()
{
    delete this->inputLayer;
    for (int i = 0; i < this->numHiddenLayers; ++i)
    {
        delete this->hiddenLayers[i];
    }
    delete [] this->hiddenLayers;
    delete this->outputLayer;
}

double NeuralNetwork::forward(double* input)
{
    this->inputLayer->setInputs(input);

    this->hiddenLayers[0]->forward(this->inputLayer);

    for (int i = 1; i < this->numHiddenLayers; i++)
    {
        this->hiddenLayers[i]->forward(this->hiddenLayers[i - 1]);
    }

    this->outputLayer->forward(this->hiddenLayers[this->numHiddenLayers - 1]);

    return this->outputLayer->getOutputValue();
}

void NeuralNetwork::printNetwork()
{
    this->inputLayer->printLayer();
    for (int i = 0; i < this->numHiddenLayers; ++i)
    {
        this->hiddenLayers[i]->printLayer();
    }
    this->outputLayer->printLayer();
}

void NeuralNetwork::clearNetwork()
{
    this->inputLayer->clearLayer();
    for (int i = 0; i < this->numHiddenLayers; ++i)
    {
        this->hiddenLayers[i]->clearLayer();
    }
    this->outputLayer->clearLayer();
}
