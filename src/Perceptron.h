//
// Created by hunter harloff on 2019-12-01.
//

#ifndef CPPNN_PERCEPTRON_H
#define CPPNN_PERCEPTRON_H

#include <vector>
#include "Activation.h"

class Perceptron {
public:
    Perceptron(int, Activation*);
    void calculate(const std::vector<double>&);
    double getValue();
    void mutate(double);
private:
    std::vector<double> weights;
    Activation* activationFunction;
    double cachedValue;
    int inputSize;
};


#endif //CPPNN_PERCEPTRON_H
