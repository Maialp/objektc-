#pragma once
#include "std_lib_facilities.h"

struct Temps {
	double max;
	double min;
};

istream& operator>>(istream& is, Temps& t);

vector<Temps> readTemps(const string& filename);
void tempStats(const vector<Temps>& temps);
