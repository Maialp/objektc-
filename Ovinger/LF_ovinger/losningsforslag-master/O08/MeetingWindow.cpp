#include "MeetingWindow.h"
#include <iostream>

MeetingWindow::MeetingWindow(Point xy, int w, int h, const string& title)
	: Graph_lib::Window{xy, w, h, title},
	headerText{ Point{pad, fieldH}, "Meetings" },

	quitBtn{ Point{x_max() - btnW - pad, pad + fieldH}, btnW, btnH, "Quit", cb_quit },

	meetingDay      { Point {fieldPad, pad + fieldH   	 }, fieldW, btnH, "Day" },
	meetingStart    { Point {fieldPad, (pad + fieldH) * 2}, fieldW, btnH, "Start time" },
	meetingEnd      { Point {fieldPad, (pad + fieldH) * 3}, fieldW, btnH, "End time" },
	meetingLocation { Point {fieldPad, (pad + fieldH) * 4}, fieldW, btnH, "Location" },
	meetingSubject  { Point {fieldPad, (pad + fieldH) * 5}, fieldW, btnH, "Subject" },
	meetingLeader   { Point {fieldPad, (pad + fieldH) * 6}, fieldW, btnH, "Leader" },
	meetingNewBtn   { Point {fieldPad, (pad + fieldH) * 7}, btnW, btnH, "Add meeting", cb_new_meeting },
	meetingData     { Point {pad, (pad + fieldH) * 8     }, x_max() - pad * 2, fieldW * 2, "All meetings" },

	personName      { Point {fieldPad, pad + fieldH    	 }, fieldW, btnH, "Name" },
	personEmail     { Point {fieldPad, (pad + fieldH) * 2}, fieldW, btnH, "Email" },
	personSeats   	{ Point {fieldPad, (pad + fieldH) * 3}, fieldW, btnH, "Car seats" },
	personNewBtn    { Point {fieldPad, (pad + fieldH) * 4}, btnW, btnH, "Add person", cb_new_person },
	personData      { Point {pad, (pad + fieldH) * 5     }, x_max() - pad * 2, fieldW * 2, "All persons" },

	pageMenu      	{ Point {x_max() - btnW - pad, (pad + fieldH) * 2}, btnW, btnH, Menu::vertical, "Layout menu" }
{
	// Felles
	attach(quitBtn);
	attach(headerText);

	// Nytt møte
	attachMeetingWidget(meetingDay);
	attachMeetingWidget(meetingStart);
	attachMeetingWidget(meetingEnd);
	attachMeetingWidget(meetingLocation);
	attachMeetingWidget(meetingSubject);
	attachMeetingWidget(meetingLeader);
	attachMeetingWidget(meetingNewBtn);

	for (auto c : campusToString)
		meetingLocation.add(c.second);

	// Møte-liste
	attachMeetingWidget(meetingData);

	// Ny person
	attachPersonWidget(personName);
	attachPersonWidget(personEmail);
	attachPersonWidget(personSeats);
	attachPersonWidget(personNewBtn);

	// Person-liste
	attachPersonWidget(personData);

	// Meny
	pageMenu.attach(new Button{ Point{0, 0}, 0, 0, "Meetings", cb_meetings });
	pageMenu.attach(new Button{ Point{0, 0}, 0, 0, "Persons", cb_persons });
	attach(pageMenu);

	// Initielt vindu
	showMeetingPage();
	// headerText.set_label("Meetings"); // Dette er allerede gjort i konstruktøren til headerText
	headerText.set_font_size(headerFontSize);
}

MeetingWindow::~MeetingWindow()
{
	for (auto* m : meetings) {
		delete m;
	}

	for (auto* p : people) {
		delete p;
	}

	for (auto* c : cars) {
		delete c;
	}
}

void MeetingWindow::newMeeting()
{
	int day = meetingDay.get_int();
	int start = meetingStart.get_int();
	int end = meetingEnd.get_int();
	
	Campus campus = static_cast<Campus>(meetingLocation.value());
	const string subject = meetingSubject.get_string();
	int leaderId = meetingLeader.value();

	meetingDay.clear_value();
	meetingStart.clear_value();
	meetingEnd.clear_value();
	meetingSubject.clear_value();
	meetingLeader.clear_value();

	if (day < 1 || 31 < day || start < 0 || 23 < start || end < start || subject.empty() || leaderId < 0)
	{
		cerr << "Not enough information to add meeting.\n";
		return;
	}

	const Person* leader = people[leaderId];
	meetings.push_back(new Meeting{ day, start, end, campus, subject, leader });

	updateMeetingList();
}

void MeetingWindow::newPerson()
{
	Car* car = nullptr;
	if (personSeats.get_int() != 0) {
		car = new Car{ personSeats.get_int() };
		car->reserveFreeSeat(); // Sjåføren må ha plass
		cars.push_back(car);
	}
	
	const string& name = personName.get_string();
	const string& email = personEmail.get_string();

	personSeats.clear_value();
	personName.clear_value();
	personEmail.clear_value();
	
	if (name.empty() || email.empty()) {
		cerr << "Not enough information to add person.\n";
		return;
	}

	people.push_back(new Person{ name, email, car });
	meetingLeader.add(people.back()->getName());
	updatePersonList();
}

void MeetingWindow::showMeetingPage()
{
	hideWidgets(personWidgets);
	headerText.set_label("Meetings");

	for (auto* mw : meetingWidgets) {
		mw->show();
	}
}

void MeetingWindow::showPersonPage()
{
	hideWidgets(meetingWidgets);
	headerText.set_label("Persons");

	for (auto* pw : personWidgets) {
		pw->show();
	}
}

void MeetingWindow::hideWidgets(vector<Widget*>& widgets)
{
	for (auto* w : widgets) {
		w->hide();
	}
}

void MeetingWindow::updateMeetingList()
{
	stringstream ss;
	for (auto* m : meetings) {
		ss << *m << '\n';
	}
	meetingData.put(ss.str());
}

void MeetingWindow::updatePersonList()
{
	stringstream ss;
	for (auto* p : people) {
		ss << *p << '\n';
	}
	personData.put(ss.str());
}

void MeetingWindow::attachMeetingWidget(Widget& mw)
{
	attach(mw);
	meetingWidgets.push_back(&mw);
}

void MeetingWindow::attachPersonWidget(Widget& pw)
{
	attach(pw);
	personWidgets.push_back(&pw);
}


void MeetingWindow::quit()
{
	hide();
}

// Callbackfunksjoner
void MeetingWindow::cb_quit(Address, Address pw)
{
	// static_cast<MeetingWindow*>(pw)->quit();
	reference_to<MeetingWindow>(pw).quit();
}

void MeetingWindow::cb_new_meeting(Address, Address pw)
{
	reference_to<MeetingWindow>(pw).newMeeting();
}

void MeetingWindow::cb_new_person(Address, Address pw)
{
	reference_to<MeetingWindow>(pw).newPerson();
}

void MeetingWindow::cb_meetings(Address, Address pw)
{
	reference_to<MeetingWindow>(pw).showMeetingPage();
}

void MeetingWindow::cb_persons(Address, Address pw)
{
	reference_to<MeetingWindow>(pw).showPersonPage();
}

void MeetingWindow::printPeople() const {
	for (const auto* person : people) {
		std::cout << *person << '\n';
	}
}
