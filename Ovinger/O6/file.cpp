#include "file.h"
#include "std_lib_facilities.h"
#include <iostream>
#include <string>

//Oppg 1 a) 

void readToFile(string fileName){
    ofstream myFile; 
    myFile.open(fileName, ios_base::app);
    if (!myFile){
        error("Cannot open file");
    }
    string leggTil = "";
    cout << "Legg til i tekstfil.txt: ";
    cin >> leggTil;

    while(leggTil != "quit"){
        myFile << leggTil << '\n';
        cout << "Legg til i tekstfil.txt: ";
        cin >> leggTil;
    }
}

//Oppg 1 b) 
void readFromFile(string fromFile, string toFile){
    ifstream myFile{fromFile};        //Åpner fila som skal leses fra 
    if (!myFile){
        error("Cannot open file");
    }
    ofstream endFile{toFile};         //Åpner fila som skal leses inn til
    if (!endFile){
        error("Cannot open file");
    }

    map<int, string> lineAndText;
    int count = 1;
    while (!myFile.eof()){      //Lager et map med alle linjene og tilhørende tekst på linja
        string fileLine; 
        myFile >> fileLine;
        lineAndText[count] = fileLine;
        count++;
    }
    for(auto s:lineAndText){
        endFile << s.first << ' ' << s.second << '\n';
    }
}

//Oppg 2 a)
vector<int> charCount(string fileName){
    vector<int> charCountVec(26, 0);

    ifstream myFile{fileName};
    if (!myFile){
        error("Cannot open file");
    }
    char c;

    while (!myFile.eof()){
        myFile >> c;
        if (tolower(c)>= 'a' && tolower(c)<= 'z'){
            charCountVec[tolower(c)-'a'] += 1 ;
        }
    }

    return charCountVec;
}

void printCharCount(vector<int> charCount){
    for(int i = 0; i < size(charCount); i++){
        if(i%3 == 0){
            cout << '\n';
        }
        char letter = 'a' + i;
        cout << letter << ": " << setw(5) <<charCount[i] << '\t';
    }
    cout << '\n';
}