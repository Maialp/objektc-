#include "animal.h"
#include "std_lib_facilities.h"

string Animal::toString(){
    string ageString = to_string(age);
    string final = "Animal: ";
    final.append(name);
    final.append(", ");
    final.append(ageString);
    return final;
}

string Dog::toString()  {
    string ageString = to_string(age);
    string final = "Dog: ";
    final.append(name);
    final.append(", ");
    final.append(ageString);
    return final;
}

string Cat::toString()  {
    string ageString = to_string(age);
    string final = "Cat: ";
    final.append(name);
    final.append(", ");
    final.append(ageString);
    return final;
}

void testAnimal(){
    Dog milly("Milly", 15);
    Cat pal("Paal", 7);
    cout << milly.toString()<<'\n' << pal.toString() << '\n' <<endl;

}