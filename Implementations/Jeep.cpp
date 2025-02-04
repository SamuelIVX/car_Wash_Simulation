#include <iostream>
#include "../Headers/Jeep.h"
#include <ctime>

using namespace std;

Jeep::Jeep(int arrivalTime) : Vehicle(arrivalTime)
{
    setCarType("Jeep");
    hasFourWheelDrive = rand() % 2;
    hasOffRoadTires = rand() % 2;
    hasRoofRack = rand() % 2;

    unordered_map<string, int> waterUsages = {
        {"Hand Wash", 35},
        {"Automatic", 45},
        {"Full Service", 60}};

    unordered_map<string, int> soapUsages = {
        {"Hand Wash", 2},
        {"Automatic", 1},
        {"Full Service", 3}};

    water = waterUsages[typeOfWash];
    soap = soapUsages[typeOfWash];

    if (interiorCleaningRequired)
        washTime += 8;
    if (hasFourWheelDrive)
        washTime += 4;
    if (hasOffRoadTires)
        washTime += 9;
    if (hasRoofRack)
        washTime += 3;
}

Jeep::~Jeep() {}

int Jeep::getArrivalTime() const { return arrivalTime; }

int Jeep::getWashTime() const { return washTime; }

void Jeep::setCarType(string type) { carType = type; }

string Jeep::getCarType() const { return carType; }

string Jeep::getLicensePlate() const { return licensePlate; }

string Jeep::getTypeOfWash() const { return typeOfWash; }

void Jeep::display() const
{
    Vehicle::display();
    cout << " | Has Four Wheel Drive?: " << (hasFourWheelDrive ? "True" : "False")
         << " | Has Offroad Tires?: " << (hasOffRoadTires ? "True" : "False")
         << " | Has Roof Rack?: " << (hasRoofRack ? "True" : "False") << endl;
}
