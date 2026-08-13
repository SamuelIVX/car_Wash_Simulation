/**
 * @file Ford.cpp
 * @brief Ford wash-time, resource, and display overrides for the car-wash simulation.
 */

#include <iostream>
#include "../Headers/Ford.h"
#include <ctime>
#include <unordered_map>

using namespace std;

/** Construct a Ford; washTime depends on type, drivetrain, and drive mode. */
Ford::Ford(int arrivalTime) : Vehicle(arrivalTime)
{

    int randomValue = rand() % 4;
    string vehicleTypes[] = {"Truck", "SUV", "Car"};
    string driveTrains[] = {"FWD", "RWD", "AWD"};
    string driveModes[] = {"Sport", "Track", "Off-Road"};

    setCarType("Ford");
    vehicleType = vehicleTypes[randomValue];
    driveTrain = driveTrains[randomValue];
    driveMode = driveModes[randomValue];

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

    unordered_map<string, int> vehicleTypeTimes{
        {"Truck", 5},
        {"SUV", 4},
        {"Car", 3}};
    unordered_map<string, int> driveTrainTimes{
        {"FWD", 3},
        {"RWD", 3},
        {"AWD", 2}};
    unordered_map<string, int> driveModeTimes{
        {"Sport", 3},
        {"Track", 4},
        {"Off-road", 5}};

    washTime += vehicleTypeTimes[vehicleType] + driveTrainTimes[driveTrain] + driveModeTimes[driveMode];
    if (interiorCleaningRequired)
        washTime += 4;
}

Ford::~Ford() {}

int Ford::getArrivalTime() const { return arrivalTime; }

int Ford::getWashTime() const { return washTime; }

void Ford::setCarType(string type) { carType = type; }

string Ford::getCarType() const { return carType; }

string Ford::getLicensePlate() const { return licensePlate; }

string Ford::getTypeOfWash() const { return typeOfWash; }

/** Print shared Vehicle fields plus Ford-specific options. */
void Ford::display() const
{
    Vehicle::display();
    cout << " | Vehicle Type: " << vehicleType
         << " | Drive Train: " << driveTrain
         << " | Drive Mode: " << driveMode << endl;
}
