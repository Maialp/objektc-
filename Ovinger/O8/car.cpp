#include "car.h"

bool Car::hasFreeSeats() const{
    if(freeSeats>0){
        return true;
    }
    else{
        return false;
    }
}

void Car::reserveFreeSeat(){
    freeSeats++;
}

bool Person::hasAvailableSeats() const {
    if(car!=nullptr){
        return car->hasFreeSeats();
    }
    else{
        return false;
    }
}
ostream& operator<<(ostream& os, const Person& person) {
    os << person.name << ", " << person.email << ", ";
    if (person.car!=nullptr){
        os << "has car";
    }
    return os; 
}