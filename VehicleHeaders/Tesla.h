#pragma once
#include "Vehicle.h"

class Tesla : public Vehicle
{
public:
    Tesla(
        int arrivalTime,
        int washTime,
        string typeOfWash,
        string carType,
        string licensePlate,
        int queuePosition,
        bool interiorCleaningRequired,
        int isVIP,
        float water,
        float soap,
        bool batteryInspected,
        bool sensorCleaningRequired,
        int numberOfSensors);

    virtual int getArrivalTime() const;

    virtual int getWashTime() const;

    virtual string getTypeOfWash() const;

    virtual int getWaterUsage() const;

    virtual int getSoapUsage() const;

    virtual string getLicensePlate() const;

    virtual int getQueuePosition() const;

    virtual string getCarType() const;

    virtual void display() const;

    virtual void cleanSensors() const;

private:
    // Electrical
    bool batteryInspected;

    // Sensors
    bool sensorCleaningRequired;
    int numberOfSensors;
};
