#include "std_lib_facilities.h"
#include "tests.h"
#include "utilities.h"

void testCallByValue(){
    int v0 = 5;
    int increment = 2;
    int iterations = 10; 
    int result = invrementByValueNumTimes(v0, increment, iterations);
    cout << "v0: " << v0 << endl
        << "increment: " << increment << endl
        << "iterations: " << iterations << endl
        << "result: " << result << endl;
}

void testCallByRefrence(){
    int v0 = 5;
    int increment = 2;
    int iterations = 10; 

    incrementByValueNumTimesRef(v0, increment, iterations);
    cout << "v0: " << v0 << endl
        << "increment: " << increment << endl
        << "iterations: " << iterations << endl;
}

void testString(){
    int numChar = 8;
    string grades = randomizeString(numChar, 'A', 'F');
    cout << "Dine karakterer er:" << grades << '\n';

    vector<int> gradeCount;
    for (char c = 'F'; c >= 'A'; c--){
        int antall = countChar(grades, c);
        gradeCount.push_back(antall);
    }

    int sum = 0;
    for (int i=0; i < gradeCount.size(); i++){
        sum += gradeCount[i]*i;
    }

    double snitt = sum / 8.0 ;
    cout << "Snitt: " << snitt << '\n';
}