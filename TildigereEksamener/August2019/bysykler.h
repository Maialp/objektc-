#pragma once 
#include "std_lib_facilities.h"
#include "Point.h"

struct Location{
    string name;
    Graph_lib::Point p;
    Location(string str, Graph_lib::Point pt);
};

//3b)
class Bikestation{
    private:
        Location loc;
        unsigned int capacity;
        unsigned int bikes;
        vector<Shape> display;

    public: 
        Bikestation(Location where, unsigned int cap, unsigned int numBikes);
        int getBikes();
        void setBikes(unsigned int numBikes);
        inline string getName(){return loc.name;}
        string status();

};