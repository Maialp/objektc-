#include "std_lib_facilities.h"

//Declare relevant functions for the task. 
map<string,int> mapSurvey(string fileName);

bool sortByVal(const pair<string, int> a, const pair<string, int> b);
vector<string> sortVector(map<string,int> mapName);

void surveyResults(string fromFile, string toFile);