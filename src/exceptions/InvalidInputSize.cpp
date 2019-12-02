//
// Created by hunter harloff on 2019-12-01.
//
#include <exception>

class InvalidInputSize : public std::exception {
    virtual const char* what() const noexcept {
        return "Invalid size supplied to Perceptron";
    }
};