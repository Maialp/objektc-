#pragma once 
#include "std_lib_facilities.h"

class Car{
    private:
        int freeSeats;
    public:
        Car(int numFreeSeats) : freeSeats{numFreeSeats} {} 
        bool hasFreeSeats() const;
        void reserveFreeSeat();

};

class Person{
    private:
        string name;
        string email;
        Car* car; 
    public:
        Person(string persName, string persEmail, Car* persCar = nullptr) : name{persName}, email{persEmail}, car{persCar}{}
        string getName() const {return name;}
        string getEmail() const {return email;}
        void setEmail(string persEmail) {email = persEmail;}
        bool hasAvailableSeats() const;
        
        friend ostream& operator<<(ostream& os, const Person& person);
};