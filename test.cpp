#include <stdlib.h>
#include "Headers/Vehicle.h"
#include "Headers/Tesla.h"
#include "Headers/Volkswagon.h"
#include "Headers/Toyota.h"
#include "Headers/Nissan.h"
#include "Headers/Lamborghini.h"
#include <string>
#include <ctime>

using namespace std;

int main()
{
    srand(time(0));

    Vehicle *cars[10];
    cars[0] = new Tesla();
    cars[1] = new Volkswagon();
    cars[2] = new Toyota();
    cars[3] = new Nissan();
    cars[4] = new Lamborghini();

    for (int i = 0; i < 5; i++)
    {
        cout << "car: " << i + 1 << endl;
        cars[i]->display();
    }
    for (int i = 0; i < 5; i++)
    {
        delete cars[i];
    }

    return 0;
}

// g++ -o carwash test.cpp Implementations/*.cpp -std=c++17
// ./carwash
