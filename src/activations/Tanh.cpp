//
// Created by Poppro on 12/3/2019.
//

#include <cmath>
#include "Tanh.h"

const double Tanh::activate(double input) {
    return (2/(1 + exp(-2*input)) - 1);
}
