//
// Created by Poppro on 12/3/2019.
//

#ifndef PYRENET_TANH_H
#define PYRENET_TANH_H

#include "Activation.h"

class Tanh : public Activation {
    const double activate(double) override;
};


#endif //PYRENET_TANH_H
