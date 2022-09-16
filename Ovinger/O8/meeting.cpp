#include "meeting.h"

ostream& operator<<(ostream& os, Campus& campus){
    switch (campus){
    case Campus::Trondheim:
        os<< "Trondheim";
        break;
    case Campus::Gjovik:
        os<<"Gjøvik";
        break;
    case Campus::Alesund:
        os<<"Ålesund";
        break;
    default:
        break;
    }
    return os;
}

Meeting::Meeting(int mDay, int mStartTime, int mEndTime, Campus mLocation, string mSubject, const Person* mLeader){
    day = mDay;
    startTime = mStartTime;
    endTime = mEndTime; 
    location = mLocation; 
    subject = mSubject;
    leader = mLeader;

    addParticipants(leader);
    meetings.insert(this); 
}
vector<string> Meeting::getParticipantList() const{
    vector<string> memberNames; 
    for (const Person* p : participants){
        string memberName = (*p).getName();
        memberNames.push_back(memberName);
    }
    return memberNames;
}

ostream& operator<<(ostream& os, const Meeting& meeting){
    string subject = meeting.getSubject();
    Campus location = meeting.getLocation();
    int start = meeting.getStartTime();
    int end = meeting.getEndTime();
    Person leader = meeting.getLeader(); //Skal ikke brukes videre
    string leaderName = leader.getName();
    

    os << "Meeting info:\n";
    os <<'\t'<<"Subject: " << subject << endl;
    os <<'\t'<< "Location: " << location << endl;
    os <<'\t'<<"Time: from " << start << " to "<<end << endl;
    os <<'\t'<< "Host: " << leaderName << endl;
    os <<'\t'<< "Participants: ";
    for (string name : meeting.getParticipantList()){
        os<<name<<", ";
    }
    os<<endl;
    return os;
}

vector<const Person*> Meeting::findPotentialCoDriving() const{
    vector<const Person*> hasFreeSeats;
    for(const Meeting* m : meetings){
        int thisStart = this->getStartTime();
        int thisEnd = this->getEndTime();
        int mStart = m->getStartTime();
        int mEnd = m->getEndTime();
        Campus thisCampus = this->getLocation();
        Campus mCampus = m->getLocation();
        //Går gjennom medlemslista dersom møte-kriteriene er oppfylt: 
        if (((*m).getDay() == (*this).getDay()) && (unsigned(thisStart-mStart)<= 100) &&(unsigned(thisEnd-mEnd)<=100) && (thisCampus==mCampus)){
            set<const Person*> participants = m->getParticipants();
            for (const Person* p : participants){
                if (p->hasAvailableSeats()){
                    hasFreeSeats.push_back(p);
                }
            }
        }
    }
    return hasFreeSeats;
}