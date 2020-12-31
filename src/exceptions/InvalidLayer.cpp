//
// Created by Hunter Harloff on 12/29/20.
//

#include "InvalidLayer.h"

#include <string>

namespace PyreNet {
    const char* InvalidLayer::what() const noexcept {
        return "Invalid layer selection passed to network.";
    }
}
