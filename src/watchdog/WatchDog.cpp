//
// Created by kevin on 3/23/2022.
//

#include "WatchDog.h"
#include <cmath>
#include <utility>

WatchDog::WatchDog(std::vector<IRedline*> conds, unsigned int cap):
    conditions(std::move(conds)),
    storageCap(cap)
{}




std::vector<std::pair<ECSRedLineResponse, IRedline*>> WatchDog::stepRedlines(SensorData& data){
    std::vector<std::pair<ECSRedLineResponse, IRedline*>> result = {};
    if (this->storageCap > this->sensData.size()) {
        this->sensData.push_back(data);
    }

    for(IRedline* curTest : this->conditions){
        ECSRedLineResponse response = curTest->testCondition(data);

        if(response != ECSRedLineResponse::SAFE){
            result.emplace_back(response, curTest);
        }
    }

    return result;
}

void WatchDog::updateRedlines(std::vector<IRedline *> newRedlines) {
    this->conditions = std::move(newRedlines);
    this->sensData.clear();
}

