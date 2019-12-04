//
// Created by Poppro on 12/3/2019.
//

#ifndef PYRENET_LIENAR_H
#define PYRENET_LIENAR_H

#include "Activation.h"

namespace PyreNet {
    class Linear : public Activation {
        const double activate(double) override;
    };
};


#endif //PYRENET_LIENAR_H
