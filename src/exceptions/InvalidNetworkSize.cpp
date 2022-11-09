//
// Created by Hunter Harloff on 12/29/20.
//

#include "InvalidNetworkSize.h"

#include <string>

namespace PyreNet {
    const char* InvalidNetworkSize::what() const noexcept {
        return "Invalid network size! Network either has 0 layers inserted or 0 inputs.";
    }
}
