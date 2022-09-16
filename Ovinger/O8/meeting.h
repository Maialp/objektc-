#pragma once 
#include "std_lib_facilities.h"
#include "car.h"


enum class Campus {Trondheim, Alesund, Gjovik};

ostream& operator<<(ostream& os, Campus& campus);

class Meeting{
    private:
        int day;
        int startTime;
        int endTime;
        Campus location;
        string subject;
        const Person* leader;
        set<const Person*> participants;
        static inline set<const Meeting*> meetings{};

    public:
        Meeting(int mDay, int mStartTime, int mEndTime, Campus mLocation, string mSubject, const Person* mLeader);
        ~Meeting(){meetings.erase(this);}

        int getDay() const {return day;}
        int getStartTime() const {return startTime;}
        int getEndTime() const {return endTime;}
        Campus getLocation() const {return location;}
        string getSubject() const {return subject;}
        Person getLeader() const {return *leader;}
        set<const Person*> getParticipants() const {return participants;}
        void addParticipants(const Person* person) {participants.insert(person);}
        vector<string> getParticipantList() const;
        vector<const Person*> findPotentialCoDriving() const;
        
};
ostream& operator<<(ostream& os, const Meeting& meeting);
