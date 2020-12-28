//
// Created by Poppro on 12/27/2020.
//

#include "LayerThreadPool.h"

namespace PyreNet {
    LayerThreadPool *LayerThreadPool::instance = nullptr;

    PyreNet::LayerThreadPool *PyreNet::LayerThreadPool::getInstance() {
        if (!instance)
            instance = new LayerThreadPool;
        return instance;
    }

    void PyreNet::LayerThreadPool::addJob(const PyreNet::LayerThreadPool::LayerQueueJob &job) {
        std::unique_lock<std::mutex> lg(queueMutex);
        layerQueue.push(job);
        newJobCv.notify_one();
    }

    std::condition_variable *PyreNet::LayerThreadPool::jobCv() {
        return &jobDoneCv;
    }

    std::mutex *PyreNet::LayerThreadPool::jobMutex() {
        return &trackMutex;
    }

    [[noreturn]] void PyreNet::LayerThreadPool::threadJob() {
        LayerThreadPool* tpi = getInstance();
        std::unique_lock<std::mutex> lg(tpi->queueMutex);
        while (true) {
            if (!tpi->layerQueue.empty()) {
                LayerQueueJob job = tpi->layerQueue.front();
                tpi->layerQueue.pop();
                lg.unlock();
                job.p.calculate(job.input, job.activation);
                std::unique_lock<std::mutex> lgTrack(tpi->trackMutex);
                job.track--;
                if (job.track == 0) {
                    lgTrack.unlock();
                    tpi->jobDoneCv.notify_all();
                } else {
                    lgTrack.unlock();
                }
                lg.lock();
            } else {
                tpi->newJobCv.wait(lg);
            }
        }
    }

    PyreNet::LayerThreadPool::LayerThreadPool() {
        instance = this;
        for (int i = 0; i < 16; ++i) {
            pool.emplace_back(threadJob);
        }
    }
}