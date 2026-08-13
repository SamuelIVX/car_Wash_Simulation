/**
 * @file Toyota.cpp
 * @brief Toyota wash-time, resource, and display overrides for the car-wash simulation.
 */

#include <iostream>
#include "../Headers/Toyota.h"
#include <ctime>
#include <unordered_map>

using namespace std;

/** Construct a Toyota; option packages extend washTime. */
Toyota::Toyota(int arrivalTime) : Vehicle(arrivalTime)
{
    setCarType("Toyota");
    hasTPMS = rand() % 2;
    hasUnderbodyCoating = rand() % 2;
    hasAirPurifier = rand() % 2;

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

    if (hasTPMS)
        washTime += 3;
    if (hasUnderbodyCoating)
        washTime += 4;
    if (hasAirPurifier)
        washTime += 5;
    if (interiorCleaningRequired)
        washTime += 6;
}

Toyota::~Toyota() {}

int Toyota::getArrivalTime() const { return arrivalTime; }

int Toyota::getWashTime() const { return washTime; }

void Toyota::setCarType(string type) { carType = type; }

string Toyota::getCarType() const { return carType; }

string Toyota::getLicensePlate() const { return licensePlate; }

string Toyota::getTypeOfWash() const { return typeOfWash; }

/** Print shared Vehicle fields plus Toyota-specific options. */
void Toyota::display() const
{
    Vehicle::display();
    cout << " | Has TPMS?: " << (hasTPMS ? "True" : "False")
         << " | Has Underbody Coating?: " << (hasUnderbodyCoating ? "True" : "False")
         << " | Has Air Purifier?: " << (hasAirPurifier ? "True" : "False") << endl;
}
