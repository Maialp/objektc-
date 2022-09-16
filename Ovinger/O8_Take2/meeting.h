#pragma once
#include "person.h"

enum class Campus{Trondheim, Alesund, Gjovik};

ostream& operator<<(ostream& os, Campus c);

class Meeting{
    int day;
    int startTime;
    int endTime;
    Campus location;
    string subject;
    const Person* leader;
    set<const Person*> participants;
    static inline set<const Meeting*> meetings{};
public:
    Meeting(int day, int startT, int endtT, Campus location, string subject, const Person* leader);
    ~Meeting();
    int getDay() const { return day;}
    int getStartTime() const { return startTime;}
    int getEndTime() const { return endTime;}
    Campus getLocation() const { return location;}
    string getSubject() const { return subject;}
    const Person* getLeader() const { return leader;}
    void addParticipant(const Person* p);
    vector<string> getParticipantList();
    vector<const Person*> findPotentialCoDriving();
};

ostream& operator<<(ostream& os, Meeting& m);