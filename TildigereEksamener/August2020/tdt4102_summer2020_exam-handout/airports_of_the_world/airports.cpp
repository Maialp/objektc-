/** airport.cpp

   This file is part of the handout for the TDT4102 summer 2020 exam.


   This file contains the data definition for the internal
   representation of an airport in the program.

   You need to edit this file in order to solve the assignments A1, A2
   and A3

**/


#include "airports.h"
#include "util.h"

/**
   Assignment A1

   Implement the function get_map_coord such that it uses the static
   to_map_coord function from the Util class to return a Point
   representing the projected coordinates for the current airport
   instance. Remember that the relevant parameters can be found as the
   map_w, map_h, latitude and longtitude class member variables.
 */
Point Airport::get_map_coord() const {
  // BEGIN: A1
  return Util::to_map_coord(map_w, map_h, longtitude, latitude);
  // END: A1

}

/**
   Assignment A2

   Implement the function highlight which highlights this airport on
   the map by
   * Setting its fill color red
   * Setting its radius to 7

   Recall that this class (Airport) extends the Circle class from
   Graph_lib so you have access to all the functions from that
   class. Look at the corresponding restore function, implemented
   below, for inspiration.
 */
void Airport::highlight() {
  // BEGIN: A2
  set_fill_color(Color(Color::red, Color::visible));
  set_radius(7);  
  // END: A2

}

/**
   Assignment A3

   Implement the function search which returns a vector of pointers to
   Airport instances (type of vector<shared_ptr<Airport>>) whose name
   contains the string passed as the needle parameter. Remember to
   make the search case insensitive. For your convenience, we provide
   the function string_to_lower for converting a string to lower case.

   Return an empty vector if no matching airport is found. Remember
   that pointers to all the Airport instances are held in the
   class-member vector airport_list.


   For example, if the string needle is "Tron" or "tron" the only
   matching airport is Trondheim Værnes. The returned vector should
   therefore only contain a single Airport object instance pointer.

   You can use the existing declaration and return of the result vector.
 */
vector<shared_ptr<Airport>> Airports::search(string needle) const {
  vector<shared_ptr<Airport>> result;
  // BEGIN: A3
  string needleLower = string_to_lower(needle);

  for(shared_ptr<Airport> a : airport_list){
    string nameLower = string_to_lower(a->name);
    if((nameLower).find(needleLower) != string::npos){
      result.push_back(a);
    }

  }
  // END: A3
  return result;
}

/**
   Restores the highlighted airport to its normal representation
*/
void Airport::restore() {
  set_fill_color(Color(Color::red, Color::invisible));
  set_radius(2);
}

Airport::Airport(string name, string city, string country, string code,
                 double latitude, double longtitude, int map_w, int map_h)
    : Circle({0, 0}, 2), name(name), city(city), country(country), code(code),
      latitude(latitude), longtitude(longtitude), map_w(map_w), map_h(map_h) {
  // Hack to work around constructor initialization order
  auto coords = get_map_coord();
  move(coords.x, coords.y);
}

Airports::Airports(int map_w, int map_h) : map_w(map_w), map_h(map_h){};

void Airports::add_entry(string name, string city, string country, string code,
                         double latitude, double longtitude) {
  auto airport = make_shared<Airport>(name, city, country, code, latitude,
                                      longtitude, map_w, map_h);
  airport_list.push_back(airport);
  airport_map_by_code[airport->code] = airport;
}
