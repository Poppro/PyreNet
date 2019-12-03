//
// Created by hunter harloff on 2019-12-01.
//

#ifndef CPPNN_PERCEPTRON_H
#define CPPNN_PERCEPTRON_H

#include <vector>
#include "activations/Activation.h"

class Perceptron {
public:
    Perceptron(int);
    void calculate(const std::vector<double>&, Activation*);
    double getValue();
    void mutate(double, double);
private:
    std::vector<double> weights;
    double cachedValue;
    int inputSize;
};


#endif //CPPNN_PERCEPTRON_H
