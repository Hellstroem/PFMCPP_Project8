#include "Highway.h"

#include <cassert>

void Highway::changeSpeed(int newSpeed)
{
    speedLimit = newSpeed;
    for( auto* vehicle : vehicles )
    {
        vehicle->setSpeed(speedLimit);
    }
}

void Highway::addVehicleInternal(Vehicle* v)
{
    if(auto* veh = dynamic_cast<Car*>(v))
    {
        veh->closeWindows();
    } else if (auto* veh = dynamic_cast<Motorcycle*>(v))
    {
        veh->lanesplitAndRace(96);
    } else if (auto* veh = dynamic_cast<SemiTruck*>(v))
    {
        veh->setSpeed(66);
    }
    
}

void Highway::removeVehicleInternal(Vehicle* v)
{
    if(auto* veh = dynamic_cast<Car*>(v))
    {
        veh->tryToEvade();
    } else if (auto* veh = dynamic_cast<Motorcycle*>(v))
    {
        veh->tryToEvade();
    }else if (auto* veh = dynamic_cast<SemiTruck*>(v))
    {
        veh->pullOver();  
    }
}

void Highway::addVehicle(Vehicle* v)
{
    vehicles.push_back(v);
    addVehicleInternal(v);
}
void Highway::removeVehicle(Vehicle* v)
{
    vehicles.erase(std::remove(vehicles.begin(), 
                               vehicles.end(), 
                               v), 
                   vehicles.end());
    removeVehicleInternal(v);
}