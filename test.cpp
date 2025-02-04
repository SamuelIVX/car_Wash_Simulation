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

    // Getting user inputs
    // cout << "Enter time it takes to wash a car: ";
    // cin >> time_to_wash;

    cout << "Enter arrival probability (0 <= p <= 1): ";
    cin >> arrival_probability;

    cout << "Enter total time in seconds: ";
    cin >> total_time;

    // Starting the simulation
    car_wash_simulate(arrival_probability, total_time);

    // Que<Vehicle *> carWashQueue;
    // for (int i = 0; i < 10; i++)
    // {
    //     Vehicle *car = Vehicle::createRandomCar(i + 1);
    //     carWashQueue.addQ(car);
    //     cout << "car: " << i + 1 << endl;
    //     car->display();
    // }
    // carWashQueue.makeEmpty();

    return 0;
}

// g++ -o outut carwash.cpp Implementations/*.cpp Washing.cpp -std=c++17
// ./carwash

// Function Definition for car_wash_simulate
void car_wash_simulate(double arrival_prob, unsigned int total_time)
{
    Que<Vehicle *> carWashQueue, finishedCarsQueue;
    vector<Vehicle *> carsToBeDeleted;
    bool_source get_prob(arrival_prob);
    washer car_wash;

    Vehicle *currentCar;
    Vehicle *temp;

    // Initializing and declaring 6 counter variables
    int carsWashed = 0, carsNotWashed = 0, currentTime = 0, waitTime = 0, average_waiting_time = 0, totalWaitingTime = 0;

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

            carWashQueue.addQ(car);         // Add the new car into the car queue
            carsToBeDeleted.push_back(car); // Delete the dynamically allocated Vehicle* objects after the simulation has ended

            // calculate the wait time for nth car in the queue
            car_wash.setWashingTime(car->getWashTime());
            waitTime = carWashQueue.wait_time(car->getWashTime(), car_wash);
            totalWaitingTime += waitTime;

            cout << "\nWait Time: " << waitTime << " sec(s)" << endl;

            cout << endl;
            carWashQueue.printQueue(); // Print out the queue each time a new car arrives!
        }
        else
        {
            cout << setfill('-') << setw(55) << endl;
            cout << "\n\t\tTime: " << currentTime << " sec(s)" << endl
                 << "\t\tno car arrived..." << endl;
        }

        // If the washer is busy, iterate the wash time by 1
        if (car_wash.is_busy())
        {
            car_wash.one_second();
            // If wash time is done, process the finished car
            if (car_wash.get_wash_time_left() <= 0)
            {
                Vehicle *finishedCar;
                carWashQueue.removeQ(finishedCar); // Removing the car from the queue and grabbing it

                finishedCarsQueue.addQ(finishedCar); // Add the recently removed car into another queue for later on [statistical purpose]

                carsWashed++; // Iterate the amount of cars successfully washed

                cout << endl
                     << finishedCar->getCarType() << " has been washed and dequeued.\n";

                carWashQueue.printQueue(); // Print out the queue each time a car has been washed!
            }
        }

        // Start washing the next car if the washer is free and there’s a car in the queue
        if (!car_wash.is_busy() && !carWashQueue.empty())
        {
            cout << "\nCar wash is not busy...\n";
            currentCar = carWashQueue.getFront(); // Grab the first car in the queue [not removing it from the queue]

            car_wash.start_washing(); // Start washing the current car

            cout << "Washing car: " << currentCar->getCarType();
        }

        // Iterate the simulation by 1
        currentTime++;
        // sleep(1);
    }

    // To avoid dividing by zero
    if (carsWashed > 0)
    {
        average_waiting_time = totalWaitingTime / carsWashed; // Getting the average waiting time
    }
    else
    {
        average_waiting_time = 0; // edge case of no washed cars
    }

    carsNotWashed = carWashQueue.count();                                                  // Get the remaining number of cars in the car queue to get the total number of cars that were not washed
    finishedCarsQueue.statistical_report(average_waiting_time, carsWashed, carsNotWashed); // Display a statiscal report about what happened throughout the simulation
    carWashQueue.makeEmpty();
    finishedCarsQueue.makeEmpty();
    for (auto *car : carsToBeDeleted)
    {
        delete car;
    }
}
