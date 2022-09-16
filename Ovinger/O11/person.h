#pragma once 
#include <string>
#include <iostream>
#include <cmath>
#include <list>

class Person{
    private:
        std::string firstName;
        std::string lastName;
    public:
        Person(std::string firstName, std::string lastName) : firstName{firstName}, lastName{lastName} {}
        void printPerson() {std::cout << "Name: "<<firstName<<' '<<lastName<<std::endl;}
        std::string getFirstName() const {return firstName;}
        std::string getLastName() const {return lastName;}
        std::string getName() const {return firstName+ " " +lastName;}
        friend bool operator<(const Person& a, const Person& b);
};

void insertOrdered(std::list<Person> &l, const Person& p);