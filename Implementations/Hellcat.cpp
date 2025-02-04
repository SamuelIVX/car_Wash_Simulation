#include <iostream>
#include "../Headers/Hellcat.h"
#include <ctime>

using namespace std;

Hellcat::Hellcat(int arrivalTime) : Vehicle(arrivalTime)
{
    setCarType("Hellcat");
    hasWideTires = rand() % 2;
    hasSportSuspension = rand() % 2;
    hasQuadExhaust = rand() % 2;

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
        washTime += 6;
    if (hasWideTires)
        washTime += 5;
    if (hasSportSuspension)
        washTime += 5;
    if (hasQuadExhaust)
        washTime += 6;
}

Hellcat::~Hellcat() {}

int Hellcat::getArrivalTime() const { return arrivalTime; }

int Hellcat::getWashTime() const { return washTime; }

void Hellcat::setCarType(string type) { carType = type; }

string Hellcat::getCarType() const { return carType; }

string Hellcat::getLicensePlate() const { return licensePlate; }

string Hellcat::getTypeOfWash() const { return typeOfWash; }

void Hellcat::display() const
{
    Vehicle::display();
    cout << " | Has Wide Tires?: " << (hasWideTires ? "True" : "False")
         << " | Has Sport Suspension?: " << (hasSportSuspension ? "True" : "False")
         << " | Has Quad Exhaust?: " << (hasQuadExhaust ? "True" : "False") << endl;
}
