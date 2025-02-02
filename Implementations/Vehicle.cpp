#include <iostream>
#include "../Headers/Vehicle.h"
#include <ctime>

using namespace std;

Vehicle::Vehicle() { propertyGenerator(); }

Vehicle::~Vehicle() {}

float Vehicle::getWaterUsage() const { return water; }

float Vehicle::getSoapUsage() const { return soap; }

bool Vehicle::needsInteriorCleaning() { return interiorCleaningRequired; }

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
    licensePlate = licenseGenerator();
    interiorCleaningRequired = rand() % 2;
    water = rand() % 6 + 1;
    soap = rand() % 6 + 1;
}