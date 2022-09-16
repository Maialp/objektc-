#include "bysykler.h"

//3a) 
Location::Location(string str, Graph_lib::Point pt)
         : name{str}, p{pt} {}


//3c)
void Bikestation::setBikes(unsigned int numBikes){
    bikes = numBikes;
}

int Bikestation::getBikes(){
    return bikes;
}

//3d)
string Bikestation::status(){
    string strCapacity = to_string(capacity);
    string strBikes = to_string(bikes);
    return strBikes + " out of " + strCapacity;
}

Bikestation::Bikestation(Location where, unsigned int cap, unsigned int numBikes) 
            : loc{where}, capacity{cap}, bikes{numBikes}{
    //punkt 1)
    Reclangle* r = new Reclangle{loc.p, dispWidth, dispHeight};
    r->set_fill_color(Color::White);
    display.push_back(r);

    //punkt 2)
    

}
