/*
    The main is used to test the successful compilation and
    operation of the different classes used in this program.
*/

#include "NeuralNetwork.h"

using namespace std;

int main()
{
    //the size for the array of each type of calculation
    int num_mean = 4;
    int num_sin = 5;
    int num_squared = 5;

    //create dynmaic arrays of respective neural network objects
    NeuralNetwork** means = new NeuralNetwork*[num_mean];
    NeuralNetwork** sin_x = new NeuralNetwork*[num_sin];
    NeuralNetwork** x_squared = new NeuralNetwork*[num_squared];

    //instantiate each neural network object with the corresponding text file
    for (int i = 0; i < 5; i++)
    {
        means[i] = new NeuralNetwork("mean.txt");
        sin_x[i] = new NeuralNetwork("sin(x).txt");
        x_squared[i] = new NeuralNetwork("x_squared.txt");
    }

    //enter the input to be passed through the neural network
    double** mean_inputs = new double*[num_mean];
    mean_inputs[0] = new double[5] {5.0, 10.0, 15.0, 20.0, 25.0};
    mean_inputs[1] = new double[5] {0.0, 10.0, 20.0, 30.0, 40.0};
    mean_inputs[2] = new double[5] {-1.0, -2.0, -3.0, -4.0, -5.0};
    mean_inputs[3] = new double[5] {50.0, -2.0, -32.0, 60.0, -10.0};

    double** sin_x_inputs = new double*[num_sin];
    sin_x_inputs[0] = new double[1] {0.0};
    sin_x_inputs[1] = new double[1] {1.0};
    sin_x_inputs[2] = new double[1] {-1.0};
    sin_x_inputs[3] = new double[1] {5.0};
    sin_x_inputs[4] = new double[1] {1.5};

    double** x_squared_inputs = new double*[num_squared];
    x_squared_inputs[0] = new double[1] {2.0};
    x_squared_inputs[1] = new double[1] {4.0};
    x_squared_inputs[2] = new double[1] {8.0};
    x_squared_inputs[3] = new double[1] {-4.0};
    x_squared_inputs[4] = new double[1] {-10.0};
    
    //display the input and forward the inputs through the neural network
    cout << "This network approximates the mean of the 5 input values:" << endl << endl;
    
    for (int i = 0; i < num_mean; i++)
    {
        cout << "Input: [";
        for (int j = 0; j < 5; j++)
        {
            if (j == 4)
            {
                cout << fixed << showpoint << setprecision(2);
                cout << mean_inputs[i][j] << "]" << endl;
            }
            else
            {
                cout << fixed << showpoint << setprecision(2);
                cout << mean_inputs[i][j] << " ";
            }
        }
        cout << fixed << showpoint << setprecision(4);
        cout << "Output: " << means[i]->forward(mean_inputs[i]) << endl;
        means[i]->printNetwork(); //display the networks information
        cout << endl;
    }
    cout << endl;

    cout << "This network approximates x squared in the range [-100, 100]:" << endl << endl;
    for (int i = 0; i < num_squared; i++)
    {
        cout << "Input: [";
        cout << fixed << showpoint << setprecision(2);
        cout << x_squared_inputs[i][0] << "]" << endl;
        cout << "Output: " << fixed << showpoint << setprecision(4) << x_squared[i]->forward(x_squared_inputs[i]) << endl;
        x_squared[i]->printNetwork(); //display the networks information
        cout << endl;
    }
    cout << endl;

    cout << "This network approximates the function sin(x) where x is in radians in the range [-10, 10]:" << endl << endl;
    for (int i = 0; i < num_sin; i++)
    {
        cout << "Input: [";
        cout << fixed << showpoint << setprecision(2);
        cout << sin_x_inputs[i][0] << "]" << endl;
        cout << "Output: " << fixed << showpoint << setprecision(4) <<  sin_x[i]->forward(sin_x_inputs[i]) << endl;
        sin_x[i]->printNetwork(); //display the networks information
        cout << endl;
    }
    cout << endl;

    //clear the respective networks and free the memory used by the program
    for (int i = 0; i < num_mean; i++)
    {
        means[i]->clearNetwork();
        delete means[i];
    }
    delete [] means;

    for (int i = 0; i < num_squared; i++)
    {
        x_squared[i]->clearNetwork();
        delete x_squared[i];
    }
    delete [] x_squared;

    for (int i = 0; i < num_sin; i++)
    {
        sin_x[i]->clearNetwork();
        delete sin_x[i];
    }
    delete [] sin_x;

    for (int i = 0; i < 5; i++)
    {
        if (i == 4)
        {
            delete x_squared_inputs[i];
            delete sin_x_inputs[i];
        }
        else
        {
            delete x_squared_inputs[i];
            delete sin_x_inputs[i];
            delete mean_inputs[i];
        }
    }
    delete [] mean_inputs;
    delete [] sin_x_inputs;
    delete [] x_squared_inputs;

    return 0;
}