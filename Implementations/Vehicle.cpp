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

float Vehicle::getWaterUsage() const { return water; }

float Vehicle::getSoapUsage() const { return soap; }

bool Vehicle::needsInteriorCleaning() { return interiorCleaningRequired; }

void Vehicle::display() const
{
    cout << " | Arrival Time: " << arrivalTime
         << " | Car Type: " << carType
         << " | License Plate: " << licensePlate
         << " | Queue Position: " << queuePosition << endl
         << " | Wash Time: " << washTime
         << " | Type of Wash: " << typeOfWash
         << " | Interior Cleaning Required?: " << interiorCleaningRequired
         << " | VIP?: " << isVIP << endl
         << " | Water Usage: " << water
         << " | Soap Usage: " << soap;
}

// int Vehicle::randomGenerator();

// void Vehicle::movePosition();