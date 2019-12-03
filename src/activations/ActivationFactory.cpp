//
// Created by Poppro on 12/2/2019.
//

#include "ActivationFactory.h"

ActivationFactory* ActivationFactory::activationFactory = nullptr;

ActivationFactory* ActivationFactory::getInstance() {
    if (!activationFactory)
        activationFactory = new ActivationFactory();
    return activationFactory;
}

Activation* ActivationFactory::getActivation(LayerDefinition::activationType activation) {
    if (this->activationCache.find(activation) == this->activationCache.end()) { // activation function not in cache
        this->activationCache[activation] = generateActivation(activation);
    }
    return this->activationCache[activation];
}

Activation* ActivationFactory::generateActivation(LayerDefinition::activationType activation) { // generate dynamic class
    switch (activation) {
        case LayerDefinition::activationType::sigmoid : {
            return new Sigmoid();
        }
        default: {
            throw std::exception();
        }
    }
}
