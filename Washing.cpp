/**
 * @file Washing.cpp
 * @brief Implementations of bool_source, averager, and washer for the car-wash simulation.
 *
 * Invariants:
 * - bool_source::probability is the approximate P(query() == true).
 * - averager::count / sum track how many samples and their total.
 * - washer::seconds_for_wash is the configured cycle length; wash_time_left is 0 when idle.
 */

#include <cassert> // Provides assert
#include <cstdlib> // Provides rand, RAND_MAX, size_t
#include <iomanip>
#include "washing.h" // Provides bool_source, averager, washer definitions
#include "Que.h"     //Provides queue

using namespace std;

bool_source::bool_source(double p)
{
    // Library facilities used: cassert
    assert(p >= 0);
    assert(p <= 1);
    probability = p;
}

bool bool_source::query() const
{
    // Library facilities used: cstdlib
    return (rand() < probability * RAND_MAX);
}

averager::averager()
{
    count = 0;
    sum = 0;
}

void averager::next_number(double value)
{
    ++count;
    sum += value;
}

double averager::average() const
{
    // Library facilities used: cassert
    assert(how_many_numbers() > 0);
    return sum / count;
}

washer::washer()
{
    wash_time_left = 0;
}

void washer::setWashingTime(unsigned int s)
{
    seconds_for_wash = s;
}

void washer::one_second()
{
    if (is_busy())
        --wash_time_left;
}

void washer::start_washing()
{
    // Library facilities used: cassert
    assert(!is_busy());
    wash_time_left = seconds_for_wash;
}

int washer::get_wash_time_left() const
{
    return wash_time_left;
}
