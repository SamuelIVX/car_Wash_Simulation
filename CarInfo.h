//CarInfo header file

#include<iostream>
#include<string>
#include<cstdlib>
#ifndef CAR_INFO
#define CAR_INFO

using namespace std;

class CarInfo{
    public:
        //Default constructor
        CarInfo();
        
        //Parameterized Construtor
        CarInfo(int a_t);

        //Getter Functions
        int getCarNum()const;

        string getCarType()const;

        string getTypeOfWash()const;

        int getArrivalTime()const;

        int getWater()const;

        int getSoap()const;

    private:
        int carNum;
        string carType;
        string typeOfWash;
        int arrivalTime;
        int water;
        int soap; 
};

#endif