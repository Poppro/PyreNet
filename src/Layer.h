//
// Created by Poppro on 12/2/2019.
//

#ifndef CPPNN_LAYER_H
#define CPPNN_LAYER_H

#include <vector>
#include <thread>

#include "Perceptron.h"
#include "activations/Activation.h"

namespace PyreNet {
    class Layer {
    public:
        // Size of layer, size of previous layer (input to layer), activation function
        Layer(int, int, Activation *);

        std::vector<double> calculate(const std::vector<double> &);

        void mutate_uniform(double, double);

        void mutate_gaussian(double mean, double std);

        int size();

        friend std::ostream& operator<<(std::ostream& os, const Layer &l);

        friend std::istream& operator>>(std::istream& is, Layer &l);

    private:
        std::vector<Perceptron> nodes;
        Activation* activation;
    };
}


#endif //CPPNN_LAYER_H
