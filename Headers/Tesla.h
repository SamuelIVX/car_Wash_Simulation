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
        bool isVIP,
        float water,
        float soap,
        bool batteryInspected,
        bool sensorCleaningRequired,
        int numberOfSensors);

    virtual ~Tesla();

    virtual int getArrivalTime() const override;

    virtual int getWashTime() const override;

    virtual string getCarType() const override;

    virtual string getLicensePlate() const override;

    virtual string getTypeOfWash() const override;

    virtual int getQueuePosition() const override;

    virtual void display() const override;

    // virtual void cleanSensors() const;

private:
    int arrivalTime;
    int washTime;
    int queuePosition;
    string carType;
    string typeOfWash;
    string licensePlate;

    // Electrical
    bool batteryInspected;

    // Sensors
    bool sensorCleaningRequired;
    int numberOfSensors;
};
