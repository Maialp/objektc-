/** application.cpp

   This file is part of the handout for the TDT4102 summer 2020 exam.

   This file contains basic initialization routines for the
   program.

   You do not need to change or understand this file in order to solve
   the assignments.

**/

#include <fstream>
#include <iostream>

#include "application.h"
#include "csv.h"

Application::Application(string airport_data)
    : airport_data_file(airport_data), explorer(1300, 800),
      airports(explorer.map_w(), explorer.map_h()) {};

void Application::start() {

  read_data();
  explorer.attach_airports(airports);
  gui_main();
}

void Application::read_data() {
  ifstream f(airport_data_file);

  csv::CsvParser parser(f);

  auto it = parser.begin();

  while (it != parser.end()) {

    auto row = *it;

    // Filter airports without IATA code
    if (row[4] == "\\N") {
      it++;
      continue;
    }

    airports.add_entry(row[1], row[2], row[3], row[4], stod(row[6]),
                       stod(row[7]));

    it++;
  }
}
