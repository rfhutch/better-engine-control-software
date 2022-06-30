//
// Created by Cameron on 5/13/21.
//

#ifndef ENGINECONTROLSYSTEM_ECSPIVALVE_H
#define ENGINECONTROLSYSTEM_ECSPIVALVE_H

#include "IECSValve.h"
#include "wiringPi.h"
#include <stdexcept>

class ECSPiValve : public IECSValve {
public:
    ECSPiValve(ECSValveState initialState, int pinNumber);

    void setValveState(ECSValveState newState) override;
    ECSValveState getValveState() override;
protected:
    int pinNumber;
    ECSValveState defaultState;
};


#endif //ENGINECONTROLSYSTEM_ECSPIVALVE_H
