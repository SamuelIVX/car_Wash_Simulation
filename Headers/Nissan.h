/**
 * @file Nissan.h
 * @brief Nissan subtype with drivetrain, roof type, and paint-protection adjustments.
 */

#pragma once
#include "Vehicle.h"

/**
 * @brief Nissan subtype with drivetrain, roof type, and paint-protection adjustments.
 */
class Nissan : public Vehicle
{
public:
    /**
     * @brief Construct a Nissan; drivetrain/roof/paint options extend washTime.
     * @param arrivalTime Simulation second when this car arrives.
     */
    Nissan(int arrivalTime);

    /** @brief Destroy this Nissan. */
    virtual ~Nissan();

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

    /** @brief Print base and Nissan-specific fields to stdout. */
    virtual void display() const override;

private:
    string AWDorFWD;
    string roofType;
    bool paintProtection;
};
