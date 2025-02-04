#include <iostream>
#include "../Headers/Nissan.h"
#include <ctime>

using namespace std;

Nissan::Nissan(int arrivalTime) : Vehicle(arrivalTime)
{
    setCarType("Nissan");
    AWDorFWD = (rand() % 2 == 1 ? "All-Wheel-Drive" : "Front-Wheel-Drive");
    roofType = (rand() % 2 == 1 ? "Sunroof" : "Panoramic Roof");
    paintProtection = rand() % 2;

    if (paintProtection)
        washTime += 5;
    if (interiorCleaningRequired)
        washTime += 5;

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

    unordered_map<string, int> driveTypes = {
        {"All-Wheel-Drive", 4},
        {"Front-Wheel-Drive", 4}};
    unordered_map<string, int> roofTypes = {
        {"Sunroof", 1},
        {"Panoramic Roof", 2}};

    washTime += driveTypes[AWDorFWD] + roofTypes[roofType];
}

Nissan::~Nissan() {}

int Nissan::getArrivalTime() const { return arrivalTime; }

int Nissan::getWashTime() const { return washTime; }

void Nissan::setCarType(string type) { carType = type; }

string Nissan::getCarType() const { return carType; }

string Nissan::getLicensePlate() const { return licensePlate; }

string Nissan::getTypeOfWash() const { return typeOfWash; }

void Nissan::display() const
{
    Vehicle::display();
    cout << " | AWD or FWD: " << AWDorFWD
         << " | Roof Type: " << roofType
         << " | Has Paint Protection: " << (paintProtection ? "True" : "False") << endl;
}
