#pragma once

#include <vector>
#include <algorithm>
#include "Vehicle.h"
#include "Car.h"
#include "Motorcycle.h"
#include "SemiTruck.h"


struct HighwayPatrol;

struct Highway
{
    Highway() {};
    virtual ~Highway() = default;
    Highway(const Highway&) = default;
    Highway& operator=(const Highway&) = default;

    void changeSpeed(int newSpeed);
    void addVehicle(Vehicle* v);
    void removeVehicle(Vehicle* v);
private:
    void addVehicleInternal(Vehicle* v);
    void removeVehicleInternal(Vehicle* v);
    int speedLimit = 65;
    std::vector<Vehicle*> vehicles;
    friend HighwayPatrol;
};