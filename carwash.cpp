#include <iostream> // Provides cout
#include <cstdlib> // Provides EXIT_SUCCESS
#include "Que.h" //Provides queue
#include "washing.h" // Provides averager, bool_source, washer
#include "CarInfo.h" //The class I created
#include<string>
#include<unistd.h> //For the sleep function

using namespace std; 

//Prototype for car_wash_simulate
void car_wash_simulate(unsigned int wash_time, double arrival_prob, unsigned int total_time);

int main(){

    double time_to_wash, arrival_probability, total_time;

    //Getting user inputs
    cout << "Enter time it takes to wash a car: ";
    cin >> time_to_wash;

    cout << "Enter arrival probability (0 <= p <= 1): ";
    cin >> arrival_probability;
 
    cout << "Enter total time in seconds: ";
    cin >> total_time;

    //Displaying user inputs
    cout << "\nIt will take: " << time_to_wash << " secs to wash one car.\n"
         << "The probability of a customer arriving is: " << arrival_probability <<"\n"
         << "The simulation will run for a total of: " << total_time << " secs." << endl;

    //Starting the simulation
    car_wash_simulate(time_to_wash, arrival_probability, total_time);

    return 0;
}

//Function Definition for car_wash_simulate
void car_wash_simulate(unsigned int wash_time, double arrival_prob, unsigned int total_time) {
    //Create 2 queues of type CarInfo
    Que<CarInfo> carQueue, queue; 
    bool_source get_prob(arrival_prob);
    washer car_wash(wash_time);

    //Create 2 objects of type CarInfo
    CarInfo currentCar, temp;
    
    //Initializing and declaring 6 counter variables
    int carsWashed = 0, carsNotWashed = 0, currentTime = 0, waitTime = 0, average_waiting_time = 0, totalWaitingTime = 0;

    //Keep looping while the currentTime is less than the total simulation runtime
    while (currentTime < total_time) {
        // Check if a new car arrives, even if the washer is busy
        if (get_prob.query()) {
            cout << setfill('-') << setw(55) << endl;
            CarInfo newCar(currentTime); //A new car has arrived, construct a new CarInfo object

            cout << "\n\t\tTime: " << currentTime << " sec(s)" << endl;
            cout << "\nA '" << newCar.getCarType() << "' has arrived." <<  endl;
            
            carQueue.addQ(newCar); //Add the new car into the car queue

            //calculate the wait time for nth car in the queue
            waitTime = carQueue.wait_time(wash_time, car_wash);
            totalWaitingTime += waitTime;
            
            cout << "\nWait Time: " << waitTime << " sec(s)" << endl;

            cout << endl;
            carQueue.printQueue(); //Print out the queue each time a new car arrives!
        } else {
            cout << setfill('-') << setw(55) << endl;
            cout << "\n\t\tTime: " << currentTime << " sec(s)" << endl
                 << "\t\tno car arrived..." << endl;
        }

        // If the washer is busy, iterate the wash time by 1
        if (car_wash.is_busy()) {
            car_wash.one_second();
            // If wash time is done, process the finished car
            if (car_wash.get_wash_time_left() <= 0) {
                CarInfo finishedCar;
                carQueue.removeQ(finishedCar); //Removing the car from the queue and grabbing it

                queue.addQ(finishedCar); //Add the recently removed car into another queue for later on [statistical purpose]

                carsWashed++; //Iterate the amount of cars successfully washed

                cout << endl << finishedCar.getCarType() << " has been washed and dequeued.\n";

                carQueue.printQueue();//Print out the queue each time a car has been washed!
            }
        }
        
        // Start washing the next car if the washer is free and there’s a car in the queue
        if (!car_wash.is_busy() && !carQueue.empty()) {
            cout << "\nCar wash is not busy...\n";
            currentCar = carQueue.getFront(); //Grab the first car in the queue [not removing it from the queue]

            car_wash.start_washing(); //Start washing the current car

            cout << "Washing car: " << currentCar.getCarType();
        }

        // Iterate the simulation by 1
        currentTime++;
        sleep(1);
    }

    //To avoid dividing by zero
    if (carsWashed > 0) {
        average_waiting_time = totalWaitingTime / carsWashed; //Getting the average waiting time
    } else {
        average_waiting_time = 0; //edge case of no washed cars
    }
    
    carsNotWashed = carQueue.count(); //Get the remaining number of cars in the car queue to get the total number of cars that were not washed
    queue.statistical_report(average_waiting_time, carsWashed, carsNotWashed); //Display a statiscal report about what happened throughout the simulation
}// end of while loop
