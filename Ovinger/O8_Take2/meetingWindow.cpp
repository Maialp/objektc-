#include "meetingWindow.h"
#include <iostream>

MeetingWindow::MeetingWindow(Point xy, int w, int h, const string& title)
        : Window(xy,w,h,title), quit_btn{{w-pad-btnW,pad},btnW,btnH,"Quit",cb_quit}, 
        personNewBtn({3*pad,4*pad+3*fieldH},    btnW, btnH, "Add person", cb_new_person),
        personName  ({3*pad,pad},               fieldW,fieldH, "Name: "), 
        personEmail ({3*pad,2*pad+fieldH},      fieldW,fieldH,"Email: "),
        personSeats ({3*pad,3*pad+2*fieldH},    fieldW, fieldH, "Seats: "),
        data        ({3*pad,5*pad+3*fieldH+btnH},w-6*pad,h-(6*pad+3*fieldH+btnH), "Info:"),
        pageMenu    ({0,0},                     w,pad, Menu::horizontal, "Menu") {
    
    //Person window:
    this->attach(quit_btn);
    this->attach(personNewBtn);
    this->attach(personName);
    this->attach(personEmail);
    this->attach(personSeats);
    this->attach(data);
    this->attach(pageMenu);

    pageMenu.attach(new Button{{0,0},btnW,pad,"People",cb_persons});
    pageMenu.attach(new Button{{btnW,0}, btnW,btnH,"Meetings",cb_meetings});
    
}


void MeetingWindow::addPerson(){
    string name = personName.get_string();
    string email = personEmail.get_string();
    int freeSeats = personSeats.get_int();
    if((name != "") && (email != "")){
        if(freeSeats>0){
            Car* car = new Car{freeSeats};
            cars.push_back(car);
            car->reserveFreeSeat(); //reservere plass til sjåføren
            this->people.push_back(new Person(name,email,car));
        }
        else{
            this->people.push_back(new Person(name,email));
            personName.clear_value();
        }
        personEmail.clear_value();
        personName.clear_value();
        personSeats.clear_value();
    }
    displayPeople();
}

MeetingWindow::~MeetingWindow(){
    for(auto p : people){
        delete p;
    }
    for(auto c : cars){
        delete c;
    }
}

void MeetingWindow::displayPeople(){
    string names = "";
    for(Person* p : this->people){
        names += (p->getName() + '\n');
    }
    data.put(names);
}

void MeetingWindow::showPersonPage(){
    quit_btn.show();
    personNewBtn.show();
    personName.show();
    personEmail.show();
    personSeats.show();
    displayPeople();
}

void MeetingWindow::showMeetingPage(){
    quit_btn.hide();
    personNewBtn.hide();
    personName.hide();
    personEmail.hide();
    personSeats.hide();

}

void MeetingWindow::cb_new_person(Address, Address pw){
    reference_to<MeetingWindow>(pw).addPerson();
}

void MeetingWindow::cb_quit(Address, Address pw){
    reference_to<MeetingWindow>(pw).hide();
}

void cb_persons(Address, Address pw){
    reference_to<MeetingWindow>(pw).showPersonPage();
}

void cb_meetings(Address, Address pw){
    reference_to<MeetingWindow>(pw).showMeetingPage();
}