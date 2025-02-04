#pragma once
#include "Vehicle.h"

class Volkswagon : public Vehicle
{
public:
    Volkswagon(int arrivalTime);

    virtual ~Volkswagon();

    virtual int getArrivalTime() const override;

    virtual int getWashTime() const override;

    virtual string getCarType() const override;

    virtual string getLicensePlate() const override;

    virtual string getTypeOfWash() const override;

    virtual void setCarType(string type) override;

    virtual void display() const override;

private:
    string wheelType;
    string paintType;
    string interiorMaterial;
};
