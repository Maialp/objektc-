#include "mastermind.h"
#include "std_lib_facilities.h"
#include "tests.h"
#include "utilities.h"
#include <string>
#include "masterVisual.h"

void playMastermind(){
    constexpr int size = 4;
    constexpr int letters = 6;
    int lives = 0;
    
    MastermindWindow mwin{Point{900, 20}, winW, winH, "Mastermind"};

    string code = randomizeString(size, 'A', 'F'); 
     for (int i = 0; i < size; ++i){
        mwin.vr.push_back(new Rectangle{Point{padX+(2*i*padX), 3*padY}, padX, padY});
        mwin.vr[mwin.vr.size()-1].set_fill_color(Color{code[i]-'A'+1});
        mwin.attach(mwin.vr[mwin.vr.size()-1]);
    }
    hideCode(mwin, size);
    
    mwin.redraw();
    
    
    string guess = mwin.getInput(size, 'A', 'F'); 
    addGuess(mwin, guess, size, 'A', lives);
    addFeedback(mwin, checkCharactersAndPosition(code, guess), ceckCharacters(code, guess), size, lives);
    
    mwin.redraw();
    

    while ((checkCharactersAndPosition(code, guess) != size) && (lives != 9)){
        cout << ceckCharacters(code, guess) << " riktige tegn, "<< checkCharactersAndPosition(code, guess)<< " rikige tegn på riktig plass.\n";
        guess = mwin.getInput(size, 'A', 'A'+ (letters -1));
        addGuess(mwin, guess, size, 'A', lives+1);
        addFeedback(mwin, checkCharactersAndPosition(code, guess), ceckCharacters(code, guess), size, lives);
        
        mwin.redraw();
        lives++;
    }
    if (checkCharactersAndPosition(code, guess) == size){
        cout << "Graulerer, du fant koden: " << code << '\n';
    }
    else{
        cout << "Beklager, du har ikke flere forsøk igjen\n";
    }
}


int checkCharactersAndPosition(string correct, string guess){
    int count = 0;
    for(int i = 0; i < correct.size(); i++){
        if (correct[i] == guess[i]){
            count++;
        }
    }
    return count;
}   

int ceckCharacters(string correct, string guess){
    int count = 0;
    for (char c = 'A'; c <= 'F'; c++){
        count+= min(countChar(guess, c), countChar(correct,c));
    }
    return count;
}