//
// Created by hunter harloff on 2019-12-01.
//

#ifndef CPPNN_ACTIVATION_H
#define CPPNN_ACTIVATION_H

#include "../LayerDefinition.h"

namespace PyreNet {
    class Activation {
    public:
        virtual const double activate(double) = 0;
        virtual const LayerDefinition::activationType type() = 0;
    };
}


#endif //CPPNN_ACTIVATION_H
