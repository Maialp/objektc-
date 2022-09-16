#pragma once
#include <iostream>
#include <cmath>
#include <iomanip>
#include <utility>

using namespace std;

class Dummy {
    public:
        int *num;
        //Kontruktør
        Dummy() {               
            num = new int{0};
        }
        //Kopikonstruktør
        Dummy(const Dummy &other); 
        //Destruktør
        ~Dummy() { 
            delete num;
        }
        Dummy& operator=(Dummy rhs); //Operatoroverlastning av =
};

void dummyTest();