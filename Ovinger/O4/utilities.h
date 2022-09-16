#pragma once

int invrementByValueNumTimes(int startValue, int increment, int numTimes);

void incrementByValueNumTimesRef(int& startValue, int increment, int numTimes);

void swapNumbers(int& number1, int& number2);


// --------Oppgave 2-----------
struct Student{
    string name; 
    string studyProgram;
    int age; 
};

void printStudent(Student stud);

bool inInProgram(Student stud, string program);

string randomizeString(unsigned int size, const char start, const char end);

string readInputToString(unsigned int n, const char start, const char end);

int countChar(string streng, char bokstav);