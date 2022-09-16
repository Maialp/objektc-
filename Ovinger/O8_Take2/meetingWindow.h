#pragma once
#include "meeting.h"
#include "GUI.h"
#include "Window.h"

using namespace Graph_lib;

class MeetingWindow : public Window{
    static constexpr int pad = 20;
    static constexpr int btnW = 80;
    static constexpr int btnH = 40;
    static constexpr int fieldW = 10*20;
    static constexpr int fieldH = 30;

    Button quit_btn;
    Button personNewBtn;

    In_box personName;
    In_box personEmail;
    In_box personSeats;

    Multiline_out_box data;

    Menu pageMenu;

    vector<Person*> people;
    vector<Car*> cars;
public:
    MeetingWindow(Point xy, int w, int h, const string& title);
    ~MeetingWindow();
    static void cb_quit(Address, Address pw);
    static void cb_new_person(Address, Address pw);
    static void cb_persons(Address, Address pw);
    static void cb_meetings(Address, Address pw);
    void addPerson();
    void displayPeople();
    void showPersonPage();
    void showMeetingPage();
};