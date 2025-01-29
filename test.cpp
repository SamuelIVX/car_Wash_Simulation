#include <stdlib.h>
#include "VehicleHeaders/Tesla.h"
#include "VehicleHeaders/Vehicle.h"
#include <string>

using namespace std;

int main()
{

    Vehicle *cars[10];
    cars[0] = new Tesla(1, 2, "fast", "Tesla", "356432", 3, false, true, 12, 23, true, true, 23);
    cars[1] = new Tesla(2, 3, "slow", "Sidan", "24565", 4, true, true, 35, 2353, false, false, 23);
    cars[2] = new Tesla(3, 4, "premium", "Ford", "98754", 5, false, true, 342, 763, true, true, 23);
    cars[3] = new Tesla(4, 5, "careful", "Lambo", "i35954", 6, true, true, 135, 353, false, false, 23);

    for (int i = 0; i < 4; i++)
    {
        cout << "car: " << i << endl
             << endl;
        cars[i]->display();
    }
    for (int i = 0; i < 4; i++)
    {
        delete cars[i];
    }

    return 0;
}

// g++ -o carwash test.cpp VehicleImplementations/VehicleHeaders/Vehicle.cpp VehicleImplementations/VehicleHeaders/Tesla.cpp -std=c++17