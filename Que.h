#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include<iomanip>
#include "CarInfo.h"
#include "washing.h"
#ifndef Queue
#define Queue

using namespace std;

template<class ItemType>
struct NodeType{
    ItemType info;
    NodeType<ItemType> *next;

    NodeType() : next(nullptr) {}  // Default constructor
    NodeType(CarInfo c) : info(c), next(nullptr) {}
};

template<class ItemType>
class Que{
    public:
        Que();

        Que(const Que<ItemType> &otherQue);

        ~Que();

        void operator=(Que<ItemType> &otherQue);

        bool empty()const;

        bool full()const;

        void addQ(ItemType item);

        void removeQ(ItemType &item);
        
        void makeEmpty();

        //These are the functions I created for this function

        //Get the first car from the queue
        ItemType& getFront()const;

        //Print out the entire queue
        void printQueue()const;

        //Get the size of the queue
        int count()const;

        //Displays the information of each CarInfo object in a queue
        void statistical_report(double average_waiting_time, int cars_washed, int cars_not_washed);

        //Calculates the wait time for nth car in the queue
        int wait_time(unsigned int wash_time, washer car_wash);

    private:
        NodeType<ItemType> *qFront;
        NodeType<ItemType> *qRear;
};

template<class ItemType>
Que<ItemType>::Que(){
    qFront = nullptr;
    qRear = nullptr;
}

template<class ItemType>
Que<ItemType>::Que(const Que<ItemType> &otherQue){
    if(otherQue.qFront == 0){
        qFront = qRear = nullptr;
    } else {
        NodeType<ItemType> *tempPtr, *newPtr;
        tempPtr = otherQue.qFront;
        newPtr = new NodeType<ItemType>;
        newPtr->info = tempPtr->info;
        tempPtr = tempPtr->next;
        newPtr->next = qFront;
        qFront = newPtr;

        while(tempPtr != nullptr){
            newPtr->next = new NodeType<ItemType>;
            newPtr = newPtr->next;
            newPtr->info = tempPtr->info;
            tempPtr = tempPtr->next;
        }
        newPtr->next = nullptr;
        qRear = newPtr;
    }
}

template<class ItemType>
Que<ItemType>::~Que(){
    NodeType<ItemType> *tempPtr;
    while(qFront != nullptr){
        tempPtr = qFront;
        qFront = qFront->next;
        delete tempPtr;
    }
    qRear = nullptr;
}

template<class ItemType>
void Que<ItemType>::operator=(Que<ItemType> &otherQue){
    if(this != &otherQue){
        if(otherQue.empty()){
            makeEmpty();
        } else {
            NodeType<ItemType> *tempPtr, *newPtr;
            tempPtr = otherQue.qFront;
            newPtr = new NodeType<ItemType>;
            newPtr->info = tempPtr->info;
            tempPtr = tempPtr->next;
            newPtr->next = qFront;
            qFront = newPtr;

            while(tempPtr != nullptr){
                newPtr->next = new NodeType<ItemType>;
                newPtr = newPtr->next;
                newPtr->info = tempPtr->info;
                tempPtr = tempPtr->next;
            }
            newPtr->next = nullptr;
            qRear = newPtr;
        }
    } else {
        cerr << "QUES ARE THE SAME! " << endl;
    }
}

template<class ItemType>
bool Que<ItemType>::empty()const{
    return qFront == nullptr;
}

template<class ItemType>
bool Que<ItemType>::full()const{
    NodeType<ItemType> *tempPtr;
    tempPtr = new NodeType<ItemType>;

    if(tempPtr == nullptr){
        return true;
    } else {
        delete tempPtr;
        return false;
    }
}

template<class ItemType>
void Que<ItemType>::addQ(ItemType item){
    NodeType<ItemType> *tempPtr;
    tempPtr = new NodeType<ItemType>;
    tempPtr->info = item;
    tempPtr->next = nullptr;

    if(qFront == nullptr){
        qFront = tempPtr;
        qRear = qFront;
    } else {
        qRear->next = tempPtr;
        qRear = tempPtr;
    }
}

template<class ItemType>
void Que<ItemType>::removeQ(ItemType &item){
    NodeType<ItemType> *tempPtr;
    tempPtr = qFront;
    item = tempPtr->info;
    qFront = qFront->next;

    if(qFront == nullptr){
        delete tempPtr;
        qRear = nullptr;
    }
}
        
template<class ItemType>
void Que<ItemType>::makeEmpty(){
    NodeType<ItemType> *tempPtr;

    while(qFront != nullptr){
        tempPtr = qFront;
        qFront = qFront->next;
        delete tempPtr;
    }
    qRear = nullptr;
}

template<class ItemType>
ItemType& Que<ItemType>::getFront()const{ 
    return qFront->info; //Returns a CarInfo object from the queue
}


// Print the queue
template<class ItemType>
void Que<ItemType>::printQueue()const {
    if (empty()){
        cout << "The queue is empty.\n";
        return;
    }

    NodeType<ItemType> *current = qFront;
    cout << "Current queue: ";
    while (current != nullptr) {
        cout << "[" << current->info.getCarType() << "] ";
        current = current->next;
    }
}

// Count the number of cars in the queue
template<class ItemType>
int Que<ItemType>::count()const {
    int count = 0;
    NodeType<ItemType> *current = qFront;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

template<class ItemType>
void Que<ItemType>::statistical_report(double average_waiting_time, int cars_washed, int cars_not_washed){
    NodeType<CarInfo> *currentCar = qFront;
    
    //This is just for show to simulate wait time
    sleep(2);
    cout << "\nEnd of Car Wash Simulation..." << endl;
    sleep(2);
    cout << "Processing Final Report...\n";
    sleep(2);
    cout << endl << setfill(' ') << setw(80) << "Statistical Report\n";
    sleep(2);
    
    //Print out all of the private data members of CarInfo in the queue
    while(currentCar != nullptr){
        cout << "\nCar #: " << currentCar->info.getCarNum() << " | CarType: " << currentCar->info.getCarType() << " | ArrivalTime: " << currentCar->info.getArrivalTime() << 
        " | Type Of Wash: " << currentCar->info.getTypeOfWash() << " | Amount of Water Used: " << currentCar->info.getWater() << " gallons | Amount of Soap Used: " << currentCar->info.getSoap() << " ounces |" << endl;
        cout << setfill('-') << setw(143);

        currentCar = currentCar->next;
        sleep(2);
    }

    //Print out more statistical information
    cout << "\nA total of: " << cars_washed << " car(s) were washed!" << endl;
    sleep(2);
    cout << "A total of: " << cars_not_washed << " car(s) were not washed..." << endl;
    sleep(2);
    cout << "The average waiting time was: " << average_waiting_time << " secs" << endl;
}

template<class ItemType>
int Que<ItemType>::wait_time(unsigned int wash_time, washer car_wash){
    int waitTime = 0;

    //if the car wash is busy then: get the current cars wash time left and add it by
    // the amount of cars in the queue (NOT COUNTING THE CURRENT CAR) and multiply that by the wash time
    // the -1 at the end is to decrement the wash_time by 1 since that is how my program is structured in main
    // (car_wash.one_second is called AFTER I calculate the wait time for nth car in the queue)
    if(car_wash.is_busy()){
        waitTime += car_wash.get_wash_time_left() + (count()-1) * wash_time-1;
    } else {
        waitTime += count() * wash_time;
    }

    return waitTime;
}

#endif