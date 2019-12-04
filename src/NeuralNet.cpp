#include "NeuralNet.h"

namespace PyreNet {
    // Constructor
    NeuralNet::NeuralNet(int inputSize, const std::vector<LayerDefinition> &layers) {
        ActivationFactory* activationFactory = ActivationFactory::getInstance();
        this->inputSize = inputSize;
        this->layers.reserve(layers.size());
        int prevSize = inputSize;
        for (LayerDefinition layer : layers) {
            std::vector<Perceptron> tmp;
            tmp.reserve(layer.size);
            Activation* activation = activationFactory->getActivation(layer.activation);
            this->layers.emplace_back(layer.size, prevSize, activation);
            prevSize = layer.size;
        }
    }

    // Predictor

    std::vector<double> NeuralNet::predict(const std::vector<double> &input) {
        if (input.size() != this->inputSize) throw InvalidInputSize();
        std::vector<double> layerData(input);
        for (Layer &l : this->layers) {
            layerData = l.calculate(layerData);
        }
        return layerData;
    }

    // Mutators

    void NeuralNet::mutate(double lower, double upper) {
        for (Layer &l : this->layers) {
            l.mutate(lower, upper);
        }
    }

    // Getters

    int NeuralNet::getInputSize() {
        return this->inputSize;
    }

    int NeuralNet::getOutputSize() {
        return this->layers.back().size();
    }
}
