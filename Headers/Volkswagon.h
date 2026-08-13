/**
 * @file Volkswagon.h
 * @brief Volkswagen (spelled Volkswagon) subtype with wheel, paint, and interior material adjustments.
 */

#pragma once
#include "Vehicle.h"

/**
 * @brief Volkswagen (spelled Volkswagon) subtype with wheel, paint, and interior material adjustments.
 */
class Volkswagon : public Vehicle
{
public:
    /**
     * @brief Construct a Volkswagon; wheel/paint/interior choices extend washTime.
     * @param arrivalTime Simulation second when this car arrives.
     */
    Volkswagon(int arrivalTime);

    /** @brief Destroy this Volkswagon. */
    virtual ~Volkswagon();

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

    /** @brief Print base and Volkswagon-specific fields to stdout. */
    virtual void display() const override;

private:
    string wheelType;
    string paintType;
    string interiorMaterial;
};
