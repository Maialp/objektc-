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
    attach(quitBtn);
    attach(searchBtn);

    attach(firstName);
    attach(lastName);
    attach(searchResult);
    //End task G1
} 

void SearchWindow::cb_quit(Address, Address pw){
    //Begin task G2
    reference_to<SearchWindow>(pw).quit();
    //End task G2
}

void SearchWindow::cb_search(Address, Address pw){
    //Begin task G3
    reference_to<SearchWindow>(pw).search();
    //End task G3
}

void SearchWindow::quit(){
    //Begin task G4
    hide();
    //End task G4
}

void SearchWindow::search(){
    //Begin task G5
    //one possible solution:
    string firstNameStr = firstName.get_string();
    string lastNameStr = lastName.get_string();
    
    firstName.clear_value();
    lastName.clear_value();

    stringstream searchStream;
    for(auto c : caseSet){
        searchStream << "From case " << c->getCaseNumber() << " - " << c->getCaseName() << ":\n";
        searchStream << "Client:\n";
        if((c->getClient()->getFirstName() == firstNameStr)||(c->getClient()->getLastName() == lastNameStr)){
            searchStream << *c->getClient() << "\n"; 
        }
        searchStream << "Suspects:\n";
        for(auto s : c->getSuspects()){
            if((s->getFirstName() == firstNameStr) || (s->getLastName() == lastNameStr)){
                if(s->isGuilty()){
                    searchStream << "GUILTY: ";
                }
                searchStream << *s << "\n\n";
            }
        }
        searchStream << "\n";
    }
    searchResult.put(searchStream.str());
    //End task G5
}
