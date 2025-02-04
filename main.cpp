#include <stdlib.h>
#include <iostream> // Provides cout
#include <cstdlib>  // Provides EXIT_SUCCESS
#include <unistd.h> //For the sleep function
#include "Headers/Vehicle.h"
#include "Headers/Tesla.h"
#include "Headers/Volkswagon.h"
#include "Headers/Toyota.h"
#include "Headers/Nissan.h"
#include "Headers/Lamborghini.h"
#include "Headers/Jeep.h"
#include "Headers/Hellcat.h"
#include "Headers/Ford.h"
#include "Headers/Chevrolet.h"
#include "Headers/BMW.h"
#include "Que.h"     //Provides queue
#include "washing.h" // Provides averager, bool_source, washer
#include "CarInfo.h" //The class I created
#include <string>
#include <ctime>

using namespace std;

// Prototype for car_wash_simulate
void car_wash_simulate(double arrival_prob, unsigned int total_time);

int main()
{
    srand(time(0));

    double arrival_probability, total_time;

    cout << "Enter arrival probability (0 <= p <= 1): ";
    cin >> arrival_probability;

    cout << "Enter total time in seconds: ";
    cin >> total_time;

    // Starting the simulation
    car_wash_simulate(arrival_probability, total_time);

    return 0;
}

// Function Definition for car_wash_simulate
void car_wash_simulate(double arrival_prob, unsigned int total_time)
{
    Que<Vehicle *> carWashQueue, VIPQueue, finishedCarsQueue;
    vector<Vehicle *> carsToBeDeleted;
    bool_source get_prob(arrival_prob);
    washer car_wash, vip_car_wash;

    Vehicle *currentCar, *currentVIPCar;

    // Initializing and declaring 6 counter variables
    int carsWashed = 0, vipCarsWashed = 0, carsNotWashed = 0, vipCarsNotWashed = 0, currentTime = 0, waitTime = 0, vipWaitTime = 0, average_waiting_time = 0, vip_average_waiting_time = 0, totalWaitingTime = 0, vipTotalWaitingTime = 0;

    // Keep looping while the currentTime is less than the total simulation runtime
    while (currentTime < total_time)
    {
        // Check if a new car arrives, even if the washer is busy
        if (get_prob.query())
        {
            cout << setfill('-') << setw(55) << endl;
            Vehicle *car = Vehicle::createRandomCar(currentTime); // A new car has arrived, construct a new Vehicle object

            cout << "\n\t\tTime: " << currentTime << " sec(s)" << endl;
            cout << "\nA '" << car->getCarType() << "' has arrived." << endl;

            if (car->getIsVIP())
            {
                cout << car->getCarType() << " is a VIP member!. Moving vehicle to the VIP queue!\n";
                VIPQueue.addQ(car);
                vip_car_wash.setWashingTime(car->getWashTime());
                vipWaitTime = VIPQueue.wait_time(car->getWashTime(), vip_car_wash); // calculate the wait time for nth car in the queue
                vipTotalWaitingTime += vipWaitTime;
                cout << "\nWait Time for the VIP queue: " << vipWaitTime << " sec(s)" << endl;
            }
            else
            {
                carWashQueue.addQ(car); // Add the new car into the regular car queue
                car_wash.setWashingTime(car->getWashTime());
                waitTime = carWashQueue.wait_time(car->getWashTime(), car_wash); // calculate the wait time for nth car in the queue
                totalWaitingTime += waitTime;
                cout << "\nWait Time for the regular queue: " << waitTime << " sec(s)" << endl;
            }

            carsToBeDeleted.push_back(car); // Delete the dynamically allocated Vehicle* objects after the simulation has ended

            carWashQueue.printQueue(); // Print out the queue each time a new car arrives!
            VIPQueue.printQueue();     // Print out the queue each time a new car arrives!
        }
        else
        {
            cout << setfill('-') << setw(55) << endl;
            cout << "\n\t\tTime: " << currentTime << " sec(s)" << endl
                 << "\t\tNo car has arrived..." << endl;
        }

        // Prioritze the VIP queue first
        while (vip_car_wash.is_busy())
        {
            vip_car_wash.one_second();
            // If wash time is done, process the finished car
            if (vip_car_wash.get_wash_time_left() <= 0)
            {
                Vehicle *finishedVIPCar;
                VIPQueue.removeQ(finishedVIPCar);       // Removing the car from the queue and grabbing it
                finishedCarsQueue.addQ(finishedVIPCar); // Add the recently removed car into another queue for later on [statistical purpose]
                vipCarsWashed++;                        // Iterate the amount of cars successfully washed
                cout << endl
                     << finishedVIPCar->getCarType() << " has been washed and dequeued.\n";
                VIPQueue.printQueue(); // Print out the queue each time a car has been washed!
            }
        }

        // If the washer is busy, iterate the wash time by 1
        if (car_wash.is_busy())
        {
            car_wash.one_second();
            // If wash time is done, process the finished car
            if (car_wash.get_wash_time_left() <= 0)
            {
                Vehicle *finishedCar;
                carWashQueue.removeQ(finishedCar);   // Removing the car from the queue and grabbing it
                finishedCarsQueue.addQ(finishedCar); // Add the recently removed car into another queue for later on [statistical purpose]
                carsWashed++;                        // Iterate the amount of cars successfully washed
                cout << endl
                     << finishedCar->getCarType() << " has been washed and dequeued.\n";
                carWashQueue.printQueue(); // Print out the queue each time a car has been washed!
            }
        }

        // VIP Washer first
        if (!vip_car_wash.is_busy() && !VIPQueue.empty())
        {
            cout << "\nVIP Car wash is not busy...\n";
            currentVIPCar = VIPQueue.getFront(); // Grab the first car in the queue [not removing it from the queue]
            vip_car_wash.start_washing();        // Start washing the current car
            cout << "Washing VIP car: " << currentVIPCar->getCarType();
        }

        // Regular Washer next
        if (VIPQueue.empty())
        {
            if (!car_wash.is_busy() && !carWashQueue.empty())
            {
                cout << "\nCar wash is not busy...\n";
                currentCar = carWashQueue.getFront(); // Grab the first car in the queue [not removing it from the queue]
                car_wash.start_washing();             // Start washing the current car
                cout << "Washing car: " << currentCar->getCarType();
            }
        }

        // Iterate the simulation by 1
        currentTime++;
        // sleep(1);
    }

    // To avoid dividing by zero
    if (carsWashed > 0)
        average_waiting_time = totalWaitingTime / carsWashed; // Getting the average waiting time
    else
        average_waiting_time = 0; // edge case of no washed cars

    if (vipCarsWashed > 0)
        vip_average_waiting_time = vipTotalWaitingTime / vipCarsWashed; // Getting the average waiting time
    else
        vip_average_waiting_time = 0; // edge case of no washed cars

    // Get the remaining number of cars in the car queue to get the total number of cars that were not washed
    carsNotWashed = carWashQueue.count();
    vipCarsNotWashed = VIPQueue.count();

    finishedCarsQueue.statistical_report(average_waiting_time, carsWashed, carsNotWashed); // Display a statiscal report about what happened throughout the simulation

    carWashQueue.makeEmpty();
    finishedCarsQueue.makeEmpty();
    VIPQueue.makeEmpty();
    for (auto *car : carsToBeDeleted)
    {
        delete car;
    }
}

// g++ -o output main.cpp Implementations/*.cpp Washing.cpp -std=c++17
// ./output