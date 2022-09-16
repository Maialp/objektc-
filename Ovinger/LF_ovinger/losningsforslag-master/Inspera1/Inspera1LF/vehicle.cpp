#include "vehicle.h"

// Lager en konstruktør som initialiserer alle variablene sine med initialiseringsliste.
Vehicle::Vehicle(string name, int speed, Color c):name{name}, color{c}, speed{speed}{

}

// Funksjonen sjekker om kjøretøyet kjører i tillatt hastighet
bool Vehicle::allowedSpeed(){
    return speed < 1000;
}

// Funksjonen overskriver allowedSpeed fra Vehicle klassen og sjekker om en bil kjører i tillatt hastighet
bool Car::allowedSpeed(){
    return speed < 100;
}


// Konstruktøren for Car klassen. Legg merke til at den først kaller 
//vvehicle konstruktøren og så initialiserer egne medlemsvariabler
Car::Car(string name, Color c, int speed, int numWheels):Vehicle{name,speed,c}, numberOfWheels{numWheels}{

}

// Funksjonen endrer farge på bilen.
void Car::changeColor(Color newColor){
    color = newColor;
}

