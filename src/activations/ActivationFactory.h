//
// Created by Poppro on 12/2/2019.
//

#ifndef CPPNN_ACTIVATIONFACTORY_H
#define CPPNN_ACTIVATIONFACTORY_H


#include "../LayerDefinition.h"
#include "Activation.h"
#include "Sigmoid.h"
#include <unordered_map>

class ActivationFactory {
public:
    static ActivationFactory* getInstance();
    Activation* getActivation(LayerDefinition::activationType);
private:
    static ActivationFactory* activationFactory;
    ActivationFactory() = default;
    ActivationFactory(ActivationFactory const&);
    ActivationFactory& operator=(ActivationFactory const&);
    std::unordered_map<LayerDefinition::activationType, Activation*> activationCache;
    Activation* generateActivation(LayerDefinition::activationType);
};


#endif //CPPNN_ACTIVATIONFACTORY_H
