#include "meetingWindow.h"

void MeetingWindow::cb_quit(Address, Address pw) {
    reference_to<MeetingWindow>(pw).hide();
}
void MeetingWindow::cb_new_person(Address, Address pw){
    reference_to<MeetingWindow>(pw).addPerson();
}


void MeetingWindow::addPerson(){
    string name = personName.get_string();
    string email = personEmail.get_string();
    if ((name != "") && (email != "")){
        people.push_back(new Person{name, email});
    }
    personName.clear_value();
    personEmail.clear_value();
}

MeetingWindow::~MeetingWindow(){
    for (Person* p : people){
        delete p;
    }
}

void MeetingWindow::printPeople(){
    cout << endl<<"Participants: \n";
    for(Person* p : people){
        cout << p->getName() << ", ";
    }
    cout << endl<<endl;
}