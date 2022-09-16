#pragma once 
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <set>

using namespace std;



//Iteratorer for vektorer
void printStringVec(vector<string> stringVec);

void reverseStringVec(vector<string> stringVec);

void replaceStringVec(vector<string> &stringVec, string old, string replace);


//Iteratorer for set
void printStringSet(set<string> s);

void reverseSet(set<string> s);

void replaceStringSet(set<string>& s, string old, string replacement);