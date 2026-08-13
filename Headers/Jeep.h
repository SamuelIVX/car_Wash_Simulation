/**
 * @file Jeep.h
 * @brief Jeep subtype with 4WD, off-road tires, and roof-rack wash adjustments.
 */

#pragma once
#include "Vehicle.h"

/**
 * @brief Jeep subtype with 4WD, off-road tires, and roof-rack wash adjustments.
 */
class Jeep : public Vehicle
{
public:
    /**
     * @brief Construct a Jeep; off-road options extend washTime.
     * @param arrivalTime Simulation second when this car arrives.
     */
    Jeep(int arrivalTime);

    /** @brief Destroy this Jeep. */
    virtual ~Jeep();

    /** @brief Arrival time in simulated seconds. */
    virtual int getArrivalTime() const override;

    /** @brief Total wash duration including brand-specific extras. */
    virtual int getWashTime() const override;

    /** @brief Brand label for this vehicle. */
    virtual string getCarType() const override;

    /** @brief License plate string. */
    virtual string getLicensePlate() const override;

    /** @brief Wash package name. */
    virtual string getTypeOfWash() const override;

    /**
     * @brief Set the brand/type label.
     * @param type New car type string.
     */
    virtual void setCarType(string type) override;

    /** @brief Print base and Jeep-specific fields to stdout. */
    virtual void display() const override;

private:
    bool hasFourWheelDrive;
    bool hasOffRoadTires;
    bool hasRoofRack;
};
