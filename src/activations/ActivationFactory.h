//
// Created by Poppro on 12/2/2019.
//

#ifndef CPPNN_ACTIVATIONFACTORY_H
#define CPPNN_ACTIVATIONFACTORY_H


#include "../LayerDefinition.h"

#include <unordered_map>
#include <mutex>

#include "Activation.h"

namespace PyreNet {
    class ActivationFactory {
    public:
        static ActivationFactory *getInstance();

        Activation *getActivation(LayerDefinition::activationType);

    private:
        ActivationFactory() = default;

        ActivationFactory(ActivationFactory const &);

        ActivationFactory &operator=(ActivationFactory const &);

    private:
        static ActivationFactory *activationFactory;
        static std::mutex instanceMutex;
        std::unordered_map<LayerDefinition::activationType, Activation *> activationCache;
        Activation *generateActivation(LayerDefinition::activationType);
    };
}


#endif //CPPNN_ACTIVATIONFACTORY_H
