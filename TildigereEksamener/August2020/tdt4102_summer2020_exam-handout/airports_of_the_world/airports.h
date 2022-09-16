/** airport.h

   This file is part of the handout for the TDT4102 summer 2020 exam.


   This file contains the data definition for the internal
   representation of an airport in the program.

**/

#ifndef _AIRPORTS_H
#define _AIRPORTS_H

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "Graph.h"
#include "Point.h"

#include "util.h"

using namespace std;
using namespace Graph_lib;

// Class for holding a single
class Airport : public Circle {
public:
  // The class fields holding airport information
  const string name;
  const string city;
  const string country;

  // The three letter IATA code of the airport (e.g. OSL for Oslo Gardemoen)
  const string code;

  const double latitude;
  const double longtitude;

  // The width of the plotted map in pixels
  const int map_w;
  // The height of the plotted map in pixels
  const int map_h;

public:
  Airport(string name, string city, string country, string code,
          double latitude, double longtitude, int map_w, int map_h);

  void highlight();
  void restore();

  Point get_map_coord() const;

  string to_string() const;
};

class iCmp {
public:
  bool operator()(std::string a, std::string b) const noexcept {
    transform(a.begin(), a.end(), a.begin(), ::tolower);
    transform(b.begin(), b.end(), b.begin(), ::tolower);

    return strcmp(a.c_str(), b.c_str()) < 0;
  }
};

class Airports {

  // The width of the plotted map in pixels
  const int map_w;
  // The height of the plotted map in pixels
  const int map_h;


public:
  //using AirportPtr = shared_ptr<Airport>;
  Airports(int map_w, int map_h);

  vector<shared_ptr<Airport>> airport_list;
  map<string, shared_ptr<Airport>, iCmp> airport_map_by_code;

  void add_entry(string name, string city, string country, string code,
                 double latitude, double longtitude);

  vector<shared_ptr<Airport>> search(string needle) const;
};

#endif // _AIRPORTS_H
