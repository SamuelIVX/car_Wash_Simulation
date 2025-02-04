#include <iostream>
#include "../Headers/Lamborghini.h"
#include <ctime>

using namespace std;

Lamborghini::Lamborghini(int arrivalTime) : Vehicle(arrivalTime)
{
    int randomValue = rand() % 2;
    string paintFinishes[] = {"Metallic", "Matte", "Glossy"};

    setCarType("Lamborghini");
    paintFinish = paintFinishes[randomValue];
    hasSpoiler = rand() % 2;
    HybridorElectric = (rand() % 2 == 1 ? "Hybrid" : "Electric");

    unordered_map<string, int> typesOfPaint{
        {"Metallic", 2},
        {"Matte", 3},
        {"Glossy", 3}};

    unordered_map<string, int> carTypes{
        {"Hybrid", 3},
        {"Electric", 3}};

    washTime += typesOfPaint[paintFinish] + carTypes[HybridorElectric];

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
        washTime += 4;
    if (hasSpoiler)
        washTime += 3;
}

Lamborghini::~Lamborghini() {}

int Lamborghini::getArrivalTime() const { return arrivalTime; }

int Lamborghini::getWashTime() const { return washTime; }

void Lamborghini::setCarType(string type) { carType = type; }

string Lamborghini::getCarType() const { return carType; }

string Lamborghini::getLicensePlate() const { return licensePlate; }

string Lamborghini::getTypeOfWash() const { return typeOfWash; }

int Lamborghini::getQueuePosition() const { return queuePosition; }

void Lamborghini::display() const
{
    Vehicle::display();
    cout << " | Paint Finish: " << paintFinish
         << " | Has Spoiler?: " << (hasSpoiler ? "True" : "False")
         << " | Hybrid or Electric: " << HybridorElectric << endl;
}
