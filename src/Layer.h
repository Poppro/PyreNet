//
// Created by Poppro on 12/2/2019.
//

#ifndef CPPNN_LAYER_H
#define CPPNN_LAYER_H

#include <vector>

#include "Perceptron.h"
#include "activations/Activation.h"

class Layer {
public:
    // Size of layer, size of previous layer (input to layer), activation function
    Layer(int, int, Activation*);
    std::vector<double> calculate(const std::vector<double>&);
    void mutate(double, double);
    int size();
private:
    std::vector<Perceptron> nodes;
    Activation* activation;
};


#endif //CPPNN_LAYER_H
