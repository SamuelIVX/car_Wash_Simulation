#include <iostream>
#include "../Headers/Vehicle.h"

using namespace std;

Vehicle::Vehicle(
    int arrivalTime,
    int washTime,
    string typeOfWash,
    string carType,
    string licensePlate,
    int queuePosition,
    bool interiorCleaningRequired,
    bool isVIP,
    float water,
    float soap)
{
    this->arrivalTime = arrivalTime;
    this->washTime = washTime;
    this->typeOfWash = typeOfWash;
    this->carType = carType;
    this->licensePlate = licensePlate;
    this->queuePosition = queuePosition;
    this->interiorCleaningRequired = interiorCleaningRequired;
    this->isVIP = isVIP;
    this->water = water;
    this->soap = soap;
}

Vehicle::~Vehicle()
{
    cout << "Vehicle Destructor Invoked.";
}

// int Vehicle::getArrivalTime() const
// {
//     return arrivalTime;
// }

// int Vehicle::getWashTime() const
// {
//     return washTime;
// }

// string Vehicle::getTypeOfWash() const
// {
//     return typeOfWash;
// }

float Vehicle::getWaterUsage() const { return water; }

float Vehicle::getSoapUsage() const { return soap; }

// string Vehicle::getLicensePlate() const
// {
//     return licensePlate;
// }

// int Vehicle::getQueuePosition() const
// {
//     return queuePosition;
// }

// string Vehicle::getCarType() const
// {
//     return carType;
// }

bool Vehicle::needsInteriorCleaning()
{
    return interiorCleaningRequired;
}

void Vehicle::display() const
{
    cout << "Arrival Time: " << arrivalTime << endl
         << "Car Type: " << carType << endl
         << "License Plate: " << licensePlate << endl
         << "Queue Position: " << queuePosition << endl
         << "Wash Time: " << washTime << endl
         << "Type of Wash: " << typeOfWash << endl
         << "Interior Cleaning Required?: " << interiorCleaningRequired << endl
         << "VIP?: " << isVIP << endl
         << "Water Usage: " << water << endl
         << "Soap Usage: " << soap << endl;
}

// int Vehicle::randomGenerator();

// void Vehicle::movePosition();