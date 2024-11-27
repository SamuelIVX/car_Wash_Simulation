//CarInfo Implementation File

#include "CarInfo.h"
#include<iostream>
#include<string>

using namespace std;

//Default Constructor
CarInfo::CarInfo(){
    carType = typeOfWash = "none";
    carNum = water = soap = arrivalTime = 0; 
}
        
//Parameterized Constructor
CarInfo::CarInfo(int a_t){
    int randomNum = rand() % 5 + 1;
    carNum++;
    arrivalTime = a_t;
    water = soap = 0;
    
    switch(randomNum){
        case 1:
            carType = "mini";
            break;
        case 2:
            carType = "regular";
            break;
        case 3:
            carType = "mini_van";
            break;
        case 4:
            carType = "van";
            break;
        case 5:
            carType = "truck";
            break;
    }
    randomNum = rand() % 3 + 1;
    switch(randomNum){
        case 1:
            typeOfWash = "hand";
            water += 2.5;
            soap += 1.2;
            break;
        case 2:
            typeOfWash = "automatic";
            water += 4;
            soap += 2;
            break;
        case 3:
            typeOfWash = "premium";
            water += 5;
            soap += 3.25;
            break;
        }
}

//All getter function definitions
int CarInfo::getCarNum()const{
    return carNum;
}

string CarInfo::getCarType()const{
    return carType;
}

string CarInfo::getTypeOfWash()const{
    return typeOfWash;
}

int CarInfo::getArrivalTime()const{
    return arrivalTime;
}

int CarInfo::getWater()const{
    return water;
}

int CarInfo::getSoap()const{
    return soap;
}