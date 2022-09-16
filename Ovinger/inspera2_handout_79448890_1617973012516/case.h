#pragma once
#include "person.h"
#include <set>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

enum class TypeOfCase{murder, robbery, kidnapping, other};
ostream& operator<<(ostream& os, const TypeOfCase& t);

class Case{
private:
    string caseName; //the name of the case
    TypeOfCase caseType; //type of case
    
    static inline int caseCount{0}; //total number of cases
    int caseNumber; //the id-number for this case
    static inline set<Case*> cases{}; //a set containing pointers to all of the cases
    
    int salary; //how much money you will get for solving the case
    Person* client; //your client
    string caseDescription; // a description of the case
    bool solved; //true if solved, false if unsolved
    
    vector<string> clues; // vector filled with clues (strings)

    //Begin task C5
    set<Suspect*> suspects; // dette set-et inneholder Suspect-pekere
    //End task C5
public:
    Case(string name, TypeOfCase type, int salary, Person* aClient);
    ~Case();

    string getCaseName() const;
    TypeOfCase getCaseType() const;
    
    int getCaseCount() const;
    int getCaseNumber() const;
    set<Case*> getCases() const;
    
    int getSalary() const;
    
    Person* getClient() const;

    string getDescription() const;
    void setDescription(string description);

    bool getSolved() const;
    void setSolved(bool isSolved);

    vector<string> getClues() const;
    void addClue(string clue);

    //Begin task C6
    set<Suspect*> getSuspects() const {return suspects;} 
    void addSuspect(Suspect* s) {suspects.insert(s);} 
    //End task C6

    int totalSalary() const;
    double averageSalary() const;
    const Case& caseWLargestSalary() const;
};

bool operator<(const Case& lhs, const Case& rhs);

ostream& operator<<(ostream& os, const Case& c);
