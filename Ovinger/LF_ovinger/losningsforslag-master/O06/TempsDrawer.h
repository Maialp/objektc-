#pragma once

/* Basert på PPP 15.6 Graphing data. */
#include "Graph.h"
#include "Simple_window.h"
#include "Temps.h"

constexpr int xmax = 1200;
constexpr int ymax = 650;
constexpr int xoffset = 80;
constexpr int yoffset = 40;
constexpr int xspace = 40;
constexpr int yspace = 40;
constexpr int xlength = xmax - xoffset - xspace;
constexpr int ylength = ymax - yoffset - yspace;
constexpr int n_months = 12;
constexpr int degrees = 60;

// Skalering se PPP side 543.
class Scale
// Dataverdi til koordinat konvertering
{
	int cbase; // Koordinatbase
	int vbase; // Verdibase
	double scale;

public:
	Scale(int b, int vb, double s) : cbase(b), vbase(vb), scale(s)
	{}
	int calculatePoint(int v) const
	{
		return static_cast<int>(cbase + (v - vbase) * scale);
	}
	int calculatePoint(double v) const
	{
		return static_cast<int>(cbase + (v - vbase) * scale);
	}
};

void drawMaxMin(const vector<Temps>& temps);
