//
// Created by Poppro on 12/3/2019.
//

#ifndef PYRENET_RANDOMGENERATOR_H
#define PYRENET_RANDOMGENERATOR_H

#include <random>
#include <chrono>
#include <mutex>

namespace PyreNet {
    class RandomGenerator {
    public:
        static RandomGenerator *getInstance();

        double generate(double, double);

    private:
        static RandomGenerator *randomGenerator;

        static std::mutex mutex;

        RandomGenerator();

        RandomGenerator(RandomGenerator const &);

        RandomGenerator &operator=(RandomGenerator const &);

        std::default_random_engine *generator;
    };
}


#endif //PYRENET_RANDOMGENERATOR_H
