#include "vehicle.h"

// Implement all the necessary functions as described in the task here.

bool Vehicle::allowSpeed(){
    if(speed <= 1000){ 
        return true;  //returnerer true om bilen kjører under 1000 km/t 
    }
    else{
        return false; // returnerer false om bilen kjører over 1000 km/t
}

void Car::changeColor(Color newColor){
    color{newColor};
}

bool Car::allowSpeed(){
    if(speed <= 100){ 
        return true;  //returnerer true om bilen kjører under 100 km/t 
    }
    else{
        return false; // returnerer false om bilen kjører over 100 km/t
}