#pragma once
#include <iostream>
#include <string>

using namespace std;

class Vehicle
{
public:
    Vehicle();

    virtual ~Vehicle();

    virtual int getArrivalTime() const = 0;

    virtual int getWashTime() const = 0;

    virtual void setCarType(string type) = 0;

    virtual string getCarType() const = 0;

    virtual string getLicensePlate() const = 0;

    virtual int getQueuePosition() const = 0;

    virtual string getTypeOfWash() const = 0;

    virtual void display() const = 0;

    virtual float getWaterUsage() const;

    virtual float getSoapUsage() const;

    virtual bool needsInteriorCleaning();

    virtual void propertyGenerator();

    virtual string licenseGenerator();

protected:
    int arrivalTime;
    int washTime;
    string typeOfWash;
    string carType;
    string licensePlate;
    int queuePosition;
    bool interiorCleaningRequired;
    bool isVIP;
    float water;
    float soap;
};