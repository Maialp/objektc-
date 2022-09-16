/** explorer.cpp

   This file is part of the handout for the TDT4102 summer 2020 exam.

   This file implements the functions for drawing and handling events
   from the main application window.

   You need to modify this file to solve the assignments E1 through
   E6.

**/
 
#include "explorer.h"

#include "GUI.h"
#include "Graph.h"
#include <FL/fl_ask.H>

#include "util.h"

/**
    Assignment E1

    Implement the function lookup_airport which looks up an airport by
    its three-letter (IATA) code passed through the code paramter. Use
    the map accessed using airports->airport_map_by_code to do
    this. This is a normal C++ map which can be accessed as you are
    used to, except that key lookup is case insensitive. If the
    airport isn't found you should

   * call the function alert to show a meaningful error message
   * throw the exception AirportNotFoundException defined in explorer.h
**/
shared_ptr<Airport> Explorer::lookup_airport(string code) {
  // BEGIN: E1
  
  auto res = airports->airport_map_by_code.find(code);
  if(res == airports->airport_map_by_code.end()){
    alert("No airport matched " + code);
    throw AirportNotFoundException();
  }

  return res->second;

  // END: E1
}

/**
   Assignment E2

   Implement the function validate_code which checks if the airport
   code passed as a string through the code parameter is valid. A valid
   airport code must

   * be exactly three characters long
   * contain only letters between a and z (inclusive, case insensitive)

   If the airport code is invalid, use the function alert to
   display a meaningful error message, and throw the InvalidAirportCode
 exception.
 **/
void Explorer::validate_code(string code) {

  // BEGIN: E2

  if(code.length() != 3){
    alert("Incalid airport code " + code);
    throw InvalidAirportCode();
  }
  for (char c : code){
    if(!((c>='a' && c<='z') || (c>='A' && c<='Z'))){
      alert("Incalid airport code " + code);
      throw InvalidAirportCode();
    }
  }
  // END: E2
}

// The following function implements the handling code for GUI
// events. The function takes a value from the Command enum as its
// argument and performs the appropriate action.

// You do not need to consider error conditions, such as the user
// entering the name of a non-existing airport, when implementing
// these functions as this is transparently handled

void Explorer::do_command(Command command) {
  switch (command) {
  case HIGHLIGHT: {

    /** Assignment E3

        Implement the handler for the airport highlighting action of
        the graphical user interface. This action highlights the
        airport whose code is entered into the text field named
        in_airport in the this class. The function should

        * get the airport code entered in the in_airport text field
        * Call the function validate_code to ensure that the code is valid
        * look up the name of the airport to get a pointer to the corresponding
       Airport object
        * call the highlight function of the returned airport object to
          highlight the airport
        * Add the Airport pointer to the class member vector highlighted so that
          they can be restored to normal later
     */

    // BEGIN: E3

    string airport_code = in_airport.get_string();
    validate_code(airport_code);
    
    auto airport = lookup_airport(airport_code);
    airport->highlight();
    highlighted.push_back(airport);
    // END: E3

  } break;

  case PERFORM_SEARCH: {
/** Assignment E4

    Using the search function from the Airports class (Assignment
    A3), implement the handler code for the search action of the
    graphical user interface. The result of the search should be
    displayed in the output box search_results.

    For example, a search for the string "oslo" yields two results,
    OSL (Gardemoen) and FBU (Fornebu). An example of a suitable output
    to put in the search_results box is

      The search for oslo returned
      OSL Oslo Lufthavn
      FBU Oslo, Fornebu Airport

*/
    // BEGIN: E4

    auto query = in_search_query.get_string();
    auto result = airports->search(query);

    if (result.size()>0){
      stringstream s;
      s << "The search for " + query + "returned\n";
      for (auto a : result){
        s << a->code << ' ' << a->name << endl;
      }
      search_results.put(s.str());
    }
    else {
      search_results.put("The search for " + query + " returned 0 results");

    }
    // END: E4


  } break;
  case CALCULATE_DISTANCE: {
    /** Assignment E5

        Implement the handling code for the distance calculation
        action which calculates the distance between two airports and
        prints the result in the Distance calculation text box
        (declared as distance_results). The
        text fields in_from_airport and in_dest_airport contains the
        codes of the two airports.

        Your function should use the distance function from the Util
        class (assignment U2). Get the latitude and longtitude
        parameters from the Airport object pointers returned from the
        lookup_airport function.

        For example, querying the distance between OSL (Gardemoen) and
        SFO (San Francisco) could print the following in the distance
        calculation box:

           The distance from
           OSL to SFO is
           8344.854071 km

    */

    // BEGIN: E5

    auto code1 = in_from_airport.get_string();
    auto code2 = in_dest_airport.get_string();

    validate_code(code1);
    validate_code(code2);

    auto airport1 = lookup_airport(code1);
    auto airport2 = lookup_airport(code2);

    auto distance = Util::distance(airport1->latitude, airport1->longtitude, airport2->latitude, airport2->longtitude);

    distance_results.put("The distance from\n" + code1+" to "+code2+" is\n" +to_string(distance) +" km");
    // END: E5


  } break;

  case DRAW_TRIP: {
    /** Assignment E6

        In this assignment you will implement a part of a feature
        that plots and calculates the aggregated length of a multi-leg
        journey.

        A trip is defined in a file containing a single line with a
        sequence of airport codes separated by spaces. For example:

           TRD OSL EWR

        specifies a trip from Trondheim (TRD) to Newark (EWR) via Oslo (OSL).


        Specifically, we ask you to implement the code for opening and parsing
        such files into a vector of strings containing the airport
        codes. The distance calculation and plotting itself is already
        implemented in the function calculate_trip which takes a
        vector of airport codes as its parameter. The path of the trip
        file is entered into the in_trip_file text box. You can use
        the preexisting declaration of the codes vector and the call to
        calculate_trip in your implementation.

        Several sample trip files are provided in the data folder
        named tripX.txt.

        The function should call the alert function to display a
        suitable error message and throw the FileReadError exception
        if something goes wrong. In particular this should happen when

        * Opening the file fails
        * The file contains less that two airport codes
     */

    vector<string> codes;
    // BEGIN: E6

    auto fname = in_trip_file.get_string();
    ifstream ist{fname};

    if (!ist){
      alert("unable to open file " + fname);
      throw FileReadError();
    }

    string code;
    while (getline(ist, code,' ')){
      string trimmed;
      stringstream trimmer;
      trimmer << code;
      trimmer >>trimmed;
      validate_code(trimmed);
      codes.push_back(trimmed);
    }
    if (codes.size()<2){
      alert("Need at least two ariports in file");
      throw (FileReadError());
    }
    calculate_trip(codes);
    // END: E6


    calculate_trip(codes);

  } break;

    ///
    /// END OF ASSIGNMENTS
    ///
  case CLEAR_TRIP:
    trip_distance_result.put("");
    for (auto s : trip_lines) {
      detach(*s);
      delete s;
    }
    trip_lines.clear();
    for (auto a : trip_highlighted) {
      a->restore();
    }
    trip_highlighted.clear();
    break;
  case DRAW_DISTANCE_LINE: {

    auto code1 = in_from_airport.get_string();
    auto code2 = in_dest_airport.get_string();
    validate_code(code1);
    validate_code(code2);
    auto airport1 = lookup_airport(code1);
    auto airport2 = lookup_airport(code2);

    auto line = new Line(airport1->get_map_coord(), airport2->get_map_coord());
    line->set_color(Color::red);
    distance_lines.push_back(line);
    attach(*line);

  } break;
  case CLEAR_HIGHLIGHTED:

    while (!highlighted.empty()) {
      auto a = highlighted.back();
      highlighted.pop_back();
      a->restore();
    }
    break;

  case CLEAR_DISTANCE:
    distance_results.put("");
    for (auto a : distance_lines) {
      detach(*a);
      delete a;
    }
    distance_lines.clear();
    break;
  }

  redraw();
}

void Explorer::calculate_trip(const vector<string> &airport_codes) {

  vector<string> codes;

  // Be forgiving and trim airport codes
  for (auto &c : airport_codes) {
    string trimmed;
    stringstream trimmer;
    trimmer << c;
    trimmer >> trimmed;
    codes.push_back(trimmed);
  }

  stringstream text;

  text << "The trip " << codes.front();

  // Get the first airport
  shared_ptr<Airport> airport = lookup_airport(codes.front());
  codes.erase(codes.begin());

  Open_polyline *route = new Open_polyline;
  route->set_color(Color::red);
  route->add(airport->get_map_coord());

  airport->highlight();
  trip_highlighted.push_back(airport);

  // Only process the first element once

  double trip_length = 0;

  for (auto c : codes) {
    auto a = lookup_airport(c);
    a->highlight();
    trip_highlighted.push_back(a);
    route->add(a->get_map_coord());
    trip_length += Util::distance(airport->latitude, airport->longtitude,
                                  a->latitude, a->longtitude);
    text << " -> " << endl << c;
  }

  text << endl << " is " << trip_length << " km";

  trip_distance_result.put(text.str());
  route->draw_lines();
  trip_lines.push_back(route);
  attach(*route);
}

/**
   Shows a message box to the user displaying the message msg
 */
void Explorer::alert(const string &msg) { fl_alert("%s", msg.c_str()); }

void Explorer::attach_airports(const Airports &airports) {
  this->airports = &airports;
  for (auto ap : airports.airport_list) {
    attach(*ap);
  }
  redraw();
}

int Explorer::map_w() const { return x_len; }
int Explorer::map_h() const { return y_len; }

Explorer::Explorer(int w, int h)
    : Graph_lib::Window({0, 0}, w, h, "MapView"), x_len(w - 300), y_len(h),
      x_offset(x_len),
      // Airport distance interface
      in_from_airport({x_offset, distance_offset}, 200, 20, "From"),
      in_dest_airport({x_offset, distance_offset + 20}, 200, 20, "To"),
      btn_plot_length(
          {x_offset, distance_offset + 40}, 200, 20, "Plot length",
          &dispatch_command2<CALCULATE_DISTANCE, DRAW_DISTANCE_LINE>),
      btn_clear_length({x_offset, distance_offset + 60}, 200, 20, "Clear line",
                       &dispatch_command<CLEAR_DISTANCE>),
      distance_results({x_offset, distance_offset + 100}, 200, 100,
                       "Distance calculations"),

      // Airport highlighting interface
      in_airport({x_offset, highlight_offset}, 200, 20, "Airport"),
      btn_highlight({x_offset, highlight_offset + 20}, 200, 20, "Highlight",
                    &dispatch_command<HIGHLIGHT>),
      btn_clear({x_offset, highlight_offset + 40}, 200, 20, "Clear all",
                &dispatch_command<CLEAR_HIGHLIGHTED>),

      // Airport search interface
      in_search_query({x_offset, search_offset}, 200, 20, "Search query"),
      btn_search({x_offset, search_offset + 20}, 200, 20, "Search",
                 &dispatch_command<PERFORM_SEARCH>),
      search_results({x_offset, search_offset + 60}, 200, 200,
                     "Search results"),

      // Trip calculation interface
      in_trip_file({x_offset, trip_offset}, 200, 20, "Trip file"),
      btn_show_trip({x_offset, trip_offset + 20}, 100, 20, "Show trip",
                    &dispatch_command<DRAW_TRIP>),
      btn_clear_trip({x_offset + 100, trip_offset + 20}, 100, 20, "Clear trip",
                     &dispatch_command<CLEAR_TRIP>),
      trip_distance_result({x_offset, trip_offset + 60}, 200, 100,
                           "Trip distance")

{

  attach(btn_plot_length);
  attach(btn_clear_length);
  attach(in_from_airport);
  attach(in_dest_airport);
  attach(distance_results);

  attach(in_airport);
  attach(btn_highlight);
  attach(btn_clear);

  attach(in_search_query);
  attach(btn_search);
  attach(search_results);

  attach(in_trip_file);
  attach(btn_show_trip);
  attach(btn_clear_trip);
  attach(trip_distance_result);
  end();
}

Explorer::~Explorer() {
  for (auto d : distance_lines) {
    detach(*d);
    delete d;
  }
  for (auto t : trip_lines) {
    detach(*t);
    delete t;
  }
}
