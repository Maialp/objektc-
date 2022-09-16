/** explorer.h

   This file is part of the handout for the TDT4102 summer 2020 exam.

   This file contains the declarations for drawing and handling event
   from the main application window.

**/

#ifndef _EXPLORER_H
#define _EXPLORER_H

#include <memory>

#include "GUI.h"
#include "Graph.h"
#include "Window.h"

#include "airports.h"

using namespace Graph_lib;

class AirportNotFoundException : public exception {};

class InvalidAirportCode : public exception {};

class FileReadError : public exception {
};

class Explorer : public Graph_lib::Window {
private:
  // Vertical offset for highlight GUI group
  constexpr static int distance_offset = 20;
  constexpr static int highlight_offset = distance_offset + 240;
  constexpr static int search_offset = highlight_offset + 100;
  constexpr static int trip_offset = search_offset + 300;

  const int x_len;
  const int y_len;

  const int x_offset;

  // Vectors for keeping track of objects displayed on the map
  vector<shared_ptr<Airport>> highlighted;
  vector<Shape*> distance_lines;
  vector<Shape*> trip_lines;
  vector<shared_ptr<Airport>> trip_highlighted;

  // Widgets
  In_box in_from_airport;
  In_box in_dest_airport;
  Button btn_plot_length;
  Button btn_clear_length;
  Multiline_out_box distance_results;

  In_box in_airport;
  Button btn_highlight;
  Button btn_clear;

  In_box in_search_query;
  Button btn_search;
  Multiline_out_box search_results;

  In_box in_trip_file;
  Button btn_show_trip;
  Button btn_clear_trip;
  Multiline_out_box trip_distance_result;


  const Airports *airports;

public:
  Explorer(int w, int h);
  ~Explorer();
  void attach_airports(const Airports &airports);
  int map_w() const;
  int map_h() const;

private:
  shared_ptr<Airport> lookup_airport(string code);
  void alert(const string& msg);

  void validate_code(string code);

  void calculate_trip(const vector<string>& airport_codes);

  enum Command {
    HIGHLIGHT,
    CLEAR_HIGHLIGHTED,
    CALCULATE_DISTANCE,
    DRAW_DISTANCE_LINE,
    CLEAR_DISTANCE,
    PERFORM_SEARCH,
    DRAW_TRIP,
    CLEAR_TRIP
  };
  void do_command(Command command);

  // GUI event handling dispatch function
  template <int command>
  static void dispatch_command(Address, Address base_ptr) {
    try {
      reference_to<Explorer>(base_ptr).do_command(Command(command));
    } catch (AirportNotFoundException *) {
    } catch (AirportNotFoundException&) {
    } catch (InvalidAirportCode *) {
    } catch (InvalidAirportCode &) {
    } catch (FileReadError *) {
    } catch (FileReadError &) {
    }
  }

  template <int command1, int command2>
  static void dispatch_command2(Address addr, Address base_ptr) {
    dispatch_command<command1>(addr, base_ptr);
    dispatch_command<command2>(addr, base_ptr);
  }
};

#endif // _EXPLORER_H
