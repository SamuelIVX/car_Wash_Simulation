/**
 * @file Chevrolet.h
 * @brief Chevrolet subtype with body style and aero/parking-sensor adjustments.
 */

#pragma once
#include "Vehicle.h"

/**
 * @brief Chevrolet subtype with body style and aero/parking-sensor adjustments.
 */
class Chevrolet : public Vehicle
{
public:
    /**
     * @brief Construct a Chevrolet; washTime depends on type and option packages.
     * @param arrivalTime Simulation second when this car arrives.
     */
    Chevrolet(int arrivalTime);

    /** @brief Destroy this Chevrolet. */
    virtual ~Chevrolet();

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

    /** @brief Print base and Chevrolet-specific fields to stdout. */
    virtual void display() const override;

private:
    string vehicleType;
    bool hasActiveAero;
    bool hasParkingSensors;
};
