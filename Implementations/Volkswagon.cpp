#include <iostream>
#include "../Headers/Volkswagon.h"
#include <ctime>

using namespace std;

Volkswagon::Volkswagon()
{
    int randomValue = rand() % 4;
    string wheelTypes[] = {"Aluminum", "Alloy", "Steel", "Chrome"};
    string paintTypes[] = {"Metallic", "Brushed", "Gloos", "Matte"};
    string interiorMaterials[] = {"Leather", "Fabric", "V-Tex", "Cloth"};

    setCarType("Volkswagon");
    wheelType = wheelTypes[randomValue];
    paintType = paintTypes[randomValue];
    interiorMaterial = interiorMaterials[randomValue];
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
