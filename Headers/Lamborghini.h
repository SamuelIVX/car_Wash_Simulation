/**
 * @file Lamborghini.h
 * @brief Lamborghini subtype with paint finish, spoiler, and hybrid/electric adjustments.
 */

#pragma once
#include "Vehicle.h"

/**
 * @brief Lamborghini subtype with paint finish, spoiler, and hybrid/electric adjustments.
 */
class Lamborghini : public Vehicle
{
public:
    /**
     * @brief Construct a Lamborghini; paint and powertrain affect washTime.
     * @param arrivalTime Simulation second when this car arrives.
     */
    Lamborghini(int arrivalTime);

    /** @brief Destroy this Lamborghini. */
    virtual ~Lamborghini();

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

    /** @brief Print base and Lamborghini-specific fields to stdout. */
    virtual void display() const override;

private:
    string paintFinish;
    bool hasSpoiler;
    string HybridorElectric;
};
