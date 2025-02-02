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
void car_wash_simulate(unsigned int wash_time, double arrival_prob, unsigned int total_time);

int main()
{
    srand(time(0));

    // double time_to_wash, arrival_probability, total_time;

    // // Getting user inputs
    // cout << "Enter time it takes to wash a car: ";
    // cin >> time_to_wash;

    // cout << "Enter arrival probability (0 <= p <= 1): ";
    // cin >> arrival_probability;

    // cout << "Enter total time in seconds: ";
    // cin >> total_time;

    // // Displaying user inputs
    // cout << "\nIt will take: " << time_to_wash << " secs to wash one car.\n"
    //      << "The probability of a customer arriving is: " << arrival_probability << "\n"
    //      << "The simulation will run for a total of: " << total_time << " secs." << endl;

    // // Starting the simulation
    // car_wash_simulate(time_to_wash, arrival_probability, total_time);

    std::vector<Vehicle *> cars;
    for (int i = 0; i < 10; i++)
    {
        Vehicle *car = Vehicle::createRandomCar(i);
        cars.push_back(car);
        cout << "car: " << i + 1 << endl;
        car->display();
    }

    for (auto &car : cars)
    {
        delete car;
    }

    return 0;
}

// g++ -o carwash test.cpp Implementations/*.cpp -std=c++17
// ./carwash

// Function Definition for car_wash_simulate
void car_wash_simulate(unsigned int wash_time, double arrival_prob, unsigned int total_time)
{
}
