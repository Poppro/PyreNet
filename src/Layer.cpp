//
// Created by Poppro on 12/2/2019.
//

#include "Layer.h"
#include <thread>

namespace PyreNet {
// Constructor

    Layer::Layer(int size, int prevSize, Activation *activation) {
        this->nodes.reserve(size);
        for (int i = 0; i < size; i++) {
            this->nodes.emplace_back(prevSize);
        }
        this->activation = activation;
    }

// Main Layer Logic

    void threadJob(const std::vector<double> &input, Perceptron *p, Activation *activation) {
        p->calculate(input, activation);
    }

    std::vector<double> Layer::calculate(const std::vector<double> &input) {
        std::vector<std::thread> threadPool;
        threadPool.reserve(nodes.size());
        for (Perceptron &p : this->nodes) {
            // run perceptron calculation on thread
            threadPool.emplace_back(threadJob, input, &p, this->activation);
        }
        for (std::thread &t : threadPool) {
            t.join();
        }
        std::vector<double> ans;
        ans.reserve(this->nodes.size());
        for (Perceptron &p : this->nodes) {
            ans.push_back(p.getValue());
        }
        return ans;
    }

// Mutators

    void Layer::mutate(double lower, double upper) {
        for (Perceptron &p : this->nodes) {
            p.mutate(lower, upper);
        }
    }

// Getters

    int Layer::size() {
        return this->nodes.size();
    }
}