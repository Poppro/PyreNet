//
// Created by Poppro on 12/4/2019.
//

#ifndef PYRENET_INVALIDINPUTSIZE_H
#define PYRENET_INVALIDINPUTSIZE_H

#include <exception>

namespace PyreNet {
    class InvalidInputSize : public std::exception {
        const char *what() const noexcept override;
    };
}

#endif //PYRENET_INVALIDINPUTSIZE_H
