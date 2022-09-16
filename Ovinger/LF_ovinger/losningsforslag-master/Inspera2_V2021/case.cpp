#include "case.h"

ostream& operator<<(ostream& os, const TypeOfCase& t){
    //Begin task T1
    //there are several possible solutions. Here are two of them.
    //Alternative 1:
    map<TypeOfCase, string> typeToString{{TypeOfCase::murder, "murder"}, {TypeOfCase::robbery, "robbery"}, 
        {TypeOfCase::kidnapping, "kidnapping"}, {TypeOfCase::other, "other"}};
        //this map could also be placed as a const map in the header-file
    os << typeToString.at(t); 
    return os;
    //Alternative 2:
    /*
    switch (t){
    case TypeOfCase::murder:
        os << "murder";
        break;
    case TypeOfCase::robbery:
        os << "robbery";
        break;
    case TypeOfCase::kidnapping:
        os << "kidnapping";
        break;
    case TypeOfCase::other:
        os << "other";
        break;
    default:
        break;
    }
    return os;
    */
    //End task T1
}

//------------------------------------------------------

//Begin task C1
//one possible solution
Case::Case(string name, TypeOfCase type, int salary, Person* aClient) : 
    caseName{name}, caseType{type}, caseNumber{++caseCount}, salary{salary}, client{aClient}, solved{false} { 
        cases.insert(this);
}
//End task C1

//------------------------------------------------------


Case::~Case(){
    //Begin task C2
    cases.erase(this);
    //End task C2
}

//------------------------------------------------------


string Case::getCaseName() const{
    //Begin task C3a
    return caseName;
    //End task C3a
}
TypeOfCase Case::getCaseType() const {
    //Begin task C3b
    return caseType;
    //End task C3b
}

int Case::getCaseCount() const {
    //Begin task C3c
    return caseCount;
    //End task C3c
}
int Case::getCaseNumber() const {
    //Begin task C3d
    return caseNumber;
    //End task C3d
}
set<Case*> Case::getCases() const{
    //Begin task C3e
    return cases;
    //End task C3e
}

int Case::getSalary() const{
    //Begin task C3f
    return salary;
    //End task C3f
}

Person* Case::getClient() const{
    //Begin task C3g
    return client;
    //End task C3g
}

string Case::getDescription() const{ 
    //Begin task C3h
    return caseDescription;
    //End task C3h
}
void Case::setDescription(string description) {
    //Begin task C3i
    caseDescription = description;
    //End task C3i
}

bool Case::getSolved() const{
    //Begin task C3j
    return solved;
    //End task C3j
}
void Case::setSolved(bool solved) {
    //Begin task C3k
    this->solved = solved;
    //End task C3k
}

vector<string> Case::getClues() const {
    //Begin task C3l
    return clues;
    //End task C3l
}
void Case::addClue(string clue) {
    //Begin task C3m
    clues.push_back(clue);
    //End task C3m
}

//------------------------------------------------------

bool operator<(const Case& lhs, const Case& rhs){
    //Begin task C4
    //one possible solution:
    return (lhs.getSalary() < rhs.getSalary());
    //End task C4
}

//------------------------------------------------------

ostream& operator<<(ostream& os, const Case& c){
    //Begin task C7
    //one possible solution:
    os << "Case " << c.getCaseNumber() << " of " << c.getCaseCount() << ": " << c.getCaseName() <<"\n\n";
    
    os << "Type of case: " << c.getCaseType() << "\n\n"; 

    if(c.getSolved()){
        os << "This case is SOLVED.\n\n";
    }
    else{
        os << "This case is UNSOLVED.\n\n";
    }

    os << "Client:\n" << *c.getClient() << "\n\n";

    os << "Description: " << c.getDescription() << "\n\n";

    os << "Suspects:\n";
    for(auto s: c.getSuspects()){
        os << *s << "\n\n";
    }

    os << "Clues:\n";
    for(auto clue : c.getClues()){
        os << clue << "\n";
    }

    return os;
    //End task C7
}


//------------------------------------------------------


int Case::totalSalary() const{
    //Begin task L1
    //one possible solution:
    int salary{0};
    for(auto c : cases){
        salary += c->getSalary();
    }
    return salary;
    //End task L1
}

double Case::averageSalary() const{
    //Begin task L2
    //one possible solution:
    return totalSalary()/static_cast<double>(cases.size());
    //End task L2
}

const Case& Case::caseWLargestSalary() const{
    //Begin task L3
    //there are several possible solutions. Here are two of them.
    //siden set-et inneholder pekere hjelper det ikke at det er sortert
    
    //alternative 1:
    auto curr = *cases.begin();
    for(auto c : cases){
        if(*curr < *c){
            curr = c;
        }
    }
    return *curr;

    /*
    //alternative 2:
    auto curr = *cases.begin();
    for(auto iter = cases.begin()++; iter != cases.end(); iter++){
        if(*curr < **iter){
            curr = *iter;
        }
    }
    return *curr;
    */
   
    //End task L3
}