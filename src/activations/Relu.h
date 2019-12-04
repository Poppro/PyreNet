//
// Created by Poppro on 12/3/2019.
//

#ifndef PYRENET_RELU_H
#define PYRENET_RELU_H

#include "Activation.h"

namespace PyreNet {
    class Relu : public Activation {
    public:
        const double activate(double) override;
    };
}


#endif //PYRENET_RELU_H
