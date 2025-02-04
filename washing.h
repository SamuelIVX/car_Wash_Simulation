// File washing.h
//  CLASSES PROVIDED: bool_source, averager, washer.
//
//  CONSTRUCTOR for the bool_source class:
//  bool_source(double p = 0.5)
//  Precondition: 0 <= p <= 1.
//  Postcondition: The bool_source has been initialized so that p is the
//  approximate probability of returning true in any subsequent activation
//  of query( ).
//
//  CONSTANT MEMBER FUNCTION for the bool_source class:
//  bool query( ) const
//  Postcondition: The return value is either true or false, with the
//  probability of a true value being approximately p (from the constructor).
//
//  CONSTRUCTOR for the averager class:
//  averager( )
//  Postcondition: The averager has been initialized so that it
//  is ready to accept a sequence of numbers to average.
//
//  MODIFICATION MEMBER FUNCTION for the averager class:
//  void next_number(double value)
//  Postcondition: The averager has accepted value as the next
//  number in the sequence of numbers which it is averaging.
//
//  CONSTANT MEMBER FUNCTIONS for the averager class:
//  size_t how_many_numbers( ) const
//  Postcondition: The value returned is a count of how many
//  times next_number has been activated.
//  double average( ) const
//  Precondition: how_many_numbers > 0.
//  Postcondition: The value returned is the average of all the
//  numbers which have been given to the averager.
//
//  CONSTRUCTOR for the washer class:
//  washer(unsigned int s = 60)
//  Precondition: The value of s is the number of seconds needed for
//  the completion of one wash cycle.
//  Postcondition: The washer has been initialized so that all
//  other member functions may be used.
//
//  MODIFICATION MEMBER FUNCTIONS for the washer class:
//  void one_second( )
//  Postcondition: The washer has recorded (and simulated) the
//  passage of one more second of time.
//
//  void start_washing( )
//  Precondition: The washer is not busy.
//  Postcondition: The washer has started simulating one wash
//  cycle. Therefore, is_busy( ) will return true until
//  the required number of simulated seconds have occured.
//
//  CONSTANT MEMBER FUNCTIONS for the washer class:
//  bool is_busy( ) const
//  Postcondition: Return value is true if the washer is busy
//  (in a wash cycle); otherwise the return value is false.
//
//  VALUE SEMANTICS for the bool_source, averager, and washer classes:
//  Assignments and the copy constructor may be used with the three classes.

#include <iostream>
#include <string>
#ifndef WASHING_H
#define WASHING_H

class bool_source
{
public:
    // CONSTRUCTOR
    bool_source(double p = 0.5);

    // CONSTANT function
    bool query() const;

private:
    double probability; // Probability of query() returning true
};

class averager
{
public:
    // CONSTRUCTOR
    averager();

    // MODIFICATION function
    void next_number(double value);

    // CONSTANT functions
    std::size_t how_many_numbers() const
    {
        return count;
    }

    double average() const;

private:
    std::size_t count; // How many numbers have been given to the averager
    double sum;        // Sum of all the numbers given to the averager
};

class washer
{
public:
    // CONSTRUCTOR
    washer();

    // Setter
    void setWashingTime(unsigned int s);

    // MODIFICATION functions
    void one_second();

    void start_washing();

    // CONSTANT function
    bool is_busy() const
    {
        return (wash_time_left > 0);
    }

    int get_wash_time_left() const;

private:
    unsigned int seconds_for_wash; // Seconds for a single wash
    unsigned int wash_time_left;   // Seconds until washer no longer busy
};
#endif
