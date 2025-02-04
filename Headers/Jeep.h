#pragma once
#include "Vehicle.h"

class Jeep : public Vehicle
{
public:
    Jeep(int arrivalTime);

    virtual ~Jeep();

    virtual int getArrivalTime() const override;

    virtual int getWashTime() const override;

    virtual string getCarType() const override;

    virtual string getLicensePlate() const override;

    virtual string getTypeOfWash() const override;

    virtual void setCarType(string type) override;

    virtual void display() const override;

private:
    bool hasFourWheelDrive;
    bool hasOffRoadTires;
    bool hasRoofRack;
};
