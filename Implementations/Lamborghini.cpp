#include <iostream>
#include "../Headers/Lamborghini.h"
#include <ctime>

using namespace std;

Lamborghini::Lamborghini()
{
    int randomValue = rand() % 2;
    string paintFinishes[] = {"Metallic", "Matte", "Glossy"};

    setCarType("Lamborghini");
    paintFinish = paintFinishes[randomValue];
    hasSpoiler = rand() % 2;
    HybridorElectric = (rand() % 2 == 1 ? "Hybrid" : "Electric");

    unordered_map<string, int> typesOfPaint{
        {"Metallic", 4},
        {"Matte", 5},
        {"Glossy", 6}};

    unordered_map<string, int> carTypes{
        {"Hybrid", 3},
        {"Electric", 4}};

    washTime += typesOfPaint[paintFinish] + carTypes[HybridorElectric];

    if (interiorCleaningRequired)
        washTime += 12;
    if (hasSpoiler)
        washTime += 5;
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
