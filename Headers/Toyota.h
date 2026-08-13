/**
 * @file Toyota.h
 * @brief Toyota subtype with TPMS, underbody coating, and air-purifier adjustments.
 */

#pragma once
#include "Vehicle.h"

/**
 * @brief Toyota subtype with TPMS, underbody coating, and air-purifier adjustments.
 */
class Toyota : public Vehicle
{
public:
    /**
     * @brief Construct a Toyota; option packages extend washTime.
     * @param arrivalTime Simulation second when this car arrives.
     */
    Toyota(int arrivalTime);

    /** @brief Destroy this Toyota. */
    virtual ~Toyota();

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

    /** @brief Print base and Toyota-specific fields to stdout. */
    virtual void display() const override;

private:
    bool hasTPMS;
    bool hasUnderbodyCoating;
    bool hasAirPurifier;
};
