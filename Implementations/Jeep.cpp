#include <iostream>
#include "../Headers/Jeep.h"
#include <ctime>

using namespace std;

Jeep::Jeep()
{
    setCarType("Jeep");
    hasFourWheelDrive = rand() % 2;
    hasOffRoadTires = rand() % 2;
    hasRoofRack = rand() % 2;

    if (interiorCleaningRequired)
        washTime += 14;
    if (hasFourWheelDrive)
        washTime += 8;
    if (hasOffRoadTires)
        washTime += 15;
    if (hasRoofRack)
        washTime += 4;
}

Jeep::~Jeep() {}

int Jeep::getArrivalTime() const { return arrivalTime; }

int Jeep::getWashTime() const { return washTime; }

void Jeep::setCarType(string type) { carType = type; }

string Jeep::getCarType() const { return carType; }

string Jeep::getLicensePlate() const { return licensePlate; }

string Jeep::getTypeOfWash() const { return typeOfWash; }

int Jeep::getQueuePosition() const { return queuePosition; }

void Jeep::display() const
{
    Vehicle::display();
    cout << " | Has Four Wheel Drive?: " << (hasFourWheelDrive ? "True" : "False")
         << " | Has Offroad Tires?: " << (hasOffRoadTires ? "True" : "False")
         << " | Has Roof Rack?: " << (hasRoofRack ? "True" : "False") << endl;
}
