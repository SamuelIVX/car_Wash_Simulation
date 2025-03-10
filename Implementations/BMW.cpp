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
        {"3-Series", 2},
        {"M4", 4},
        {"X5", 3}};

    unordered_map<string, int> vehicleTypeTimes{
        {"Sedan", 5},
        {"SUV", 4},
        {"Sports", 3}};

    washTime += vehicleModelTimes[model] + vehicleTypeTimes[vehicleType];

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
        washTime += 7;
    if (hasRainSensingWipers)
        washTime += 3;
}

BMW::~BMW() {}

int BMW::getArrivalTime() const { return arrivalTime; }

int BMW::getWashTime() const { return washTime; }

void BMW::setCarType(string type) { carType = type; }

string BMW::getCarType() const { return carType; }

string BMW::getLicensePlate() const { return licensePlate; }

string BMW::getTypeOfWash() const { return typeOfWash; }

void BMW::display() const
{
    Vehicle::display();
    cout << " | Model: " << model
         << " | Vehicle Type: " << vehicleType
         << " | Has Rain Sensing Wipers?: " << (hasRainSensingWipers ? "True" : "False") << endl;
}
