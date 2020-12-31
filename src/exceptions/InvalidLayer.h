//
// Created by Hunter Harloff on 12/29/20.
//

#ifndef PYRENET_INVALIDLAYER_H
#define PYRENET_INVALIDLAYER_H

#include <exception>

namespace PyreNet {
    class InvalidLayer : public std::exception {
    public:
        const char *what() const noexcept override;
    };
}


#endif //PYRENET_INVALIDLAYER_H
