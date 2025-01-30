#include <stdlib.h>
#include "Headers/Tesla.h"
#include "Headers/Vehicle.h"
#include <string>
#include <ctime>

using namespace std;

int main()
{
    srand(time(0));

    Vehicle *cars[10];
    cars[0] = new Tesla();
    cars[1] = new Tesla();
    cars[2] = new Tesla();
    cars[3] = new Tesla();

    for (int i = 0; i < 4; i++)
    {
        cout << "car: " << i << endl;
        cars[i]->display();
    }
    for (int i = 0; i < 4; i++)
    {
        delete cars[i];
    }

    return 0;
}

// g++ -o carwash test.cpp Implementations/Vehicle.cpp Implementations/Tesla.cpp -std=c++17