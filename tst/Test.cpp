//
// Created by Poppro on 12/3/2019.
//

#include <iostream>
#include "../src/PyreNet.h"

void stressTest() {
    std::vector<PyreNet::LayerDefinition> layerDefs;
    layerDefs.emplace_back(50, PyreNet::LayerDefinition::activationType::relu);
    layerDefs.emplace_back(50, PyreNet::LayerDefinition::activationType::relu);
    layerDefs.emplace_back(50, PyreNet::LayerDefinition::activationType::relu);
    layerDefs.emplace_back(2, PyreNet::LayerDefinition::activationType::relu);
    PyreNet::NeuralNet nn(5, layerDefs);
    nn.mutate(0, 0.1);
    std::vector<double> input{0,1,2,3,4};
    std::cout << "Stress test complete" << std::endl;
}

void serializeTest() {
    std::vector<PyreNet::LayerDefinition> layerDefs;
    layerDefs.emplace_back(50, PyreNet::LayerDefinition::activationType::relu);
    layerDefs.emplace_back(50, PyreNet::LayerDefinition::activationType::relu);
    layerDefs.emplace_back(50, PyreNet::LayerDefinition::activationType::relu);
    layerDefs.emplace_back(2, PyreNet::LayerDefinition::activationType::relu);
    PyreNet::NeuralNet nn(5, layerDefs);
    nn.mutate(0,2);
    std::vector<double> input{0,1,2,3,4};
    double output = nn.predict(input)[0];

    std::stringstream ss;
    ss << nn;

    nn.mutate(2,2);
    if (std::abs(nn.predict(input)[0] - output) <= 1)
        exit(EXIT_FAILURE);

    ss >> nn;
    if (std::abs(nn.predict(input)[0] - output) > 1)
        exit(EXIT_FAILURE);

    std::cout << "Serialize test complete" << std::endl;
}

int main() {
    stressTest();
    serializeTest();
    return 0;
}