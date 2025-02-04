#include <iostream>
#include "../Headers/Volkswagon.h"
#include <ctime>
#include <unordered_map>

using namespace std;

Volkswagon::Volkswagon(int arrivalTime) : Vehicle(arrivalTime)
{

    int randomValue = rand() % 4;

    string wheelTypes[] = {"Aluminum", "Alloy", "Steel", "Chrome"};
    string paintTypes[] = {"Metallic", "Brushed", "Gloss", "Matte"};
    string interiorMaterials[] = {"Leather", "Fabric", "V-Tex", "Cloth"};

    unordered_map<string, int> wheelWashTimes = {
        {"Alloy", 3},
        {"Steel", 4},
        {"Aluminum", 5},
        {"Chrome", 5}};

    unordered_map<string, int> paintWashTimes = {
        {"Gloss", 2},
        {"Metallic", 3},
        {"Brushed", 4},
        {"Matte", 3}};

    unordered_map<string, int> interiorWashTimes = {
        {"Leather", 2},
        {"V-Tex", 3},
        {"Cloth", 3},
        {"Fabric", 5}};

    unordered_map<string, int> waterUsages = {
        {"Hand Wash", 35},
        {"Automatic", 45},
        {"Full Service", 60}};

    unordered_map<string, int> soapUsages = {
        {"Hand Wash", 2},
        {"Automatic", 1},
        {"Full Service", 3}};

    setCarType("Volkswagon");

    wheelType = wheelTypes[randomValue];
    paintType = paintTypes[randomValue];
    interiorMaterial = interiorMaterials[randomValue];

    if (interiorCleaningRequired)
        washTime += wheelWashTimes[wheelType] + paintWashTimes[paintType] + interiorWashTimes[interiorMaterial];
    else
        washTime += wheelWashTimes[wheelType] + paintWashTimes[paintType];

    water = waterUsages[typeOfWash];
    soap = soapUsages[typeOfWash];
}

Volkswagon::~Volkswagon() {}

int Volkswagon::getArrivalTime() const { return arrivalTime; }

int Volkswagon::getWashTime() const { return washTime; }

void Volkswagon::setCarType(string type) { carType = type; }

string Volkswagon::getCarType() const { return carType; }

string Volkswagon::getLicensePlate() const { return licensePlate; }

string Volkswagon::getTypeOfWash() const { return typeOfWash; }

int Volkswagon::getQueuePosition() const { return queuePosition; }

void Volkswagon::display() const
{
    Vehicle::display();
    cout << " | Wheel Type: " << wheelType
         << " | Paint Type: " << paintType
         << " | Interior Material: " << interiorMaterial << endl;
}
