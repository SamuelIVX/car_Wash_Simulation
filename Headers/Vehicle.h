/**
 * @file Vehicle.h
 * @brief Abstract polymorphic base for brands used in the car-wash queue simulation.
 *
 * Owns shared wash metadata (arrival, VIP, water/soap) and the random-car factory.
 */

#pragma once
#include <iostream>
#include <string>

using namespace std;

/**
 * @brief Base vehicle in the wash queue; concrete brands override display and accessors.
 */
class Vehicle
{
public:
    /**
     * @brief Construct a vehicle arriving at @p arrivalTime and roll shared properties.
     * @param arrivalTime Simulation second when this car arrives.
     * @post VIP cars get half the base washTime from propertyGenerator().
     */
    Vehicle(int arrivalTime);

    /** @brief Virtual destructor for polymorphic deletion. */
    virtual ~Vehicle();

    /**
     * @brief Factory that returns a heap-allocated random concrete Vehicle subtype.
     * @param arrivalTime Simulation second stamped on the new car.
     * @return Owning pointer to a derived Vehicle; caller must delete.
     * @example
     * Vehicle *car = Vehicle::createRandomCar(42);
     * // use car, then delete car;
     */
    static Vehicle *createRandomCar(int arrivalTime);

    /** @brief Arrival time in simulated seconds. */
    virtual int getArrivalTime() const = 0;

    /** @brief Total wash duration for this car (brand-adjusted). */
    virtual int getWashTime() const = 0;

    /** @brief Set the display brand/type string. */
    virtual void setCarType(string type) = 0;

    /** @brief Brand/type label used in queue prints. */
    virtual string getCarType() const = 0;

    /** @brief Generated license plate string. */
    virtual string getLicensePlate() const = 0;

    /** @brief Position hint in the queue (shared base field). */
    virtual int getQueuePosition() const;

    /** @brief Wash package name (Hand Wash / Automatic / Full Service). */
    virtual string getTypeOfWash() const = 0;

    /** @brief Print vehicle details to stdout. */
    virtual void display() const = 0;

    /** @brief Water usage for this wash. */
    virtual float getWaterUsage() const;

    /** @brief Soap usage for this wash. */
    virtual float getSoapUsage() const;

    /**
     * @brief Whether this car is treated as VIP (preferential queue).
     * @return Non-zero when VIP; stored as bool but returned as float historically.
     */
    virtual float getIsVIP() const;

    /** @brief Whether an interior clean was rolled for this car. */
    virtual bool needsInteriorCleaning();

    /** @brief Roll shared wash type, VIP, plate, water/soap, and base wash time. */
    virtual void propertyGenerator();

    /**
     * @brief Build an 11-character alphanumeric license plate.
     * @return Random plate string.
     */
    virtual string licenseGenerator();

protected:
    int arrivalTime;
    int washTime;
    string typeOfWash;
    string carType;
    string licensePlate;
    int queuePosition;
    bool interiorCleaningRequired;
    bool isVIP;
    float water;
    float soap;
};
