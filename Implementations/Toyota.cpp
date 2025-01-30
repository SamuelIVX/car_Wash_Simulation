#include <iostream>
#include "../Headers/Toyota.h"
#include <ctime>

using namespace std;

Toyota::Toyota()
{
    setCarType("Toyota");
    hasTPMS = rand() % 2;
    hasUnderbodyCoating = rand() % 2;
    hasAirPurifier = rand() % 2;
}

Toyota::~Toyota() {}

int Toyota::getArrivalTime() const { return arrivalTime; }

int Toyota::getWashTime() const { return washTime; }

void Toyota::setCarType(string type) { carType = type; }

string Toyota::getCarType() const { return carType; }

string Toyota::getLicensePlate() const { return licensePlate; }

string Toyota::getTypeOfWash() const { return typeOfWash; }

int Toyota::getQueuePosition() const { return queuePosition; }

void Toyota::display() const
{
    Vehicle::display();
    cout << " | Has TPMS?: " << (hasTPMS ? "True" : "False")
         << " | Has Underbody Coating?: " << (hasUnderbodyCoating ? "True" : "False")
         << " | Has Air Purifier?: " << (hasAirPurifier ? "True" : "False") << endl;
}
