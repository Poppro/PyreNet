//
// Created by Poppro on 12/2/2019.
//

#include "Layer.h"

#include <condition_variable>

#include "thread/LayerThreadPool.h"

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

    std::vector<double> Layer::calculate(const std::vector<double> &input) {
        LayerThreadPool* layerThreadPool = LayerThreadPool::getInstance();
        int track = this->nodes.size();
        for (Perceptron &p : this->nodes) {
            LayerThreadPool::LayerQueueJob job(input, p, this->activation, track);
            layerThreadPool->addJob(job);
        }
        layerThreadPool->waitForTasks(track);
        std::vector<double> ans;
        ans.reserve(this->nodes.size());
        for (const Perceptron &p : this->nodes) {
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