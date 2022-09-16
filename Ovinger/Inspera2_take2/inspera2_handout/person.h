#pragma once
#include <string>
#include <iostream>
using namespace std;

class Person{
private:
    string firstName;
    string lastName;
    int age;
public:
    Person(string f, string l, int age);

    string getFirstName() const;
    string getLastName() const;
    int getAge() const;
};

ostream& operator<<(ostream& os, const Person& p);

//Begin task S1, S2, S3 and S4

class Suspect : public Person{
    bool guilty;
public: 
    Suspect(string f, string l, int age) : Person{f,l,age}, guilty{false}{}
    bool getGuilty() const {return guilty;} //skal ikke endre på noe, og bør derfor være konst
    void setGuilty(bool isGuilty) {guilty = isGuilty;}

};

//End task S1, S2, S3, S4