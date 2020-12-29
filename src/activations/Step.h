//
// Created by Poppro on 12/3/2019.
//

#ifndef PYRENET_STEP_H
#define PYRENET_STEP_H

#include "Activation.h"

namespace PyreNet {
    class Step : public Activation {
        const double activate(double) override;
        const LayerDefinition::activationType type() override;
    };
}


#endif //PYRENET_STEP_H
