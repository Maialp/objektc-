#include "NTNULogo.h"

#include "Simple_window.h"
#include "std_lib_facilities.h"

using namespace Graph_lib;

constexpr Point origo{Point{0, 0}};
constexpr int radius{85};
constexpr int pad{100};
const string title{"NTNU Logo"};

void drawNTNULogo(){

    //Kalle konstrutøren som trengs for å tegne logo:
    Simple_window win{origo, 5* pad, 5* pad, title}; 

    Circle midCircle{Point{origo.x + 2 * pad, origo.y + 2 * pad}, radius};
    Rectangle topRectangle{Point{origo.x + pad, origo.y + pad}, Point{origo.x + 3 * pad, origo.y + 3 * pad}};

    Circle c1{Point{origo.x + pad, origo.y + pad}, pad};
    Circle c2{Point{origo.x + 3 * pad, origo.y + pad}, pad};
    Circle c3{Point{origo.x + pad, origo.y + 3 * pad}, pad};
    Circle c4{Point{origo.x + 3 * pad, origo.y + 3 * pad}, pad};
    Rectangle r1{Point{origo.x, origo.y + pad}, Point{origo.x + 4 * pad, origo.y + 3 * pad}};
    Rectangle r2{Point{origo.x + pad, origo.y}, Point{origo.x + 3 * pad, origo.y + 4 * pad}}; 

    //Sette fyll-farge:
    midCircle.set_fill_color(Color::dark_blue);
    topRectangle.set_fill_color(Color::white);
    c1.set_fill_color(Color::dark_blue);
    c2.set_fill_color(Color::dark_blue);
    c3.set_fill_color(Color::dark_blue);
    c4.set_fill_color(Color::dark_blue);
    r1.set_fill_color(Color::dark_blue);
    r2.set_fill_color(Color::dark_blue);

    //Fjerne kanter: 
    midCircle.set_color(Color::invisible);
    topRectangle.set_color(Color::invisible);
    c1.set_color(Color::invisible);
    c2.set_color(Color::invisible);
    c3.set_color(Color::invisible);
    c4.set_color(Color::invisible);
    r1.set_color(Color::invisible);
    r2.set_color(Color::invisible);

    //Tegne figurer:
    win.attach(c1);
    win.attach(c2);
    win.attach(c3);
    win.attach(c4);
    win.attach(r1);
    win.attach(r2);
    win.attach(topRectangle);
    win.attach(midCircle);

    win.wait_for_button();
}
