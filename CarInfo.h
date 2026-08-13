/**
 * @file CarInfo.h
 * @brief Simple per-car record (type, wash style, arrival, water/soap) used by early queue demos.
 *
 * Distinct from the polymorphic Vehicle hierarchy; retained as a student-authored ADT.
 */

#include<iostream>
#include<string>
#include<cstdlib>
#ifndef CAR_INFO
#define CAR_INFO

using namespace std;

/**
 * @brief Snapshot of one car's wash metadata and resource usage.
 */
class CarInfo{
    public:
        /**
         * @brief Construct a blank car record (type/wash "none", numeric fields 0).
         */
        CarInfo();
        
        /**
         * @brief Construct a car arriving at @p a_t with randomized type and wash style.
         * @param a_t Simulation arrival time in seconds.
         */
        CarInfo(int a_t);

        /** @brief Unique-ish car number for this record. */
        int getCarNum()const;

        /** @brief Vehicle size category (e.g. mini, van, truck). */
        string getCarType()const;

        /** @brief Wash style (hand, automatic, or premium). */
        string getTypeOfWash()const;

        /** @brief Arrival time in simulated seconds. */
        int getArrivalTime()const;

        /** @brief Water usage accumulated for this car. */
        int getWater()const;

        /** @brief Soap usage accumulated for this car. */
        int getSoap()const;

    private:
        int carNum;
        string carType;
        string typeOfWash;
        int arrivalTime;
        int water;
        int soap; 
};

#endif
