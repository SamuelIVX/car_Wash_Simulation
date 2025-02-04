#include <iostream>
#include "../Headers/Tesla.h"
using namespace std;

Tesla::Tesla(int arrivalTime) : Vehicle(arrivalTime)
{
    setCarType("Tesla");
    batteryInspected = rand() % 2;
    numberOfSensors = rand() % 12 + 1;
    sensorCleaningRequired = rand() % 2;

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

    if (!batteryInspected)
        washTime += 2;
    if (sensorCleaningRequired)
        washTime += numberOfSensors * 2;
    if (interiorCleaningRequired)
        washTime += 3;
}

Tesla::~Tesla() {}

int Tesla::getArrivalTime() const { return arrivalTime; }

int Tesla::getWashTime() const { return washTime; }

void Tesla::setCarType(string type) { carType = type; }

string Tesla::getCarType() const { return carType; }

string Tesla::getLicensePlate() const { return licensePlate; }

string Tesla::getTypeOfWash() const { return typeOfWash; }

void Tesla::display() const
{
    Vehicle::display();
    cout << " | Battery Inspected?: " << (batteryInspected ? "Yes" : "No")
         << " | # of Sensors: " << numberOfSensors
         << " | Sensor Cleaning Required?: " << (sensorCleaningRequired ? "Yes" : "No") << endl;
}
