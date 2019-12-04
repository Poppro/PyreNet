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
        this->weights.resize(inputSize);
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
        this->cachedValue = activation->activate(weightedSum);
    }

    void Perceptron::mutate(double lower, double upper) {
        RandomGenerator *randomGenerator = RandomGenerator::getInstance();
        for (double &weight : this->weights) {
            weight += randomGenerator->generate(lower, upper);
        }
    }

    // Getters

    double Perceptron::getValue() {
        return this->cachedValue;
    }
}