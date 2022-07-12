#pragma once
#include "Vehicle.h"

struct SemiTruck : public Vehicle
{
    SemiTruck(const std::string& name);
    virtual ~SemiTruck() = default;
    SemiTruck(const SemiTruck&) = default;
    SemiTruck& operator=(const SemiTruck&) = default;

    void pullOver();
    void setSpeed(int s);

};