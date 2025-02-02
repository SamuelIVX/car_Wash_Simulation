#include <iostream>
#include "../Headers/BMW.h"
#include <ctime>

using namespace std;

BMW::BMW(int arrivalTime) : Vehicle(arrivalTime)
{
    int randomValue = rand() % 3;
    string models[] = {"3-Series", "M4", "X5"};
    string vehicleTypes[] = {"Sedan", "SUV", "Sports"};

    setCarType("BMW");
    model = models[randomValue];
    vehicleType = vehicleTypes[randomValue];
    hasRainSensingWipers = rand() % 2;

    unordered_map<string, int> vehicleModelTimes{
        {"3-Series", 6},
        {"M4", 4},
        {"X5", 7}};

    unordered_map<string, int> vehicleTypeTimes{
        {"Sedan", 10},
        {"SUV", 8},
        {"Sports", 7}};

    washTime += vehicleModelTimes[model] + vehicleTypeTimes[vehicleType];

    if (interiorCleaningRequired)
        washTime += 13;
    if (hasRainSensingWipers)
        washTime += 6;
}

BMW::~BMW() {}

int BMW::getArrivalTime() const { return arrivalTime; }

int BMW::getWashTime() const { return washTime; }

void BMW::setCarType(string type) { carType = type; }

string BMW::getCarType() const { return carType; }

string BMW::getLicensePlate() const { return licensePlate; }

string BMW::getTypeOfWash() const { return typeOfWash; }

int BMW::getQueuePosition() const { return queuePosition; }

void BMW::display() const
{
    Vehicle::display();
    cout << " | Model: " << model
         << " | Vehicle Type: " << vehicleType
         << " | Has Rain Sensing Wipers?: " << (hasRainSensingWipers ? "True" : "False") << endl;
}
