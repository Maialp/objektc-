/** main.cpp

   This file is part of the handout for the TDT4102 summer 2020 exam.

   This file contains the main function which launches the application.

   You do not need to change or understand this file in
   order solve the assignment.

**/

#include <fstream>
#include <iostream>

#include "application.h"

using namespace std;

int main() {

  // Application configuration parameters

  // CSV file containing airport definitions
  string airports_data{"data/airports.csv"};

  try {
    Application(airports_data).start();
  } catch (const ifstream::failure &e) {
    cout << e.what();
  }

  return 0;
}
