#include <iostream>
#include "../Headers/Nissan.h"
#include <ctime>

using namespace std;

Nissan::Nissan()
{
    setCarType("Nissan");
    AWDorFWD = (rand() % 2 == 1 ? "All-Wheel-Drive" : "Front-Wheel-Drive");
    roofType = (rand() % 2 == 1 ? "Sunroof" : "Panoramic Roof");
    paintProtection = rand() % 2;

    if (paintProtection)
        washTime += 10;
    if (interiorCleaningRequired)
        washTime += 10;

    unordered_map<string, int> driveTypes = {
        {"All-Wheel-Drive", 10},
        {"Front-Wheel-Drive", 8}};
    unordered_map<string, int> roofTypes = {
        {"Sunroof", 1},
        {"Panoramic Roof", 3}};
    washTime += driveTypes[AWDorFWD] + roofTypes[roofType];
}

Nissan::~Nissan() {}

int Nissan::getArrivalTime() const { return arrivalTime; }

int Nissan::getWashTime() const { return washTime; }

void Nissan::setCarType(string type) { carType = type; }

string Nissan::getCarType() const { return carType; }

string Nissan::getLicensePlate() const { return licensePlate; }

string Nissan::getTypeOfWash() const { return typeOfWash; }

int Nissan::getQueuePosition() const { return queuePosition; }

void Nissan::display() const
{
    Vehicle::display();
    cout << " | AWD or FWD: " << AWDorFWD
         << " | Roof Type: " << roofType
         << " | Has Paint Protection: " << (paintProtection ? "True" : "False") << endl;
}
