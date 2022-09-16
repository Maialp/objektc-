#pragma once

#include "Window.h"
#include "GUI.h"
#include "Meeting.h"
#include "Person.h"

#include <string>
#include <vector>

using namespace Graph_lib;

// Meeting GUI
// Denne implementasjonen håndterer program-tilstanden i Window-klassen
struct MeetingWindow : Graph_lib::Window
{
	static constexpr int pad = 4;
	static constexpr int btnW = 100;
	static constexpr int btnH = 20;
	static constexpr int fieldW = 200;
	static constexpr int fieldH = 20;
	static constexpr int fieldPad = 80;
	static constexpr int headerFontSize = 20;

	MeetingWindow(Point xy, int w, int h, const std::string& title);
	~MeetingWindow();
	void printPeople() const;

private:
	// Program-tilstand
	std::vector<Meeting*> meetings;
	std::vector<Person*> people;
	std::vector<Car*> cars;

	Text headerText;
	Button quitBtn;

	// Møte
	In_box meetingDay;
	In_box meetingStart;
	In_box meetingEnd;
	Choice meetingLocation;
	In_box meetingSubject;
	Choice meetingLeader;
	Button meetingNewBtn;
	std::vector<Widget*> meetingWidgets;

	// Møte-liste
	Multiline_out_box meetingData;

	// Person
	In_box personName;
	In_box personEmail;
	In_box personSeats;
	Button personNewBtn;
	std::vector<Widget*> personWidgets;

	// Person-liste
	Multiline_out_box personData;

	Menu pageMenu;

	void newMeeting();
	void newPerson();
	void showMeetingPage();
	void showPersonPage();
	void hideWidgets(std::vector<Widget*>& widgets);
	void quit();

	// Hjelpefunksjoner
	void attachMeetingWidget(Widget& mw);
	void attachPersonWidget(Widget& pw);
	void updateMeetingList();
	void updatePersonList();
	
	static void cb_quit(Address, Address pw);
	static void cb_new_meeting(Address, Address pw);
	static void cb_new_person(Address, Address pw);
	static void cb_meetings(Address, Address pw);
	static void cb_persons(Address, Address pw);
};
