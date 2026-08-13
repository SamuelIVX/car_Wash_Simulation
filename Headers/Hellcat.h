/**
 * @file Hellcat.h
 * @brief Hellcat subtype with tire, suspension, and exhaust wash adjustments.
 */

#pragma once
#include "Vehicle.h"

/**
 * @brief Hellcat subtype with tire, suspension, and exhaust wash adjustments.
 */
class Hellcat : public Vehicle
{
public:
    /**
     * @brief Construct a Hellcat; performance options extend washTime.
     * @param arrivalTime Simulation second when this car arrives.
     */
    Hellcat(int arrivalTime);

    /** @brief Destroy this Hellcat. */
    virtual ~Hellcat();

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

    /** @brief Print base and Hellcat-specific fields to stdout. */
    virtual void display() const override;

private:
    bool hasWideTires;
    bool hasSportSuspension;
    bool hasQuadExhaust;
};
