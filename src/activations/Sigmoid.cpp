//
// Created by hunter harloff on 2019-12-01.
//

#include "Sigmoid.h"
#include <math.h>

double Sigmoid::activate(double input) {
    return 1.0 / (1.0 + exp(-input));
}
