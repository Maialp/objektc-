#include "person.h"

//Begin task P1
//one possible solution:
Person::Person(string f, string l, int age) : firstName{f}, lastName{l}, age{age}{

}
//End task P1

string Person::getFirstName() const{
    //Begin task P2a
    return firstName;
    //End task P2a
}

string Person::getLastName() const{
    //Begin task P2b
    return lastName;
    //End task P2b
}

int Person::getAge() const{
    //Begin task P2c
    return age;
    //End task P2c
}

ostream& operator<<(ostream& os, const Person& p){
    //Begin task P3
    //one possible solution:
    os << "Name: " << p.getFirstName() << " " << p.getLastName() << '\n';
    os << "Age: " << p.getAge();
    return os;
    //End task P3
}