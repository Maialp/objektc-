#pragma once
#include "Window.h"
#include "GUI.h"
#include "case.h"

using namespace Graph_lib;

class SearchWindow : public Window{
private:
    static constexpr int buttonWidth{100};
    static constexpr int buttonHeight{30};

    static constexpr int padW{50};
    static constexpr int padH{10};

    Button quitBtn;
    Button searchBtn;

    static void cb_quit(Address, Address pw);
    static void cb_search(Address, Address pw);

    void quit();
    void search();

    In_box firstName;
    In_box lastName;

    Multiline_out_box searchResult;

    set<Case*> caseSet; 
public:
    SearchWindow(Point xy, int width, int height, const string& title, set<Case*> caseSet); 
};