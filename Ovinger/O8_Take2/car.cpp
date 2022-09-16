#include "car.h"

bool Car::hasFreeSeats() const {
    if (freeSeats>0){
        return true;
    }
    else {
        return false;
    }
}

void Car::reserveFreeSeat(){
    freeSeats++;
}

Car::Car(int fSeats){
    freeSeats = fSeats;
}