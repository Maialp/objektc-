#include "person.h"

void insertOrdered(std::list<Person> &l, const Person& p){
    l.push_back(p);
    l.sort();
}

bool operator<(const Person& a, const Person& b){
    std::string nameA = a.getName();
    std::string nameB = b.getName();
    return nameA < nameB;
}