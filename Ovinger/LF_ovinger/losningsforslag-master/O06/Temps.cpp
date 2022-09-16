#include "Temps.h"
#include "TempsDrawer.h"

istream &operator>>(istream &is, Temps &t)
{
	return is >> t.max >> t.min;
}

vector<Temps> readTemps(const string &filename)
{
	ifstream ifs{filename};
	if (!ifs)
	{
		error("Couldn't open file: ", filename);
	}

	vector<Temps> temps;
	// For-løkken holder på så lenge vi får lest inn Temps-objekter
	for (Temps t; ifs >> t;)
	{
		temps.push_back(t);
	}
	return temps;
}

void tempStats(const vector<Temps>& temps) {
	int min_index = 0;
	int max_index = 0;
	for (size_t i = 0; i < temps.size(); i++) {
		if (temps[i].min < temps[min_index].min) {
			min_index = i;
		}
		if (temps[i].max > temps[max_index].max) {
			max_index = i;
		}
	}

	cout << "The day with the lowest temperature was day " << min_index << " with a temperature of " << temps[min_index].min << " degrees\n";
	cout << "The day with the highest temperature was day " << max_index << " with a temperature of " << temps[max_index].max << " degrees\n";
}
