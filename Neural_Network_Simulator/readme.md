# Neural Network Simulator

This projects showcases my familiarity with C++ classes, objects and dynamic memory.

## Overview

In the field of Artificial Intelligence (AI), Neural Networks (NNs) are powerful tools facilitating the so-called "Fourth Industrial Revolution".

## What is a Neural Network?

For the purpose of this project, a NN is made up of layers of neurons. Connecting these neurons together forms a model of the human brain. Neurons are represented using circles in a graph-like structure. In this scenario, there is only one input layer, one output layer, and one or more hidden layers which are in between the input and output layer.

![visual demonstration of NN](https://www.tibco.com/sites/tibco/files/media_entity/2021-05/neutral-network-diagram.svg)

Values move from the input layer to the output layer i.e. from **left** to **right** through the network (this is the forward direction). Each neuron in a layer is connected to every neuron in the next layer via what is known as a *weight*. In order for a value to move forward in a network, it must be multiplied by the weight which attaches it to the next neuron in the network. After a value is aggregated in a neuron a non-linear activation function is applied. The output of a neural network is the value(s) that emerge from the output layer, after the input values have made their way through the entire network. In this assignment, there will only be a single neuron in the output layer, and thus there will only be a single output value from the NN.

## Why are Neural Networks so useful?

Neural networks are known as *univeral approximators*. Although a NN is essentially a bunch of numbers being multiplied together, the weights of these networks are able to be adjusted in order to model different functions both linear and non-linear. In practice large networks allow computers to be able to perform useful tasks, some of which are classifying images, recommending movies and interpreting speech.

This project is significantly simplified compared to real-life implementations. The program will be implementing a forward pass through a fully connected neural network.

**Note:** There are no biases in this program.

## UML Class Diagrams

### Input Layer

```
- numInputs: int
- inputs: double*
---
+ InputLayer(numInputs: int)
+ ~InputLayer()
+ getInputs(): double
+ getNumInputs(): int
+ setInputs(inputs: double*): void
+ setNumInputs(numInputs: int): void
+ printLayer(): void
+ clearLayer(): void
```

#### Member Variables

- ```numInputs``` represents the number of inputs to the first layer of the NN.
- ```inputs``` is a dynamic array ```double``` array. These values are the inputs to NN. 

#### Member Functions

- ```InputLayer(int numInputs)```
 - Constructor that accepts the ```numInputs``` as a parameter and sets the corresponding member variable.
- ```~InputLayer()```
 - Destructor that deallocates the ```inputs``` array
- ```getInputs()```
 - Returns the ```inputs``` array
- ```getNumInputs()```
 - Returns the number of the inputs of the NN
- ```setInputs(double* inputs)```
 - Sets the ```inputs``` member variable to the argument (without a deep copy).
 - If inputs are already set, the existing inputs should be deallocated first.
- ```setNumInputs(int numInputs)```
 - Sets the ```numInputs``` member variable to the value of the argument
- ```printLayer()```
 - Prints the string ```i:x``` where ```x``` is the ```numInputs``` of this layer.
- ```clearLayer()```
 - Sets each element of the ```inputs``` array to zero.
 - If the inputs array is NULL, then do nothing.