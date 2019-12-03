//
// Created by hunter harloff on 2019-12-01.
//

#ifndef CPPNN_ACTIVATION_H
#define CPPNN_ACTIVATION_H


class Activation {
public:
     // run activation function on weighted sum
     virtual const double activate(double) = 0;
};


#endif //CPPNN_ACTIVATION_H
