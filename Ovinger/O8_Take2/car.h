#pragma once
#include "std_lib_facilities.h"

class Car{
    unsigned int freeSeats;
public:
    Car(int fSeats);
    bool hasFreeSeats() const;
    void reserveFreeSeat();
};