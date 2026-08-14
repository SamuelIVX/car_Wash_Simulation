/**
 * @file Que.h
 * @brief Header-only linked-node queue template used for regular, VIP, and finished cars.
 *
 * Provides enqueue/dequeue plus simulation helpers (printQueue, wait_time, statistical_report).
 * Instantiated primarily as Que<Vehicle *>.
 */

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <iomanip>
#include "washing.h"
#ifndef Queue
#define Queue

using namespace std;

/**
 * @brief Singly linked list node holding one queue item.
 * @tparam ItemType Payload type (typically Vehicle *).
 */
template <class ItemType>
struct NodeType
{
    ItemType info;
    NodeType<ItemType> *next;

    /** @brief Construct an empty node with a null next pointer. */
    NodeType() : next(nullptr) {}
};

/**
 * @brief Linked FIFO queue with car-wash simulation helpers.
 * @tparam ItemType Element type stored in each node.
 */
template <class ItemType>
class Que
{
public:
    /** @brief Construct an empty queue. */
    Que();

    /**
     * @brief Copy queue nodes and stored payload values from @p otherQue.
     * @note For Que<Vehicle *>, pointed-to Vehicle objects are not cloned.
     * @param otherQue Queue to duplicate.
     */
    Que(const Que<ItemType> &otherQue);

    /** @brief Destroy the queue and free all nodes (not the pointed-to Vehicles). */
    ~Que();

    /**
     * @brief Replace this queue with copied nodes and payload values.
     * @note For Que<Vehicle *>, pointed-to Vehicle objects are not cloned.
     * @param otherQue Source queue; no-op if assigning to self.
     */
    void operator=(Que<ItemType> &otherQue);

    /**
     * @brief Whether the queue has no elements.
     * @return True if empty.
     */
    bool empty() const;

    /**
     * @brief Probe whether a new node can be allocated.
     * @return True if allocation failed (queue considered full).
     */
    bool full() const;

    /**
     * @brief Enqueue @p item at the rear.
     * @param item Value to store (e.g. Vehicle *).
     * @code
     * Que<Vehicle *> q;
     * Vehicle *v = Vehicle::createRandomCar(0);
     * q.addQ(v);  // caller still owns v; queue does not delete it
     * @endcode
     */
    void addQ(ItemType item);

    /**
     * @brief Dequeue the front element into @p item.
     * @param[out] item Receives the former front payload.
     * @pre !empty().
     * @code
     * Vehicle *front = nullptr;
     * q.removeQ(front);
     * @endcode
     */
    void removeQ(ItemType &item);

    /** @brief Remove all nodes without deleting pointed-to Vehicle objects. */
    void makeEmpty();

    /**
     * @brief Reference to the front payload without removing it.
     * @return Mutable reference to front info.
     * @pre !empty().
     */
    ItemType &getFront() const;

    /** @brief Print brand labels for every vehicle currently in the queue. */
    void printQueue() const;

    /**
     * @brief How many elements are in the queue.
     * @return Number of nodes currently in the queue.
     */
    int count() const;

    /**
     * @brief Print end-of-run stats and per-car details from this (finished) queue.
     * @param average_waiting_time Mean wait among washed cars.
     * @param cars_washed Count successfully washed.
     * @param cars_not_washed Count still waiting when time expired.
     * @code
     * finished.statistical_report(12.5, 8, 2);
     * @endcode
     */
    void statistical_report(double average_waiting_time, int cars_washed, int cars_not_washed);

    /**
     * @brief Estimate wait for a newly arrived car given current bay state.
     * @param wash_time This car's wash duration in seconds.
     * @param car_wash Wash bay whose remaining time factors into the estimate.
     * @return Estimated wait in simulated seconds.
     *
     * Subtracts 1 when the bay is busy because main advances the bay after this call.
     * @code
     * int wait = queue.wait_time(car->getWashTime(), bay);
     * @endcode
     */
    int wait_time(unsigned int wash_time, washer &car_wash);

private:
    NodeType<ItemType> *qFront;
    NodeType<ItemType> *qRear;
};

template <class ItemType>
Que<ItemType>::Que()
{
    qFront = nullptr;
    qRear = nullptr;
}

template <class ItemType>
Que<ItemType>::Que(const Que<ItemType> &otherQue)
{
    if (otherQue.qFront == 0)
    {
        qFront = qRear = nullptr;
    }
    else
    {
        NodeType<ItemType> *tempPtr, *newPtr;
        tempPtr = otherQue.qFront;
        newPtr = new NodeType<ItemType>;
        newPtr->info = tempPtr->info;
        tempPtr = tempPtr->next;
        newPtr->next = qFront;
        qFront = newPtr;

        while (tempPtr != nullptr)
        {
            newPtr->next = new NodeType<ItemType>;
            newPtr = newPtr->next;
            newPtr->info = tempPtr->info;
            tempPtr = tempPtr->next;
        }
        newPtr->next = nullptr;
        qRear = newPtr;
    }
}

template <class ItemType>
Que<ItemType>::~Que()
{
    NodeType<ItemType> *tempPtr;
    while (qFront != nullptr)
    {
        tempPtr = qFront;
        qFront = qFront->next;
        delete tempPtr;
    }
    qRear = nullptr;
}

template <class ItemType>
void Que<ItemType>::operator=(Que<ItemType> &otherQue)
{
    if (this != &otherQue)
    {
        if (otherQue.empty())
        {
            makeEmpty();
        }
        else
        {
            NodeType<ItemType> *tempPtr, *newPtr;
            tempPtr = otherQue.qFront;
            newPtr = new NodeType<ItemType>;
            newPtr->info = tempPtr->info;
            tempPtr = tempPtr->next;
            newPtr->next = qFront;
            qFront = newPtr;

            while (tempPtr != nullptr)
            {
                newPtr->next = new NodeType<ItemType>;
                newPtr = newPtr->next;
                newPtr->info = tempPtr->info;
                tempPtr = tempPtr->next;
            }
            newPtr->next = nullptr;
            qRear = newPtr;
        }
    }
    else
    {
        cerr << "QUES ARE THE SAME! " << endl;
    }
}

template <class ItemType>
bool Que<ItemType>::empty() const
{
    return qFront == nullptr;
}

template <class ItemType>
bool Que<ItemType>::full() const
{
    NodeType<ItemType> *tempPtr;
    tempPtr = new NodeType<ItemType>;

    if (tempPtr == nullptr)
    {
        return true;
    }
    else
    {
        delete tempPtr;
        return false;
    }
}

template <class ItemType>
void Que<ItemType>::addQ(ItemType item)
{
    NodeType<ItemType> *tempPtr;
    tempPtr = new NodeType<ItemType>;
    tempPtr->info = item;
    tempPtr->next = nullptr;

    if (qFront == nullptr)
    {
        qFront = tempPtr;
        qRear = qFront;
    }
    else
    {
        qRear->next = tempPtr;
        qRear = tempPtr;
    }
}

template <class ItemType>
void Que<ItemType>::removeQ(ItemType &item)
{
    NodeType<ItemType> *tempPtr;
    tempPtr = qFront;
    item = tempPtr->info;
    qFront = qFront->next;

    if (qFront == nullptr)
    {
        delete tempPtr;
        qRear = nullptr;
    }
}

template <class ItemType>
void Que<ItemType>::makeEmpty()
{
    NodeType<ItemType> *tempPtr;

    while (qFront != nullptr)
    {
        tempPtr = qFront;
        qFront = qFront->next;
        delete tempPtr; // Deletes the node
    }
    qRear = nullptr;
}

template <class ItemType>
ItemType &Que<ItemType>::getFront() const
{
    return qFront->info; // Front payload (e.g. Vehicle *); does not dequeue
}

// Print the queue
template <class ItemType>
void Que<ItemType>::printQueue() const
{
    NodeType<ItemType> *current = qFront;
    cout << "Current queue: ";
    while (current != nullptr)
    {
        cout << "[" << current->info->getCarType() << "] ";
        current = current->next;
    }
}

// Count the number of cars in the queue
template <class ItemType>
int Que<ItemType>::count() const
{
    int count = 0;
    NodeType<ItemType> *current = qFront;
    while (current != nullptr)
    {
        count++;
        current = current->next;
    }
    return count;
}

template <class ItemType>
void Que<ItemType>::statistical_report(double average_waiting_time, int cars_washed, int cars_not_washed)
{
    NodeType<ItemType> *currentCar = qFront;

    cout << "\nEnd of Car Wash Simulation..." << endl;
    cout << "Processing Final Report...\n";
    cout << endl
         << setfill(' ') << setw(80) << "Statistical Report\n";
    // sleep(2);

    // Print out all of the private data members of Vehicle in the queue
    while (currentCar != nullptr)
    {
        cout << "\nCar License Plate: " << currentCar->info->getLicensePlate() << " | CarType: " << currentCar->info->getCarType() << " | VIP: " << (currentCar->info->getIsVIP() == 1 ? "True" : "False") << " | ArrivalTime: " << currentCar->info->getArrivalTime() << " | Type Of Wash: " << currentCar->info->getTypeOfWash() << " | Amount of Water Used: " << currentCar->info->getWaterUsage() << " gallons | Amount of Soap Used: " << currentCar->info->getSoapUsage() << " ounces |" << endl;
        cout << setfill('-') << setw(180);

        currentCar = currentCar->next;
        // sleep(2);
    }

    // Print out more statistical information
    cout << "\nA total of: " << cars_washed << " car(s) were washed!" << endl;
    // sleep(2);
    cout << "A total of: " << cars_not_washed << " car(s) were not washed..." << endl;
    // sleep(2);
    cout << "The average waiting time was: " << average_waiting_time << " secs" << endl;
}

template <class ItemType>
int Que<ItemType>::wait_time(unsigned int wash_time, washer &car_wash)
{
    int waitTime = 0;

    // if the car wash is busy then: get the current cars wash time left and add it by
    //  the amount of cars in the queue (NOT COUNTING THE CURRENT CAR) and multiply that by the wash time
    //  the -1 at the end is to decrement the wash_time by 1 since that is how my program is structured in main
    //  (car_wash.one_second is called AFTER I calculate the wait time for nth car in the queue)
    if (car_wash.is_busy())
    {
        waitTime += car_wash.get_wash_time_left() + (count() - 1) * wash_time - 1;
    }
    else
    {
        waitTime += count() * wash_time;
    }

    return waitTime;
}

#endif