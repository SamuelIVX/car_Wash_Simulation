#pragma once
#include "Vehicle.h"

class Hellcat : public Vehicle
{
public:
    Hellcat(int arrivalTime);

    virtual ~Hellcat();

    virtual int getArrivalTime() const override;

    virtual int getWashTime() const override;

    virtual string getCarType() const override;

    virtual string getLicensePlate() const override;

    virtual string getTypeOfWash() const override;

    virtual void setCarType(string type) override;

    virtual void display() const override;

private:
    bool hasWideTires;
    bool hasSportSuspension;
    bool hasQuadExhaust;
};
