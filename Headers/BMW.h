#pragma once
#include "Vehicle.h"

class BMW : public Vehicle
{
public:
    BMW();

    virtual ~BMW();

    virtual int getArrivalTime() const override;

    virtual int getWashTime() const override;

    virtual string getCarType() const override;

    virtual string getLicensePlate() const override;

    virtual string getTypeOfWash() const override;

    virtual int getQueuePosition() const override;

    virtual void setCarType(string type) override;

    virtual void display() const override;

private:
    string model;
    string vehicleType;
    bool hasRainSensingWipers;
};
