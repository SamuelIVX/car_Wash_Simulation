#pragma once
#include "Vehicle.h"

class Tesla : public Vehicle
{
public:
    Tesla();

    virtual ~Tesla();

    virtual int getArrivalTime() const override;

    virtual int getWashTime() const override;

    virtual string getCarType() const override;

    virtual string getLicensePlate() const override;

    virtual string getTypeOfWash() const override;

    virtual int getQueuePosition() const override;

    virtual void setCarType(string type) override;

    virtual void display() const override;

    // virtual void cleanSensors() const;

private:
    // Electrical
    bool batteryInspected;

    // Sensors
    bool sensorCleaningRequired;
    int numberOfSensors;
};
