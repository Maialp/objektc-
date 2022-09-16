#pragma once
#include "std_lib_facilities.h"
#include "meeting.h"
#include "GUI.h"
#include "Graph.h"

using namespace Graph_lib;

class MeetingWindow : public Window{
    private:
        static constexpr int pad = 45; 
        static constexpr int btnW = 100; 
        static constexpr int btnH = 50; 
        static constexpr int fieldW = 250; 
        static constexpr int fieldH = 25; 
        static constexpr int fieldPad = 100; 

        Button quitBtn;
        Button personNewBtn; 
        In_box personName;
        In_box personEmail;

        vector<Person*> people;

    public:
        MeetingWindow(Point xy, int w, int h, const string& title) : Window{xy, w, h, title}, 
        quitBtn{Point{2*fieldPad+fieldW,pad}, btnW, btnH, "Quit", this->cb_quit}, 
        personNewBtn{Point{fieldPad,(3*pad+2*fieldH)}, btnW, btnH, "Add person", this->cb_new_person},
        personName{Point{fieldPad,pad},fieldW, fieldH, "Name:"},
        personEmail{Point{fieldPad,2*pad+fieldH},fieldW, fieldH, "Email:"}
        {
            this->attach(quitBtn);
            this->attach(personName);
            this->attach(personEmail);
            this->attach(personNewBtn);
        }

        ~MeetingWindow();

        static void cb_quit(Address, Address pw); 
        static void cb_new_person(Address, Address pw);
        void addPerson();
        void printPeople();
};