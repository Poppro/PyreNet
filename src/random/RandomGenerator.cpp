//
// Created by Poppro on 12/3/2019.
//

#include "RandomGenerator.h"
namespace PyreNet {
    RandomGenerator *RandomGenerator::randomGenerator = nullptr;
    std::mutex RandomGenerator::instanceMutex;

    RandomGenerator *RandomGenerator::getInstance() {
        std::unique_lock<std::mutex> lg(instanceMutex);
        if (randomGenerator == nullptr)
            randomGenerator = new RandomGenerator();
        return randomGenerator;
    }

    RandomGenerator::RandomGenerator() {
        typedef std::chrono::high_resolution_clock myclock;
        auto t = myclock::now();
        auto *gen = new std::default_random_engine(t.time_since_epoch().count());
        this->generator = gen;
    }

    double RandomGenerator::generate_uniform(double lower, double upper) {
        std::unique_lock<std::mutex> lg(instanceMutex);
        std::uniform_real_distribution<double> dist(lower, upper);
        return dist(*generator);
    }

    double RandomGenerator::generate_gaussian(double mean, double std) {
        std::unique_lock<std::mutex> lg(instanceMutex);
        std::normal_distribution<double> dist(mean, std);
        return dist(*generator);
    }
}