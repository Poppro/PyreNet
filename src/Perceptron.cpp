//
// Created by hunter harloff on 2019-12-01.
//

#include "Perceptron.h"

#include "random/RandomGenerator.h"
#include "exceptions/InvalidInputSize.h"

namespace PyreNet {
    // Constructor

    Perceptron::Perceptron(int inputSize) {
        this->inputSize = inputSize;
        this->weights.resize(inputSize + 1);
    };

    // Mutators

    void Perceptron::calculate(const std::vector<double> &input, Activation *activation) {
        if (input.size() != this->inputSize) {
            throw InvalidInputSize();
        }
        double weightedSum = 0;
        for (int i = 0; i < this->inputSize; i++) {
            weightedSum += input[i] * this->weights[i];
        }
        weightedSum += 1 * this->weights.back(); // bias term
        this->cachedValue = activation->activate(weightedSum);
    }

    void Perceptron::mutate_uniform(double lower, double upper) {
        RandomGenerator *randomGenerator = RandomGenerator::getInstance();
        for (double &weight : this->weights) {
            weight += randomGenerator->generate_uniform(lower, upper);
        }
    }

    void Perceptron::mutate_gaussian(double mean, double std) {
        RandomGenerator *randomGenerator = RandomGenerator::getInstance();
        for (double &weight : this->weights) {
            weight += randomGenerator->generate_gaussian(mean, std);
        }
    }

    // Getters

    double Perceptron::getValue() const {
        return this->cachedValue;
    }

    // Serialize

    std::ostream &operator<<(std::ostream &os, const Perceptron &p) {
        for (double w : p.weights)
            os << w << " ";
        return os;
    }

    std::istream& operator>>(std::istream& is, Perceptron &p) {
        for (double& w : p.weights) {
            is >> w;
        }
        return is;
    }
}