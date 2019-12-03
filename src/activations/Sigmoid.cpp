//
// Created by hunter harloff on 2019-12-01.
//

#include <cmath>
#include "Sigmoid.h"

const double Sigmoid::activate(double input) {
    return 1.0 / (1.0 + std::exp(-input));
}
