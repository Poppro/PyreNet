//
// Created by hunter harloff on 2019-12-01.
//

#include <random>
#include "Perceptron.h"
#include "../exceptions/InvalidInputSize.cpp"

// Constructor

Perceptron::Perceptron(int inputSize, Activation* af)
    : activationFunction(af), inputSize(inputSize) {};

// Mutators

void Perceptron::calculate(const std::vector<double> &input) {
    if (input.size() != this->inputSize) {
        throw InvalidInputSize();
    }
    double weightedSum = 0;
    for (int i = 0; i < this->inputSize; i++) {
        weightedSum += input[i] * this->weights[i];
    }
    this->cachedValue = this->activationFunction->activate(weightedSum);
}

void Perceptron::mutate(double interval) {
    std::default_random_engine generator;
    std::uniform_real_distribution<double> dist(-interval, interval);
    for (double &weight : this->weights) {
        weight += dist(generator);
    }
}

// Getters

double Perceptron::getValue() {
    return this->cachedValue;
}
