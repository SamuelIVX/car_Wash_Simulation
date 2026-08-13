/**
 * @file washing.h
 * @brief Discrete-event car-wash helpers: arrival probability, running averages, and wash-bay state.
 *
 * Provides bool_source, averager, and washer used by the main simulation loop.
 */

#include <iostream>
#include <string>
#ifndef WASHING_H
#define WASHING_H

/**
 * @brief Bernoulli trial source for random car arrivals.
 */
class bool_source
{
public:
    /**
     * @brief Construct a source that returns true with approximate probability @p p.
     * @param p Probability in [0, 1] that query() returns true.
     * @pre 0 <= p <= 1.
     */
    bool_source(double p = 0.5);

    /**
     * @brief Draw one random true/false outcome using @c probability.
     * @return True with approximate probability @c probability; otherwise false.
     */
    bool query() const;

private:
    double probability; // Probability of query() returning true
};

/**
 * @brief Online accumulator for a sequence of numeric samples.
 */
class averager
{
public:
    /**
     * @brief Construct an empty averager ready to accept samples.
     */
    averager();

    /**
     * @brief Append @p value to the running sum/count.
     * @param value Next sample in the sequence being averaged.
     */
    void next_number(double value);

    /**
     * @brief How many samples have been recorded.
     * @return Count of next_number activations.
     */
    std::size_t how_many_numbers() const
    {
        return count;
    }

    /**
     * @brief Mean of all recorded samples.
     * @return Average of values passed to next_number.
     * @pre how_many_numbers() > 0.
     */
    double average() const;

private:
    std::size_t count; // How many numbers have been given to the averager
    double sum;        // Sum of all the numbers given to the averager
};

/**
 * @brief Single wash bay that tracks remaining seconds in the current cycle.
 *
 * Duration is not fixed at construction; call setWashingTime() before start_washing().
 */
class washer
{
public:
    /**
     * @brief Construct an idle washer with no wash in progress.
     * Call setWashingTime() to configure cycle length before starting a wash.
     */
    washer();

    /**
     * @brief Set the length of the next wash cycle in simulated seconds.
     * @param s Positive number of seconds required to complete one wash.
     * @pre s > 0.
     */
    void setWashingTime(unsigned int s);

    /**
     * @brief Advance the simulation by one second; decrement remaining wash time if busy.
     */
    void one_second();

    /**
     * @brief Begin a wash cycle using the duration from setWashingTime().
     * @pre is_busy() is false and a positive wash duration is configured.
     * @post is_busy() is true until the configured seconds have elapsed via one_second().
     */
    void start_washing();

    /**
     * @brief Whether a wash cycle is currently in progress.
     * @return True if wash_time_left > 0.
     */
    bool is_busy() const
    {
        return (wash_time_left > 0);
    }

    /**
     * @brief Seconds remaining in the current wash cycle.
     * @return Remaining wash time; 0 when idle.
     */
    int get_wash_time_left() const;

private:
    unsigned int seconds_for_wash; // Seconds for a single wash
    unsigned int wash_time_left;   // Seconds until washer no longer busy
};
#endif
