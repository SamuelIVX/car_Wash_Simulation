/**
 * @file Ford.h
 * @brief Ford subtype with body style, drivetrain, and drive-mode wash adjustments.
 */

#pragma once
#include "Vehicle.h"

/**
 * @brief Ford subtype with body style, drivetrain, and drive-mode wash adjustments.
 */
class Ford : public Vehicle
{
public:
    /**
     * @brief Construct a Ford; washTime depends on type, drivetrain, and drive mode.
     * @param arrivalTime Simulation second when this car arrives.
     */
    Ford(int arrivalTime);

    /** @brief Destroy this Ford. */
    virtual ~Ford();

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

    /** @brief Print base and Ford-specific fields to stdout. */
    virtual void display() const override;

private:
    string vehicleType;
    string driveTrain;
    string driveMode;
};
