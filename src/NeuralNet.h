#ifndef CPPNN_LIBRARY_H
#define CPPNN_LIBRARY_H

#include <vector>

#include "Perceptron.h"
#include "LayerDefinition.h"
#include "Layer.h"
#include "activations/ActivationFactory.h"
#include "exceptions/InvalidInputSize.h"

namespace PyreNet {
    class NeuralNet {
    public:
        // # of input size, and layer topology (vector of layer sizes, includes output & middle)
        NeuralNet(int, const std::vector<LayerDefinition>&);

        // Predict output
        std::vector<double> predict(const std::vector<double>&);

        // Mutate weightings in the neural net by an interval amount
        void mutate_uniform(double lowerBound, double upperBound);

        // Mutate weightings based on normal distribution
        void mutate_gaussian(double mean, double std);

        //size of public layers
        int getInputSize();

        int getOutputSize();

        friend std::ostream& operator<<(std::ostream& os, const NeuralNet& nn);

        friend std::istream& operator>>(std::istream& is, NeuralNet& nn);

    private:
        int inputSize;
        std::vector<Layer> layers;
    };
}
#endif