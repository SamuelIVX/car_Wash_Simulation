#include <iostream>
#include "../Headers/Ford.h"
#include <ctime>

using namespace std;

Ford::Ford()
{

    int randomValue = rand() % 4;
    string vehicleTypes[] = {"Truck", "SUV", "Car"};
    string driveTrains[] = {"FWD", "RWD", "AWD"};
    string driveModes[] = {"Sport", "Track", "Off-Road"};

    setCarType("Ford");
    vehicleType = vehicleTypes[randomValue];
    driveTrain = driveTrains[randomValue];
    driveMode = driveModes[randomValue];
}

Ford::~Ford() {}

int Ford::getArrivalTime() const { return arrivalTime; }

int Ford::getWashTime() const { return washTime; }

void Ford::setCarType(string type) { carType = type; }

string Ford::getCarType() const { return carType; }

string Ford::getLicensePlate() const { return licensePlate; }

string Ford::getTypeOfWash() const { return typeOfWash; }

int Ford::getQueuePosition() const { return queuePosition; }

void Ford::display() const
{
    Vehicle::display();
    cout << " | Vehicle Type: " << vehicleType
         << " | Drive Train: " << driveTrain
         << " | Drive Mode: " << driveMode << endl;
}
