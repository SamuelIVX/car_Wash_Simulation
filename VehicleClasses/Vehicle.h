#include <iostream>
#include <string>

using namespace std;

class Vehicle // Abstract Base Class
{
public:
    Vehicle(); // Default Constructor

    virtual int getArrivalTime() const;

    virtual int getWaterUsage() const;

    virtual int getSoapUsage() const;

    virtual bool needsInteriorCleaning();

    virtual string getLicensePlate() const = 0; // Unique Identifier for each car

    virtual string getTypeOfWash() const = 0;

    virtual string getCarType() const = 0;

    virtual void display() const = 0;

private:
    string licensePlate;
    int arrivalTime;
    float water;
    float soap;
};