#include <iostream>
#include "../Headers/Chevrolet.h"
#include <ctime>

using namespace std;

Chevrolet::Chevrolet(int arrivalTime) : Vehicle(arrivalTime)
{
    int randomValue = rand() % 3;
    string vehicleTypes[] = {"Truck", "SUV", "Car"};

    setCarType("Chevrolet");
    vehicleType = vehicleTypes[randomValue];
    bool hasActiveAero = rand() % 2;
    bool hasParkingSensors = rand() % 2;

    unordered_map<string, int> vehicleTypeTimes{
        {"Truck", 10},
        {"SUV", 8},
        {"Car", 7}};

    washTime += vehicleTypeTimes[vehicleType];
    if (interiorCleaningRequired)
        washTime += 9;
    if (hasActiveAero)
        washTime += 8;
    if (hasParkingSensors)
        washTime += 3;
}

Chevrolet::~Chevrolet() {}

int Chevrolet::getArrivalTime() const { return arrivalTime; }

int Chevrolet::getWashTime() const { return washTime; }

void Chevrolet::setCarType(string type) { carType = type; }

string Chevrolet::getCarType() const { return carType; }

string Chevrolet::getLicensePlate() const { return licensePlate; }

string Chevrolet::getTypeOfWash() const { return typeOfWash; }

int Chevrolet::getQueuePosition() const { return queuePosition; }

void Chevrolet::display() const
{
    Vehicle::display();
    cout << " | Vehicle Type: " << vehicleType
         << " | Has Active Aero?: " << (hasActiveAero ? "True" : "False")
         << " | Has Parking Sensors?: " << (hasParkingSensors ? "True" : "False") << endl;
}
