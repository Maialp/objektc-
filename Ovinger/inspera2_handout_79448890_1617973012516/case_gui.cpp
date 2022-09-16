#include "case_gui.h"
#include <sstream>

SearchWindow::SearchWindow(Point xy, int width, int height, const string& title, set<Case*> caseSet) : 
        Window{xy, width, height, title}, 
        quitBtn{{width-(padW+buttonWidth), 2*padH}, buttonWidth, buttonHeight, "Quit", cb_quit},
        searchBtn{{(width-buttonWidth)/2, buttonHeight*4+padH}, buttonWidth, buttonHeight, "Search", cb_search},
        firstName{{padW*2, buttonHeight*2}, width-4*padW, buttonHeight, "First name:"},
        lastName{{padW*2, buttonHeight*3}, width-4*padW, buttonHeight, "Last name:"},
        searchResult{{padW*2, buttonHeight*6+2*padH}, width-4*padW, height-8*buttonHeight, "Search results:"},
        caseSet{caseSet}        
{
    //Begin task G1
        Window::attach(quitBtn);
        Window::attach(searchBtn);
        Window::attach(firstName);
        Window::attach(lastName);
        Window::attach(searchResult);

    //End task G1
} 

void SearchWindow::cb_quit(Address, Address pw){
    //Begin task G2
    quit();
    //End task G2
}

void SearchWindow::cb_search(Address, Address pw){
    //Begin task G3
    this->search();
    //End task G3
}

void SearchWindow::quit(){
    //Begin task G4
    Window::end();
    //End task G4
}

void SearchWindow::search(){
    //Begin task G5

    //End task G5
}
