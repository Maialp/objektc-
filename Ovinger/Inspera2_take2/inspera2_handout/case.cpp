#include "case.h"

ostream& operator<<(ostream& os, const TypeOfCase& t){
    //Begin task T1
    switch (t){
    case TypeOfCase::murder:
        os << "murder";
        break;
    case TypeOfCase::kidnapping:
        os << "kidnapping";
        break;
    case TypeOfCase::robbery:
        os << "robbery";
        break;
    case TypeOfCase::other:
        os << "other";
        break;        
    default:
        break;
    }
    return os;
    //End task T1
}

//------------------------------------------------------

//Begin task C1
Case::Case(string name, TypeOfCase type, int salary, Person* aClient)
        : caseName{name}, caseType{type}, salary{salary}, client{aClient}{
    caseCount++;
    caseNumber = caseCount;
    solved = false;
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
void Case::setSolved(bool isSolved) {
    //Begin task C3k
    solved = isSolved;
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

    //True om lønn på lhs < rhs
    return (lhs.getSalary() < rhs.getSalary());
    
    //End task C4
}

//------------------------------------------------------

ostream& operator<<(ostream& os, const Case& c){
    //Begin task C7
    os<<"Case "<<c.getCaseNumber()<<" of "<<c.getCaseCount()<<": "<<c.getCaseName()<<"\n\n";
    os<<"Type of case: " << c.getCaseType()<<"\n\n";
    os<<"This case is ";
    if(c.getSolved()){os<<"SOLVED.\n\n";}
    else{os<<"UNSOLVED.\n\n";}
    os<<"Client:\n"<<c.getClient()<<endl;
    os<<"Description: "<<c.getDescription()<<endl;

    set<Suspect*> suspects = c.getSuspects();
    os<<"Suspects:\n";
    for(Suspect* suspect : suspects){
        os<< *suspect<<endl;
    } 

    vector<string> clues = c.getClues();
    os<<"Clues: \n";
    for(string clue : clues){
        os<<clue<<endl;
    }
    return os;
    //End task C7
}


//------------------------------------------------------


int Case::totalSalary() const{
    //Begin task L1
    int totalSalary = 0;
    for(Case* c : this->cases){
        totalSalary += c->getSalary();
    }
    return totalSalary;
    //End task L1
}

double Case::averageSalary() const{
    //Begin task L2
    double totalSalary = static_cast<double>(this->totalSalary());
    double avrSal = totalSalary/((this->cases).size());
    return avrSal; 
    //End task L2
}

const Case& Case::caseWLargestSalary() const{
    //Begin task L3
    auto mostSalary = *cases.begin();
    for(auto c : cases){
        if (*mostSalary < *c){
            mostSalary = c;
        }
    }
    return *mostSalary; 
    //End task L3
}