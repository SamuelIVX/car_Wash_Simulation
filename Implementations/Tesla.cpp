#include <iostream>
#include "../Headers/Tesla.h"
using namespace std;

Tesla::Tesla(
    int arrivalTime,
    int washTime,
    string typeOfWash,
    string carType,
    string licensePlate,
    int queuePosition,
    bool interiorCleaningRequired,
    bool isVIP,
    float water,
    float soap,
    bool batteryInspected,
    bool sensorCleaningRequired,
    int numberOfSensors)
    : Vehicle(arrivalTime, washTime, typeOfWash, carType, licensePlate, queuePosition, interiorCleaningRequired, isVIP, water, soap)
{
    this->batteryInspected = batteryInspected;
    this->sensorCleaningRequired = sensorCleaningRequired;
    this->numberOfSensors = numberOfSensors;
}

Tesla::~Tesla() { cout << "Tesla Destructor Invoked."; }

int Tesla::getArrivalTime() const { return this->arrivalTime; }

int Tesla::getWashTime() const { return this->washTime; }

string Tesla::getCarType() const { return this->carType; }

string Tesla::getLicensePlate() const { return this->licensePlate; }

string Tesla::getTypeOfWash() const { return this->typeOfWash; }

int Tesla::getQueuePosition() const { return this->queuePosition; }

void Tesla::display() const
{
    Vehicle::display();
    cout << " | Battery Inspected?: " << batteryInspected
         << " | # of Sensors: " << numberOfSensors
         << " | Sensor Cleaning Required?: " << sensorCleaningRequired << endl;
}

// void Tesla::cleanSensors() const;