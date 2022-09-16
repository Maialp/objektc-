#include "MeetingWindow.h"
#include <iostream>
#include <FL/fl_ask.H>

void showErrorMessage(const std::string &message) {
	fl_alert("%s", message.c_str());
}

MeetingWindow::MeetingWindow(Point position, int width, int height, const string& title)
	: AnimationWindow{position.x, position.y, width, height, title},
	//headerText{pad, fieldH, "Meetings" },

	quitBtn{width - btnW - pad, pad + fieldH, btnW, btnH, "Quit" },

	meetingDay      {fieldPad, pad + fieldH   	 , fieldW, btnH, "Day" },
	meetingStart    {fieldPad, (pad + fieldH) * 2, fieldW, btnH, "Start time" },
	meetingEnd      {fieldPad, (pad + fieldH) * 3, fieldW, btnH, "End time" },
	meetingLocation {fieldPad, (pad + fieldH) * 4, fieldW, btnH, "Location" },
	meetingSubject  {fieldPad, (pad + fieldH) * 5, fieldW, btnH, "Subject" },
	meetingLeader   {fieldPad, (pad + fieldH) * 6, fieldW, btnH, "Leader" },
	meetingNewBtn   {fieldPad, (pad + fieldH) * 7, btnW, btnH, "Add meeting" },
	meetingData     {pad, (pad + fieldH) * 8     , width - pad * 2, fieldW * 2, "All meetings" },

	personName      {fieldPad, pad + fieldH    	 , fieldW, btnH, "Name" },
	personEmail     {fieldPad, (pad + fieldH) * 2, fieldW, btnH, "Email" },
	personSeats   	{fieldPad, (pad + fieldH) * 3, fieldW, btnH, "Car seats" },
	personNewBtn    {fieldPad, (pad + fieldH) * 4, btnW, btnH, "Add person" },
	personData      {pad, (pad + fieldH) * 5     , width - pad * 2, fieldW * 2, "All persons"},

	createMeetingButton {width - btnW - pad, (pad + fieldH) * 2, btnW, btnH, "Meetings"}, 
	createPersonButton {width - btnW - pad, (pad + fieldH) * 2, btnW, btnH, "Persons"}
{
	// Felles
	add(quitBtn);
	//attach(headerText);

	// Nytt møte
	attachMeetingWidget(meetingDay);
	attachMeetingWidget(meetingStart);
	attachMeetingWidget(meetingEnd);
	attachMeetingWidget(meetingLocation);
	attachMeetingWidget(meetingSubject);
	attachMeetingWidget(meetingLeader);
	attachMeetingWidget(meetingNewBtn);
	attachMeetingWidget(createPersonButton);

	quitBtn.callback(cb_quit, this);
	meetingNewBtn.callback(cb_new_meeting, this);
	personNewBtn.callback(cb_new_person, this);
	createMeetingButton.callback(cb_meetings, this);
	createPersonButton.callback(cb_persons, this);

	for (auto c : campusToString)
		meetingLocation.add(c.second.c_str());

	// Møte-liste
	attachMeetingWidget(meetingData);

	// Ny person
	attachPersonWidget(personName);
	attachPersonWidget(personEmail);
	attachPersonWidget(personSeats);
	attachPersonWidget(personNewBtn);
	attachPersonWidget(createMeetingButton);

	// Person-liste
	attachPersonWidget(personData);

	// Initielt vindu
	showMeetingPage();
	// headerText.set_label("Meetings"); // Dette er allerede gjort i konstruktøren til headerText
	//headerText.set_font_size(headerFontSize);
}

MeetingWindow::~MeetingWindow() {}

int getIntegerValue(string value, string nameOfField) {
	int interpretedValue = 0;
	try {
		interpretedValue = stoi(value);
	}
	catch(std::invalid_argument& exception){
		string errorMessage = "Failed to read the value from the field: " + nameOfField;
		showErrorMessage(errorMessage);
	}
	catch(std::out_of_range& exception){
		string errorMessage = "Failed to read the value from the field: " + nameOfField;
		showErrorMessage(errorMessage);
	}
	return interpretedValue;
}

void MeetingWindow::newMeeting()
{
	int day = getIntegerValue(meetingDay.value(), "day");
	int start = getIntegerValue(meetingStart.value(), "start time");
	int end = getIntegerValue(meetingEnd.value(), "end time");
	
	Campus campus = static_cast<Campus>(meetingLocation.value());
	const string subject = meetingSubject.value();
	int leaderId = meetingLeader.value();

	if(day < 1 || 31 < day) {
		showErrorMessage("The entered day is not in any month");
		return;
	}

	if(start < 0 || 23 < start) {
		showErrorMessage("The start time is not an hour of the day");
		return;
	}

	if(end < start) {
		showErrorMessage("The end time is before the start time");
		return;
	}

	if(subject.empty()) {
		showErrorMessage("The subject is empty");
		return;
	}

	if(leaderId < 0) {
		showErrorMessage("The meeting has no leader");
		return;
	}

	meetingDay.value("");
	meetingStart.value("");
	meetingEnd.value("");
	meetingSubject.value("");
	meetingLeader.value(0);

	shared_ptr<Person> leader = people.at(leaderId);
	meetings.emplace_back(new Meeting{ day, start, end, campus, subject, leader});

	updateMeetingList();
}

void MeetingWindow::newPerson()
{
	int freeSeetCount = getIntegerValue(personSeats.value(), "Free seats");
	
	Car* carInstanceOrNullptr = nullptr;
	if (freeSeetCount != 0) {
		carInstanceOrNullptr = new Car{ freeSeetCount } ;
	}
	std::unique_ptr<Car> car {carInstanceOrNullptr};

	const string& name = personName.value();
	const string& email = personEmail.value();
	
	if (name.empty()) {
		showErrorMessage("The name field is empty");
		return;
	}

	if (name.empty()) {
		showErrorMessage("The e-mail field is empty");
		return;
	}

	personSeats.value("");
	personName.value("");
	personEmail.value("");

	people.emplace_back(new Person{ name, email, std::move(car) });
	meetingLeader.add(people.back()->getName().c_str());
	updatePersonList();
}

void MeetingWindow::showMeetingPage()
{
	hideWidgets(personWidgets);
	//headerText.set_label("Meetings");

	for (auto* mw : meetingWidgets) {
		mw->show();
	}
}

void MeetingWindow::showPersonPage()
{
	hideWidgets(meetingWidgets);
	//headerText.set_label("Persons");

	for (auto* pw : personWidgets) {
		pw->show();
	}
}

void MeetingWindow::hideWidgets(vector<Fl_Widget*>& widgets)
{
	for (auto* w : widgets) {
		w->hide();
	}
}

void MeetingWindow::updateMeetingList()
{
	stringstream ss;
	for (auto &m : meetings) {
		ss << *m << endl;
	}
	meetingData.value(ss.str().c_str());
}

void MeetingWindow::updatePersonList()
{
	stringstream ss;
	for (auto &p : people) {
		ss << *p << endl;
	}
	personData.value(ss.str().c_str());
}

void MeetingWindow::attachMeetingWidget(Fl_Widget& mw)
{
	add(mw);
	meetingWidgets.push_back(&mw);
}

void MeetingWindow::attachPersonWidget(Fl_Widget& pw)
{
	add(pw);
	personWidgets.push_back(&pw);
}


void MeetingWindow::quit()
{
	hide();
}

// Callbackfunksjoner
void MeetingWindow::cb_quit(Fl_Widget*, void* pw)
{
	static_cast<MeetingWindow*>(pw)->quit();
}

void MeetingWindow::cb_new_meeting(Fl_Widget*, void* pw)
{
	static_cast<MeetingWindow*>(pw)->newMeeting();
}

void MeetingWindow::cb_new_person(Fl_Widget*, void* pw)
{
	static_cast<MeetingWindow*>(pw)->newPerson();
}

void MeetingWindow::cb_meetings(Fl_Widget*, void* pw)
{
	static_cast<MeetingWindow*>(pw)->showMeetingPage();
}

void MeetingWindow::cb_persons(Fl_Widget*, void* pw)
{
	static_cast<MeetingWindow*>(pw)->showPersonPage();
}

void MeetingWindow::printPeople() const {
	for (const auto &person : people) {
		std::cout << *person << endl;
	}
}

