#pragma once

#include "Person.h"

#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

enum class Campus { trh, aal, gjo };
const std::map<Campus, std::string> campusToString {
	{ Campus::trh, "Trondheim" },
	{ Campus::aal, "Aalesund" },
	{ Campus::gjo, "Gjovik "}
};

std::ostream& operator<<(std::ostream& os, Campus c);

class Meeting
{
public:
	// Vi ønsker ikke å tillate kopiering av Meeting-objekter
	Meeting(const Meeting&) = delete;
	Meeting& operator=(const Meeting&) = delete;

	Meeting(int day, int startTime, int endTime, Campus location, const std::string& subject, const Person* leader);
	~Meeting();

	int getDay() const { return day; }
	int getStartTime() const { return startTime; }
	int getEndTime() const { return endTime; }
	Campus getLocation() const { return location; }
	std::string getSubject() const { return subject; }

	
	const Person& getLeader() const { return *leader; }

	void addParticipant(const Person* person);
	std::vector<std::string> getParticipantList() const;

	std::vector<const Person*> findPotentialCoDriving() const;

private:
	int day;
	int startTime;
	int endTime;
	Campus location;
	std::string subject;
	const Person* leader;
	std::set<const Person*> participants;

	// C++17 har static inline variabler, så møter kan bli initialisert her istedenfor i .cpp-filen.
	static inline std::set<const Meeting*> meetings{};
};

std::ostream& operator<<(std::ostream& os, const Meeting& m);
