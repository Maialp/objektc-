#pragma once
#include "utilities.h"
#include <FL/Fl_Widget.H>
#include "Simple_window.h"    
#include "Graph.h" 
#include <tuple>
#include <FL/Fl.H>

class Vehicle : Fl_Widget{
    private:
        std::pair<double,double> move;
    protected:
        virtual std::pair<double,double> steer() const = 0;
        virtual void drawBody() const = 0;
        PhysicsState state;
    public:
        Vehicle(double x, double y, double angle);
        void draw() final;
};

class PlayerVehicle : Vehicle{
    private: 
        std::pair<double,double> steer() const;
    public:
        PlayerVehicle(double x, double y, double angle);
        void drawBody() const;
};