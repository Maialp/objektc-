#include "Meeting.h"

#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

std::ostream& operator<<(std::ostream& os, Campus c)
{
	return os << campusToString.at(c);
}

// Initialiser static medlemsvariabel meetings
// Kun nødvendig i C++14 og tidligere, C++17 har static inline variabler
// std::set<const Meeting*> Meeting::meetings;

Meeting::Meeting(int day, int startTime, int endTime, Campus location, const std::string& subject, const Person* leader)
	: day{day},
	  startTime{startTime},
	  endTime{endTime},
	  location{location},
	  subject{subject},
	  leader{leader}
{
	meetings.insert(this); // Legger til dette møtet i meetings-settet.
	addParticipant(leader);
}

Meeting::~Meeting()
{
	meetings.erase(this); // Fjerner dette møtet fra meetings-settet
}

void Meeting::addParticipant(const Person* person)
{
	participants.insert(person);
}

std::vector<std::string> Meeting::getParticipantList() const
{
	std::vector<std::string> participantList;
	for (auto p : participants) { // Alternativt: for (const Person* : participants)
		participantList.push_back(p->getName());
	}

	return participantList;
}

std::vector<const Person*> Meeting::findPotentialCoDriving() const
{
	std::vector<const Person*> potentialDrivers;
	for (auto* m : meetings) { // Alternativt: for (const Meeting* m : meetings)
		if ( m->location == location && m->day == day
			&& abs(m->startTime - startTime) <= 1 && abs(m->endTime - endTime) <= 1) {

			for (const Person* p : m->participants) {
				if (p->hasAvailableSeats()) {
					potentialDrivers.push_back(p);
				}
			}
		}
	}

	return potentialDrivers;
}

std::ostream& operator<<(std::ostream& os, const Meeting& m)
{
	os << m.getSubject() << "-meeting at " << m.getLocation() << " campus, "
	   << "from " << m.getStartTime() << " to " << m.getEndTime() << " by " << m.getLeader()
	   << "\n > Participants:";

	auto participants{m.getParticipantList()};
	for (const auto& p : participants) { // Alternativt: for (const string& p:. participants)
		os << " " << p;
	}

	return os;
}
