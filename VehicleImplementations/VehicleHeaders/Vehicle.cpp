#include <iostream>
#include <string>

using namespace std;

class Vehicle // Abstract Base Class
{
public:
    // Parameterized Construtor
    Vehicle(
        int arrivalTime,
        int washTime,
        string typeOfWash,
        string carType,
        string licensePlate,
        int queuePosition,
        bool interiorCleaningRequired,
        int isVIP,
        float water,
        float soap);

    virtual int getArrivalTime() const = 0;

    virtual int getWashTime() const = 0;

    virtual string getCarType() const = 0;

    virtual int getWaterUsage() const;

    virtual int getSoapUsage() const;

    virtual string getLicensePlate() const = 0;

    virtual int getQueuePosition() const;

    virtual string getTypeOfWash() const = 0;

    virtual bool needsInteriorCleaning();

    virtual void display() const = 0;

    virtual int randomGenerator();

    virtual void movePosition();

private:
    int arrivalTime;
    int washTime;
    string typeOfWash;
    string carType;
    string licensePlate;
    int queuePosition;
    bool interiorCleaningRequired;
    int isVIP;
    float water;
    float soap;
};