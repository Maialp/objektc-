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
//one possible solution:
class Suspect : public Person{
private:
    bool guilty;
public:
    Suspect(string firstName, string lastName, int age) : Person{firstName, lastName, age}, guilty{false} {}

    bool isGuilty() const {return guilty;}
    void setGuilty(bool guilty) {this->guilty = guilty;}

};
//End task S1, S2, S3, S4