#include <iostream>
#include "../Headers/Hellcat.h"
#include <ctime>

using namespace std;

Hellcat::Hellcat()
{
    setCarType("Hellcat");
    hasWideTires = rand() % 2;
    hasSportSuspension = rand() % 2;
    hasQuadExhaust = rand() % 2;
}

Hellcat::~Hellcat() {}

int Hellcat::getArrivalTime() const { return arrivalTime; }

int Hellcat::getWashTime() const { return washTime; }

void Hellcat::setCarType(string type) { carType = type; }

string Hellcat::getCarType() const { return carType; }

string Hellcat::getLicensePlate() const { return licensePlate; }

string Hellcat::getTypeOfWash() const { return typeOfWash; }

int Hellcat::getQueuePosition() const { return queuePosition; }

void Hellcat::display() const
{
    Vehicle::display();
    cout << " | Has Wide Tires?: " << (hasWideTires ? "True" : "False")
         << " | Has Sport Suspension?: " << (hasSportSuspension ? "True" : "False")
         << " | Has Quad Exhaust?: " << (hasQuadExhaust ? "True" : "False") << endl;
}
