#include "NeuralNet.h"

namespace PyreNet {
    // Constructor

    NeuralNet::NeuralNet(int inputSize){
        this->inputSize = inputSize;
    }

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

    NeuralNet::NeuralNet(std::istream &is) {
        this->inputSize = 0;
        is >> *this;
    }

    // Predictor

    std::vector<double> NeuralNet::predict(const std::vector<double> &input) {
        if (this->layers.size() == 0 || this->inputSize == 0) throw InvalidNetworkSize();
        if (input.size() != this->inputSize) throw InvalidInputSize();
        std::vector<double> layerData(input);
        for (Layer &l : this->layers) {
            layerData = l.calculate(layerData);
        }
        return layerData;
    }

    // Insertor
    void NeuralNet::add(const LayerDefinition &newLayer){

        ActivationFactory* activationFactory = ActivationFactory::getInstance();

        this->layers.reserve(this->layers.size() + 1);
        int prevSize;
        if (this->layers.empty()) prevSize = this->inputSize;
        else prevSize = this->layers.back().size();

        Activation* activation = activationFactory->getActivation(newLayer.activation);
        this->layers.emplace_back(newLayer.size, prevSize, activation);
    }

    // Mutators

    void NeuralNet::mutate_uniform(const double lower, const double upper, int layer) {
        if (this->layers.size() < 3 || this->inputSize == 0) throw InvalidNetworkSize();
        if (layer == -1) {
            for (Layer &l : this->layers) {
                l.mutate_uniform(lower, upper);
            }
        } else {
            if (layer < 0 || layer >= this->layers.size())
                throw InvalidLayer();
            this->layers[layer].mutate_uniform(lower, upper);
        }
    }

    void NeuralNet::mutate_gaussian(const double mean, const double std, int layer) {
        if (this->layers.size() < 3 || this->inputSize == 0) throw InvalidNetworkSize();
        if (layer == -1) {
            for (Layer &l : this->layers) {
                l.mutate_gaussian(mean, std);
            }
        } else {
            if (layer < 0 || layer >= this->layers.size())
                throw InvalidLayer();
            this->layers[layer].mutate_gaussian(mean, std);
        }
    }

    // Getters

    const int NeuralNet::getInputSize() {
        if (this->layers.size() < 3 || this->inputSize == 0) throw InvalidNetworkSize();
        return this->inputSize;
    }

    const int NeuralNet::getOutputSize() {
        if (this->layers.size() < 3 || this->inputSize == 0) throw InvalidNetworkSize();
        return this->layers.back().size();
    }

    // Serialize

    // Write to file
    std::ostream &operator<<(std::ostream &os, const NeuralNet& nn) {
        os << nn.inputSize << " ";
        os << nn.layers.size() << " ";
        for (const Layer& l : nn.layers)
            os << l << " ";
        return os;
    }

    // Read from file
    std::istream& operator>>(std::istream& is, NeuralNet& nn) {
        is >> nn.inputSize;
        int layerSize;
        is >> layerSize;
        nn.layers.resize(layerSize, Layer(0, 0, nullptr));
        for (Layer& l : nn.layers)
            is >> l;
        return is;
    }
}
