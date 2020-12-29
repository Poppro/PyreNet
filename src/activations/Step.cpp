//
// Created by Poppro on 12/3/2019.
//

#include "Step.h"

namespace PyreNet {
    const double Step::activate(double input) {
        return (input >= 0) ? 1 : 0;
    }

    const LayerDefinition::activationType Step::type() {
        return LayerDefinition::activationType::step;
    }
}
