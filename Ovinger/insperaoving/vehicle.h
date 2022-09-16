#pragma once
#include "std_lib_facilities.h"

// Task a)
// Create an color enum here
enum class Color {blue, yellow, red, green};

// Task b) 
// Complete the Vehicle class as described in the task
class Vehicle {
    private:
        string name;
    protected: 
        Color color; 
        int speed; 
    public:
        Vehicle(string vehicleName,Color vehicleColor, int vehicleSpeed) : name{vehicleName}, color{vehicleColor}, speed{vehicleSpeed} {};
        virtual bool allowSpeed(); //Virutal for at den skal bli overskrevet at subklasse

};
// Task c)
// Create the Car class underneath as described in the task
class Car : public Vehicle{
    private:
        int numberOfWheels;
    public:
        //Kontruktør med medlemsinitialiseringsliste som kaller på konstruktøren til superklassen
        Car(string carName,Color carColor, int carSpeed, int numWheels): Vehicle{carName, carColor, carSpeed}, numberOfWheels{numWheels}{};
        void changeColor(Color newColor);   //implementert i cpp-fila
        bool allowSpeed();                  //implementert i cpp-fila

};
