#include "NTNULogo.h"

#include "Simple_window.h"
#include "std_lib_facilities.h"

using namespace Graph_lib;

constexpr Point origo{Point{0, 0}};
constexpr int radius{85};
constexpr int pad{100};
const string title{"NTNU Logo"};

void drawNTNULogo(){

    //Kalle konstrutører som trengs for å tegne logo:
    Simple_window win{origo, 5* pad, 5* pad, title}; 

    //Lager fire sirkler som skal gjøre hjørnene runde og fine og fyller dem med blått
    Circle circle1(Point{pad,pad}, pad);
    Circle circle2(Point{3*pad,pad}, pad);
    Circle circle3(Point{pad,3*pad}, pad);
    Circle circle4(Point{3*pad,3*pad}, pad);
    //Lager rektanglene som skal binde sirklene sammen:
    Rectangle rec1(Point{pad, 0}, 2*pad, 4*pad);
    Rectangle rec2(Point{0, pad}, 4*pad, 2*pad);
    //legger til hvitt kvadrat:
    Rectangle square(Point{pad, pad}, 2*pad, 2*pad);
    //adding the blue sircle:
    Circle center(Point{2*pad,2*pad}, radius);
    

    //Sette fyll-farge:
    circle1.set_fill_color(Color::blue);
    circle2.set_fill_color(Color::blue);
    circle3.set_fill_color(Color::blue);
    circle4.set_fill_color(Color::blue);
    rec1.set_fill_color(Color::blue);
    rec2.set_fill_color(Color::blue);
    square.set_fill_color(Color::white);
    center.set_fill_color(Color::blue);

    //Fjerne kanter: Shape.set_color(Color::invisible):
    circle1.set_color(Color::invisible);
    circle2.set_color(Color::invisible);
    circle3.set_color(Color::invisible);
    circle4.set_color(Color::invisible);
    rec1.set_color(Color::invisible);
    rec2.set_color(Color::invisible);
    square.set_color(Color::invisible);
    center.set_color(Color::invisible);

    //Tegne figurer:
    win.attach(circle1);
    win.attach(circle2);
    win.attach(circle3);
    win.attach(circle4);
    win.attach(rec1);
    win.attach(rec2);
    win.attach(square);
    win.attach(center);

    win.wait_for_button();
}
