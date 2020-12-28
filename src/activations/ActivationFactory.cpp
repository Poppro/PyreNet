//
// Created by Poppro on 12/2/2019.
//

#include "ActivationFactory.h"
#include "Sigmoid.h"
#include "Relu.h"
#include "Linear.h"
#include "Step.h"
#include "Tanh.h"

namespace PyreNet {
    ActivationFactory *ActivationFactory::activationFactory = nullptr;

    ActivationFactory *ActivationFactory::getInstance() {
        if (!activationFactory)
            activationFactory = new ActivationFactory();
        return activationFactory;
    }

    Activation *ActivationFactory::getActivation(LayerDefinition::activationType activation) {
        if (this->activationCache.find(activation) == this->activationCache.end()) { // activation function not in cache
            this->activationCache[activation] = generateActivation(activation);
        }
        return this->activationCache[activation];
    }

    Activation *
    ActivationFactory::generateActivation(LayerDefinition::activationType activation) { // generate dynamic class
        switch (activation) {
            case LayerDefinition::step: {
                return new Step();
            }
            case LayerDefinition::linear: {
                return new Linear();
            }
            case LayerDefinition::tanh: {
                return new Tanh();
            }
            case LayerDefinition::sigmoid: {
                return new Sigmoid();
            }
            case LayerDefinition::relu: {
                return new Relu();
            }
            default: {
                throw std::exception();
            }
        }
    }
}