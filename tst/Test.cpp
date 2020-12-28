//
// Created by Poppro on 12/3/2019.
//

#include <iostream>
#include "../src/PyreNet.h"

int main() {
    std::vector<PyreNet::LayerDefinition> layerDefs;
    layerDefs.emplace_back(50, PyreNet::LayerDefinition::activationType::relu);
    layerDefs.emplace_back(50, PyreNet::LayerDefinition::activationType::relu);
    layerDefs.emplace_back(50, PyreNet::LayerDefinition::activationType::relu);
    layerDefs.emplace_back(2, PyreNet::LayerDefinition::activationType::relu);
    PyreNet::NeuralNet nn(5, layerDefs);
    nn.mutate(0, 1);
    std::vector<double> input{0,1,2,3,4};

    for (int i = 0; i < 100; ++i) {
        for (double x : nn.predict(input))
            std::cout << x << std::endl;
    }

    return 0;
}
