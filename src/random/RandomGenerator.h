//
// Created by Poppro on 12/3/2019.
//

#ifndef PYRENET_RANDOMGENERATOR_H
#define PYRENET_RANDOMGENERATOR_H

#include <random>
#include <chrono>

class RandomGenerator {
public:
    static RandomGenerator* getInstance();
    double generate(double, double);
private:
    static RandomGenerator* randomGenerator;
    RandomGenerator();
    RandomGenerator(RandomGenerator const&);
    RandomGenerator& operator=(RandomGenerator const&);
    std::default_random_engine* generator;
};


#endif //PYRENET_RANDOMGENERATOR_H
