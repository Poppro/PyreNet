//
// Created by hunter harloff on 2019-12-01.
//

#include <random>
#include <chrono>
#include "Perceptron.h"
#include "exceptions/InvalidInputSize.cpp"

// Constructor

Perceptron::Perceptron(int inputSize)
    : inputSize(inputSize) {};

// Mutators

void Perceptron::calculate(const std::vector<double> &input, Activation* activation) {
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
    typedef std::chrono::high_resolution_clock myclock;
    auto t = myclock::now();
    std::default_random_engine generator;
    generator.seed(t.time_since_epoch().count());
    std::uniform_real_distribution<double> dist(lower, upper);
    for (double &weight : this->weights) {
        weight += dist(generator);
    }
}

// Getters

double Perceptron::getValue() {
    return this->cachedValue;
}
