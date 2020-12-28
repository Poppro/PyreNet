//
// Created by hunter harloff on 2019-12-01.
//

#ifndef CPPNN_PERCEPTRON_H
#define CPPNN_PERCEPTRON_H

#include <vector>
#include <sstream>

#include "activations/Activation.h"

namespace PyreNet {
    class Perceptron {
    public:
        Perceptron(int);

        void calculate(const std::vector<double> &, Activation *);

        double getValue();

        void mutate(double, double);

        friend std::ostream& operator<<(std::ostream& os, const Perceptron &p);

        friend std::istream& operator>>(std::istream& is, Perceptron &p);

    private:
        std::vector<double> weights;
        double cachedValue;
        int inputSize;
    };
}


#endif //CPPNN_PERCEPTRON_H
