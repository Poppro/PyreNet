//
// Created by Poppro on 12/3/2019.
//

#include "RandomGenerator.h"
namespace PyreNet {
    RandomGenerator *RandomGenerator::randomGenerator = nullptr;
    std::mutex RandomGenerator::mutex;

    RandomGenerator *RandomGenerator::getInstance() {
        std::unique_lock<std::mutex> lg(mutex);
        if (randomGenerator == nullptr)
            randomGenerator = new RandomGenerator();
        return randomGenerator;
    }

    RandomGenerator::RandomGenerator() {
        typedef std::chrono::high_resolution_clock myclock;
        auto t = myclock::now();
        auto *gen = new std::default_random_engine;
        gen->seed(t.time_since_epoch().count());
        this->generator = gen;
    }

    double RandomGenerator::generate(double lower, double upper) {
        std::unique_lock<std::mutex> lg(mutex);
        std::uniform_real_distribution<double> dist(lower, upper);
        return dist(*generator);
    }
}