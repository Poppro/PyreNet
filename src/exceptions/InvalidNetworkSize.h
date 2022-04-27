//
// Created by Samer Khatib on 4/26/22.
//

#ifndef PYRENET_INVALIDNETWORKSIZE_H
#define PYRENET_INVALIDNETWORKSIZE_H

#include <exception>

namespace PyreNet {
    class InvalidNetworkSize : public std::exception {
    public:
        const char *what() const noexcept override;
    };
}


#endif //PYRENET_INVALIDNETWORKSIZE_H
