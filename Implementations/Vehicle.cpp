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
         << " | Wash Time: " << washTime << " min"
         << " | Type of Wash: " << typeOfWash
         << " | Interior Cleaning Required?: " << interiorCleaningRequired
         << " | VIP?: " << isVIP << endl
         << " | Water Usage: " << water << " gL"
         << " | Soap Usage: " << soap << " gL";
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
    int randomValue = rand() % 2;
    string washTypes[] = {"Regular", "Premium", "Luxury"};
    washTime = rand() % 10 + 1;
    typeOfWash = washTypes[randomValue];
    licensePlate = licenseGenerator();
    interiorCleaningRequired = rand() % 2;
    water = rand() % 6 + 1;
    soap = rand() % 6 + 1;
}