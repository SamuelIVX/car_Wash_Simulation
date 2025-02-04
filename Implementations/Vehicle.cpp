#include <iostream>
#include <ctime>
#include "../Headers/Tesla.h"
#include "../Headers/Volkswagon.h"
#include "../Headers/Toyota.h"
#include "../Headers/Nissan.h"
#include "../Headers/Lamborghini.h"
#include "../Headers/Jeep.h"
#include "../Headers/Hellcat.h"
#include "../Headers/Ford.h"
#include "../Headers/Chevrolet.h"
#include "../Headers/BMW.h"

using namespace std;

Vehicle::Vehicle(int arrivalTime)
{
    this->arrivalTime = arrivalTime;
    propertyGenerator();
    if (isVIP)
        washTime /= 2;
}

Vehicle::~Vehicle() {}

Vehicle *Vehicle::createRandomCar(int arrivalTime)
{
    int randomNumber = rand() % 10;
    switch (randomNumber)
    {
    case 0:
        return new Tesla(arrivalTime);
    case 1:
        return new Volkswagon(arrivalTime);
    case 2:
        return new Toyota(arrivalTime);
    case 3:
        return new Nissan(arrivalTime);
    case 4:
        return new Lamborghini(arrivalTime);
    case 5:
        return new Jeep(arrivalTime);
    case 6:
        return new Hellcat(arrivalTime);
    case 7:
        return new Ford(arrivalTime);
    case 8:
        return new Chevrolet(arrivalTime);
    case 9:
        return new BMW(arrivalTime);
    default:
        return nullptr;
    }
}

float Vehicle::getWaterUsage() const { return water; }

float Vehicle::getSoapUsage() const { return soap; }

float Vehicle::getIsVIP() const { return isVIP; }

int Vehicle::getQueuePosition() const { return queuePosition; };

bool Vehicle::needsInteriorCleaning() { return interiorCleaningRequired; }

string Vehicle::getLicensePlate() const { return licensePlate; }

void Vehicle::display() const
{
    cout << " | Arrival Time: " << arrivalTime
         << " | Car Type: " << carType
         << " | License Plate: " << licensePlate
         << " | Queue Position: " << queuePosition << endl
         << " | Wash Time: " << washTime << "min"
         << " | Type of Wash: " << typeOfWash
         << " | Interior Cleaning Required?: " << (interiorCleaningRequired == 1 ? "Yes" : "No")
         << " | VIP?: " << (isVIP == 1 ? "Yes" : "No") << endl
         << " | Water Usage: " << water << "gL"
         << " | Soap Usage: " << soap << "oz";
}

string Vehicle::licenseGenerator()
{
    const string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    string result;
    for (int i = 0; i < 11; ++i)
    {
        result += chars[rand() % chars.size()];
    }
    return result;
}

void Vehicle::propertyGenerator()
{
    int randomValue = rand() % 3;
    string washTypes[] = {"Hand Wash", "Automatic", "Full Service"};
    typeOfWash = washTypes[randomValue];
    washTime = (typeOfWash == "Hand Wash" ? 15 : typeOfWash == "Automatic" ? 5
                                                                           : 30);
    isVIP = rand() % 2;
    licensePlate = licenseGenerator();
    interiorCleaningRequired = rand() % 2;
    water = rand() % 6 + 1;
    soap = rand() % 6 + 1;
}