#include <iostream>
#include "../Headers/Tesla.h"
using namespace std;

Tesla::Tesla()
{
    setCarType("Tesla");
    batteryInspected = rand() % 2;
    numberOfSensors = rand() % 12 + 1;
    sensorCleaningRequired = rand() % 2;

    if (!batteryInspected)
        washTime += 2;
    if (sensorCleaningRequired)
        washTime += numberOfSensors * 2;
    if (interiorCleaningRequired)
        washTime += 13;
}

Tesla::~Tesla() {}

int Tesla::getArrivalTime() const { return arrivalTime; }

int Tesla::getWashTime() const { return washTime; }

void Tesla::setCarType(string type) { carType = type; }

string Tesla::getCarType() const { return carType; }

string Tesla::getLicensePlate() const { return licensePlate; }

string Tesla::getTypeOfWash() const { return typeOfWash; }

int Tesla::getQueuePosition() const { return queuePosition; }

void Tesla::display() const
{
    Vehicle::display();
    cout << " | Battery Inspected?: " << (batteryInspected ? "Yes" : "No")
         << " | # of Sensors: " << numberOfSensors
         << " | Sensor Cleaning Required?: " << (sensorCleaningRequired ? "Yes" : "No") << endl;
}
