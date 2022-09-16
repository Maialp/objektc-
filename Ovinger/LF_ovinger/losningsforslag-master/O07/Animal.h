#pragma once
#include "std_lib_facilities.h"

/* Teorioppgave:
private - bare klassen selv har tilgang til private medlemsfunksjoner
og medlemsvariabler
• public - alle har tilgang til public medlemsfunksjoner og
medlemsvariabler
• protected - sub-klasser har tilgang til protected medlemsfunksjoner
og medlemsvariabler til super-klassen

Det er også ulike måter å arve på - se kapittel 14.3.5 i læreboken.
• Ved public arv blir medlemmer bevart som de er i
superklassen, dvs. public forblir public, protected forblir protected osv.
• Ved private arv, så vil alle medlemmer fra superklassen gjøres
til private, og dermed ikke være tilgjengelige i sub-klassen.
*/

class Animal {
public:
    Animal(string name, int age) : name{name}, age{age} {};
    virtual string toString() const = 0;
    virtual ~Animal(){};
protected:
    string name;
    int age;
};

class Dog : public Animal {
public:
    Dog(string name, int age) : Animal{name, age} {};
    string toString() const override;
};

class Cat : public Animal {
public:
    Cat(string name, int age) : Animal{name, age} {};
    string toString() const override;
};

void testAnimal();