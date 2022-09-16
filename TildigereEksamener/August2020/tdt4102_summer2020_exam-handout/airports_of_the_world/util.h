/** util.h

   This file is part of the handout for the TDT4102 summer 2020 exam.

   This file contains utility function for performing calculations on
   geocoordinates.

**/

#ifndef _UTIL_H
#define _UTIL_H

#include "airports.h"
#include <cmath>

#ifndef M_PI // Windows hack
#define M_PI 3.14159
#endif

using namespace Graph_lib;

class Util {
public:
  static Point to_map_coord(int width, int height, double latitude,
                             double longtitude);

  static double distance(double latitude1, double longtitude1, double latitude2,
                         double longtitude2);

  constexpr static double deg_to_rad(double degree) {
    return degree * (M_PI / 180);
  }

};

string string_to_lower(string s);

#endif // _UTIL_H
