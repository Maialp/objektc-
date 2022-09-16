#pragma once
#include "std_lib_facilities.h"

// Deklarering av enumen Color. 
enum class Color{blue, yellow, red, green};


// Deklarasjon av vehicle klassen. 
class Vehicle {
private:
string name;

// Legg merke til at color og speed er protected for å gjøre dem tilgjengelig ved arv
protected:
Color color;
double speed;

// Funksjonene som er public er tilgjengelig uansett
public:
Vehicle(string name, int speed, Color c);
virtual bool allowedSpeed();

};

// Car klassen. Denne arver fra Vehicle
class Car : public Vehicle {
private:
unsigned int numberOfWheels;

public:
Car(string name, Color c, int speed, int numWheels);
void changeColor(Color newColor);
bool allowedSpeed() override;
};