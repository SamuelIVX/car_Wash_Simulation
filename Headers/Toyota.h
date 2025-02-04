#pragma once
#include "Vehicle.h"

class Toyota : public Vehicle
{
public:
    Toyota(int arrivalTime);

    virtual ~Toyota();

    virtual int getArrivalTime() const override;

    virtual int getWashTime() const override;

    virtual string getCarType() const override;

    virtual string getLicensePlate() const override;

    virtual string getTypeOfWash() const override;

    virtual void setCarType(string type) override;

    virtual void display() const override;

private:
    bool hasTPMS;
    bool hasUnderbodyCoating;
    bool hasAirPurifier;
};
