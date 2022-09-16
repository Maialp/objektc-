#include "person.h"

bool Person::hasAvailableSeats() const{
    if(car!=nullptr){
        return car->hasFreeSeats();
    }
    else{
        return false;
    }
}

ostream& operator<<(ostream& os, Person p) {
    os<<"Name: "<<p.getName()<< endl;
    os<<"Email: "<<p.getEmail()<<endl;
    if(p.hasAvailableSeats()){
        os<<"Available seats\n";
    }
    else{
        os<<"No available seats\n";
    }
    return os;
}