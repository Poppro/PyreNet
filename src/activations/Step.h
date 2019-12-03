//
// Created by Poppro on 12/3/2019.
//

#ifndef PYRENET_STEP_H
#define PYRENET_STEP_H

#include "Activation.h"

class Step : public Activation {
    const double activate(double) override;
};


#endif //PYRENET_STEP_H
