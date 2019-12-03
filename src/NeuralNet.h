#ifndef CPPNN_LIBRARY_H
#define CPPNN_LIBRARY_H

#include <vector>

#include "Perceptron.h"
#include "LayerDefinition.h"
#include "Layer.h"
#include "activations/ActivationFactory.h"
#include "exceptions/InvalidInputSize.cpp"

class NeuralNet {
public:
    // # of input size, and layer topology (vector of layer sizes, includes output & middle)
    NeuralNet(int, const std::vector<LayerDefinition>&);
    // Predict output
    std::vector<double> predict(const std::vector<double>&);
    // Mutate weightings in the neural net by an interval amount
    void mutate(double, double);

    //size of public layers
    int getInputSize();
    int getOutputSize();
private:
    int inputSize;
    std::vector<Layer> layers;
};
#endif