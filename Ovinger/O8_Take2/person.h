#pragma once
#include "car.h"

class Person{
    string name;
    string email;
    Car* car;
public:
    Person(string name, string email, Car* car = nullptr) 
                : name{name}, email{email}, car{car} {}
    string getEmail() const {return email;}
    string getName() const {return name;}
    void setEmail(string mail) {email=mail;}
    bool hasAvailableSeats() const;
};

ostream& operator<<(ostream& os, Person p);