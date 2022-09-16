#pragma once 
#include "std_lib_facilities.h"

class Animal{
    protected:
        string name; 
        int age;
    public:
        Animal(string anmialName, int animalAge){name=anmialName; age= animalAge;};
        virtual ~Animal(){};
        virtual string toString();
};

class Dog : public Animal{
    public:
        Dog(string animalName, int animalAge):Animal{animalName, animalAge}{};
        string toString() override;
};

class Cat : public Animal{
    public:
        Cat(string animalName, int animalAge):Animal(animalName, animalAge){};
        string toString() override;
};

void testAnimal();