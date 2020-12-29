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

    void NeuralNet::mutate_uniform(double lower, double upper, int layer) {
        if (layer == -1) {
            for (Layer &l : this->layers) {
                l.mutate_uniform(lower, upper);
            }
        } else {
            if (layer < 0 || layer > this->layers.size())
                throw InvalidLayer();
            this->layers[layer].mutate_uniform(lower, upper);
        }
    }

    void NeuralNet::mutate_gaussian(double mean, double std, int layer) {
        if (layer == -1) {
            for (Layer &l : this->layers) {
                l.mutate_gaussian(mean, std);
            }
        } else {
            if (layer < 0 || layer > this->layers.size())
                throw InvalidLayer();
            this->layers[layer].mutate_gaussian(mean, std);
        }
    }

    // Getters

    int NeuralNet::getInputSize() {
        return this->inputSize;
    }

    int NeuralNet::getOutputSize() {
        return this->layers.back().size();
    }

    // Serialize

    std::ostream &operator<<(std::ostream &os, const NeuralNet& nn) {
        for (const Layer& l : nn.layers)
            os << l << " ";
        return os;
    }

    std::istream& operator>>(std::istream& is, NeuralNet& nn) {
        for (Layer& l : nn.layers)
            is >> l;
        return is;
    }
}
