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
    nn.mutate_uniform(0, 0.1);
    std::vector<double> input{0,1,2,3,4};
    std::cout << "Stress test complete" << std::endl;
}

void multiThreadedStressTest() {
    int threadCount = 10;
    std::vector<PyreNet::LayerDefinition> layerDefs;
    layerDefs.emplace_back(50, PyreNet::LayerDefinition::activationType::relu);
    layerDefs.emplace_back(50, PyreNet::LayerDefinition::activationType::relu);
    layerDefs.emplace_back(50, PyreNet::LayerDefinition::activationType::relu);
    layerDefs.emplace_back(2, PyreNet::LayerDefinition::activationType::relu);
    std::vector<PyreNet::NeuralNet> nns;
    for (int i = 0; i < threadCount; ++i) {
        nns.emplace_back(5, layerDefs);
        nns.back().mutate_uniform(0, 1);
    }
    std::vector<double> input{0,1,2,3,4};

    std::vector<std::thread> pool;
    for (int i = 0; i < threadCount; ++i)
        pool.emplace_back(&PyreNet::NeuralNet::predict, nns[i], input);

    for (std::thread& t : pool)
        t.join();

    std::cout << "Multi threaded stress test complete" << std::endl;
}

void serializeTest() {
    std::vector<PyreNet::LayerDefinition> layerDefs;
    layerDefs.emplace_back(50, PyreNet::LayerDefinition::activationType::relu);
    layerDefs.emplace_back(50, PyreNet::LayerDefinition::activationType::relu);
    layerDefs.emplace_back(50, PyreNet::LayerDefinition::activationType::relu);
    layerDefs.emplace_back(2, PyreNet::LayerDefinition::activationType::relu);
    PyreNet::NeuralNet nn(5, layerDefs);
    nn.mutate_uniform(0,2);
    std::vector<double> input{0,1,2,3,4};
    double output = nn.predict(input)[0];

    std::stringstream ss;
    ss << nn;

    nn.mutate_uniform(2,2);
    if (std::abs(nn.predict(input)[0] - output) <= 1)
        exit(EXIT_FAILURE);

    ss >> nn;
    if (std::abs(nn.predict(input)[0] - output) > 1)
        exit(EXIT_FAILURE);

    std::cout << "Serialize test complete" << std::endl;
}

int main() {
    stressTest();
    multiThreadedStressTest();
    serializeTest();
    return 0;
}
