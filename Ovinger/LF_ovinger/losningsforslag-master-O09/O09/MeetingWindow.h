#pragma once

#include "AnimationWindow.h"
#include "Meeting.h"
#include "Person.h"

#include <string>
#include <vector>


// Meeting GUI
// Denne implementasjonen håndterer program-tilstanden i Window-klassen
struct MeetingWindow : TDT4102::AnimationWindow
{
	static constexpr int pad = 4;
	static constexpr int btnW = 100;
	static constexpr int btnH = 20;
	static constexpr int fieldW = 200;
	static constexpr int fieldH = 20;
	static constexpr int fieldPad = 80;
	static constexpr int headerFontSize = 20;

	MeetingWindow(Point position, int width, int height, const std::string& title);
	~MeetingWindow();
	void printPeople() const;

private:
	// Program-tilstand
	std::vector<unique_ptr<Meeting>> meetings;
	std::vector<shared_ptr<Person>> people;

	//Text headerText;
	Fl_Button quitBtn;

	// Møte
	Fl_Input meetingDay;
	Fl_Input meetingStart;
	Fl_Input meetingEnd;
	Fl_Choice meetingLocation;
	Fl_Input meetingSubject;
	Fl_Choice meetingLeader;
	Fl_Button meetingNewBtn;
	// Vi kan ha en vector her av vanlige pekere fordi alle verdiene som lagres innenfor vectoren er medlemsvariabler i denne klassen
	// Dermed fjernes denne vectoren på samme tid som inneholdet av vectoren, som betyr at eierskapet av minnet er løst.
	std::vector<Fl_Widget*> meetingWidgets;

	// Møte-liste
	Fl_Multiline_Output meetingData;

	// Person
	Fl_Input personName;
	Fl_Input personEmail;
	Fl_Input personSeats;
	Fl_Button personNewBtn;
	std::vector<Fl_Widget*> personWidgets;

	// Person-liste
	Fl_Multiline_Output personData;

	Fl_Button createMeetingButton;
	Fl_Button createPersonButton;

	void newMeeting();
	void newPerson();
	void showMeetingPage();
	void showPersonPage();
	void hideWidgets(std::vector<Fl_Widget*>& widgets);
	void quit();

	// Hjelpefunksjoner
	void attachMeetingWidget(Fl_Widget& mw);
	void attachPersonWidget(Fl_Widget& pw);
	void updateMeetingList();
	void updatePersonList();
	
	static void cb_quit(Fl_Widget*, void* pw);
	static void cb_new_meeting(Fl_Widget*, void* pw);
	static void cb_new_person(Fl_Widget*, void* pw);
	static void cb_meetings(Fl_Widget*, void* pw);
	static void cb_persons(Fl_Widget*, void* pw);
};
