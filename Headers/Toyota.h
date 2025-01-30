#pragma once
#include "Vehicle.h"

class Toyota : public Vehicle
{
public:
    Toyota();

    virtual ~Toyota();

    virtual int getArrivalTime() const override;

    virtual int getWashTime() const override;

    virtual string getCarType() const override;

    virtual string getLicensePlate() const override;

    virtual string getTypeOfWash() const override;

    virtual int getQueuePosition() const override;

    virtual void setCarType(string type) override;

    virtual void display() const override;

private:
    bool hasTPMS;
    bool hasUnderbodyCoating;
    bool hasAirPurifier;
};
