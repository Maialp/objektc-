/** util.cpp

   This file is part of the handout for the TDT4102 summer 2020 exam.

   This file contains utility function for performing calculations on
   geocoordinates.

   You need to edit this file in order to solve the assignments U1 and
   U2.

**/

#include "util.h"

/**
   Assignment U1

   Implement the web mercator projection which maps geocoordinates to
   flat plane. The full assignment and the web mercator formula is
   given in the assignment PDF. The function should return a Point
   with x and y coordinates.

 */
Point Util::to_map_coord(int width, int height, double latitude,
                          double longtitude) {
  // BEGIN: U1

  int x = (width/(2*M_PI))*(deg_to_rad(latitude) + M_PI);
  int y = (height/(2*M_PI))*pow(2,0.2)*(M_PI - log(tan(M_PI/4 + deg_to_rad(longtitude)/2)));

  return {x, y};

  // END: U1
}

/**
    Assignment U2:

    Implement the havesine formula for calculating the great-circle
    distance between two geographic coordinates. The full assignment
    and the equation is given in the assignment PDF.

 */
double Util::distance(double latitude1, double longtitude1, double latitude2,
                      double longtitude2) {

   // Mean radius of the earth (in km)
   const double R = 6371;

   // BEGIN: U2
   //Latetude og airport 1 in radians: 
   const double lat_1 = deg_to_rad(latitude1);
   //Latetude og airport 2 in radians: 
   const double lat_2 = deg_to_rad(latitude2);
   
   const double delLat = deg_to_rad(latitude2-latitude1);      //latetude delta in radians
   const double delLong = deg_to_rad(longtitude2-longtitude1); //lonetude delta in radians

   double a = sin(delLat/2)*sin(delLat/2)+cos(lat_1)*cos(lat_2)*sin(delLong/2)*sin(delLong/2);
   double c = 2*atan2(sqrt(a),sqrt(1-a));
   double d = R*c;

   return d;
  // END: U2

}

/**
   Converts a string to lower case
*/
string string_to_lower(string s){
  transform(s.begin(), s.end(), s.begin(), ::tolower);

  return s;

};
