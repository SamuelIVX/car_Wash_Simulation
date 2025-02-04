#pragma once
#include "Vehicle.h"

class Nissan : public Vehicle
{
public:
    Nissan(int arrivalTime);

    virtual ~Nissan();

    virtual int getArrivalTime() const override;

    virtual int getWashTime() const override;

    virtual string getCarType() const override;

    virtual string getLicensePlate() const override;

    virtual string getTypeOfWash() const override;

    virtual void setCarType(string type) override;

    virtual void display() const override;

private:
    string AWDorFWD;
    string roofType;
    bool paintProtection;
};
