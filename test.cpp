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

    Vehicle *cars[10];
    cars[0] = new Tesla(1);
    cars[1] = new Volkswagon(2);
    cars[2] = new Toyota(3);
    cars[3] = new Nissan(4);
    cars[4] = new Lamborghini(5);
    cars[5] = new Jeep(6);
    cars[6] = new Hellcat(7);
    cars[7] = new Ford(8);
    cars[8] = new Chevrolet(9);
    cars[9] = new BMW(10);

    for (int i = 0; i < 10; i++)
    {
        cout << "car: " << i + 1 << endl;
        cars[i]->display();
    }
    for (int i = 0; i < 10; i++)
    {
        delete cars[i];
    }

    return 0;
}

// g++ -o carwash test.cpp Implementations/*.cpp -std=c++17
// ./carwash

// Function Definition for car_wash_simulate
void car_wash_simulate(unsigned int wash_time, double arrival_prob, unsigned int total_time)
{
}
