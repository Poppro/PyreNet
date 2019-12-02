#ifndef CPPNN_LIBRARY_H
#define CPPNN_LIBRARY_H

#include <vector>
#include "Perceptron.h"

class NeuralNet {
public:
    // # of input, middle (vector of layer sizes), and output nodes
    NeuralNet(int, const std::vector<int>&, int);
    // Predict output
    std::vector<double> predict(const std::vector<double>&);
    // Mutate weightings in the neural net within an interval
    void mutate(double);

    //size of public layers
    int getInputSize();
    int getOutputSize();
private:
    std::vector<Perceptron> input;
    std::vector<std::vector<Perceptron>> middle;
    std::vector<Perceptron> output;
};
#endif