#pragma once
#include "Vehicle.h"

class Ford : public Vehicle
{
public:
    Ford();

    virtual ~Ford();

    virtual int getArrivalTime() const override;

    virtual int getWashTime() const override;

    virtual string getCarType() const override;

    virtual string getLicensePlate() const override;

    virtual string getTypeOfWash() const override;

    virtual int getQueuePosition() const override;

    virtual void setCarType(string type) override;

    virtual void display() const override;

private:
    string vehicleType;
    string driveTrain;
    string driveMode;
};
