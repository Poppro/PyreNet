//
// Created by Poppro on 12/2/2019.
//

#ifndef CPPNN_LAYERDEFINITION_H
#define CPPNN_LAYERDEFINITION_H


class LayerDefinition {
public:
    enum activationType {
        sigmoid
    };
    // Constructor to be supplied layer size, desired activation function
    LayerDefinition(int, activationType);
private:
    activationType activation;
    int size;
    friend class NeuralNet;
};

#endif //CPPNN_LAYERDEFINITION_H