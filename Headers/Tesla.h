/**
 * @file Tesla.h
 * @brief Tesla subtype with battery inspection and sensor-cleaning wash adjustments.
 */

#pragma once
#include "Vehicle.h"

/**
 * @brief Tesla subtype with battery inspection and sensor-cleaning wash adjustments.
 */
class Tesla : public Vehicle
{
public:
    /**
     * @brief Construct a Tesla; may extend washTime for battery/sensors/interior.
     * @param arrivalTime Simulation second when this car arrives.
     */
    Tesla(int arrivalTime);

    /** @brief Destroy this Tesla. */
    virtual ~Tesla();

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

    /** @brief Print base and Tesla-specific fields to stdout. */
    virtual void display() const override;

private:
    bool batteryInspected;
    bool sensorCleaningRequired;
    int numberOfSensors;
};
