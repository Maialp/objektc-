#pragma once
#include "std_lib_facilities.h"
#include "file.h"
#include "emnekatalog.h"

class Temps{
    private:
    public:
        double max;
        double min;

};
istream& operator>>(istream& is, Temps& t);
vector<Temps> readTemps(string fileName);
void tempStats(vector<Temps> tempVec);