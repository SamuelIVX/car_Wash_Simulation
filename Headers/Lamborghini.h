#pragma once
#include "Vehicle.h"

class Lamborghini : public Vehicle
{
public:
    Lamborghini(int arrivalTime);

    virtual ~Lamborghini();

    virtual int getArrivalTime() const override;

    virtual int getWashTime() const override;

    virtual string getCarType() const override;

    virtual string getLicensePlate() const override;

    virtual string getTypeOfWash() const override;

    virtual void setCarType(string type) override;

    virtual void display() const override;

private:
    string paintFinish;
    bool hasSpoiler;
    string HybridorElectric;
};
