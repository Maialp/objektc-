#include "std_lib_facilities.h"
#include "utilities.h"
#include "tests.h"

#include "stdio.h"
#include "stdlib.h"
#include "time.h"

int invrementByValueNumTimes(int startValue, int increment, int numTimes){
    for (int i = 0; i < numTimes; ++i){
        startValue += increment;
    }
    return startValue;
}

void incrementByValueNumTimesRef(int& startValue, int increment, int numTimes){
    for (int i = 0; i < numTimes; ++i){
        startValue += increment;
    }
}

void swapNumbers(int& number1, int& number2){
    int num3 = number1;
    number1 = number2;
    number2 = num3;
}

void printStudent(Student stud){
    cout << "Navn: " << stud.name << '\n';
    cout << "Studieprogram: " << stud.studyProgram << '\n';
    cout << "Alder: " << stud.age << '\n';
}

bool inInProgram(Student stud, string program){
    if (stud.studyProgram == program){
        return true;
    }
    else {
        return false;
    }
}

string randomizeString(unsigned int size, const char start, const char end){
    string random_string{""};
    for (unsigned int i = 0; i < size; ++i){
        char c = start + rand()%(end-start+1);
        random_string.push_back(c);
    }
    return random_string;
}

string readInputToString(unsigned int n, const char start, const char end){
    string filledString = "";
    for(int i = 0; i < n;++i){
        char c = 'a';
        cout << "Skriv inn en bokstav mellom " << start << " og " << end<< ": ";
        cin >> c; 

        if ((tolower(c) >= tolower(start)) && (tolower(c) <= tolower(end))){
            filledString.push_back(toupper(c));
        }
        else {
            cout << "Det du skrev inn ble ikke godkjent. ";
            i--;
        }
    }
    return filledString;
}

int countChar(string streng, char bokstav){
    int antall = 0;
    for (char c : streng){
        if (tolower(c)==tolower(bokstav)){
            antall++;
        }
    }
    return antall;
}
