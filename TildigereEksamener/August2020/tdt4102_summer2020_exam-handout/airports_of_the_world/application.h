/** application.h

   This file is part of the handout for the TDT4102 summer 2020 exam.

   You do not need to change or understand this file in
   order solve the assignment.

**/

#ifndef _APPLICATION_H
#define _APPLICATION_H

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "airports.h"
#include "explorer.h"

using namespace std;

class Application {
  string airport_data_file;

  Explorer explorer;
  Airports airports;

public:
  Application(string airport_data);

  void start();

private:
  void read_data();
};

#endif // _APPLICATION_H
