#include "meeting.h"

ostream& operator<<(ostream& os, Campus c){
    switch (c)
    {
    case Campus::Alesund:
        os<<"Ålesund";
        break;
    case Campus::Gjovik:
        os<<"Gjøvik";
        break;
    case Campus::Trondheim:
        os<<"Trondheim";
        break;
    default:
        break;
    }
    return os;
}

Meeting::Meeting(int day, int startT, int endT, Campus location, string subject, const Person* leader)
            : day{day}, startTime{startT}, endTime{endT}, location{location}, subject{subject}, leader{leader}{
    meetings.insert(this);
    participants.insert(leader);
}

Meeting::~Meeting(){
    meetings.erase(this);
}

void Meeting::addParticipant(const Person* p){
    participants.insert(p);
}

vector<string> Meeting::getParticipantList(){
    vector<string> names;
    for (const Person* p : participants){
        string name = p->getName();
        names.push_back(name);
    }
    return names;
}

ostream& operator<<(ostream& os, Meeting& m){
    os << m.getSubject() <<':'<< endl;
    os << '\t' << "Leader: " << m.getLeader()->getName() << ", " << m.getLeader()->getEmail() << endl;
    os << '\t' << "Location: " << m.getLocation() << endl;
    os << '\t' << "Time: " << m.getStartTime() << " to " << m.getEndTime() << endl << endl;
    os << '\t' << "Participants:\n\t" ;
    for (string name : m.getParticipantList()){
        os << name << ", ";
    }
    return os;
}

vector<const Person*> Meeting::findPotentialCoDriving(){
    vector<const Person*> rides;
    for (auto m : meetings){
        if ((m->day == this->day)&&(abs(m->startTime - this->startTime)<= 1000) && (abs(m->startTime - this->startTime)<=1000)){
            for(auto p : m->participants){
                if(p->hasAvailableSeats()){
                    rides.push_back(p);
                }
            }
        }
    }
    return rides;
}