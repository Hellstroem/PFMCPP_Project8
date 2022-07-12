#include "SemiTruck.h"

SemiTruck::SemiTruck(const std::string& n) : Vehicle(n) {}

void SemiTruck::pullOver()
{
    setSpeed(0);
    std::cout << name << ": hello officer, what seems to be the problem?" << std::endl;
}

void SemiTruck::setSpeed(int s)
{
    Vehicle::setSpeed(70);
    std::cout << name << ": getting up to speed" << std::endl;
}
