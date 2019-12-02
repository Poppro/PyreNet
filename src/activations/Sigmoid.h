//
// Created by hunter harloff on 2019-12-01.
//

#ifndef CPPNN_SIGMOID_H
#define CPPNN_SIGMOID_H

#include "../Activation.h"

class Sigmoid : Activation {
public:
    double activate(double) override;
};


#endif //CPPNN_SIGMOID_H
