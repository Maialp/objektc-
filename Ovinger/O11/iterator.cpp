#include "iterator.h"

//Iteratorer for vektorer
void printStringVec(vector<string> stringVec){
    for(vector<string>::iterator it = stringVec.begin(); it!=stringVec.end(); it++){
        cout<<*it<<'\t';
    }
    cout<<'\n';
}

void reverseStringVec(vector<string> v){
    for(vector<string>::reverse_iterator it = v.rbegin(); it != v.rend(); it++){
        cout << *it <<'\t';
    }
    cout << endl;
}

void replaceStringVec(vector<string> &stringVec, string old, string replacement){
    for (vector<string>::iterator it = stringVec.begin(); it!=stringVec.end(); it++){
        if (*it == old){
            stringVec.erase(it);
            stringVec.insert(it, replacement);
        }
    }
}


//Iteratorer for sets
void printStringSet(set<string> s){
    for(set<string>::iterator it=s.begin(); it!=s.end(); it++){
        cout << *it <<'\t';
    }
    cout << endl;
}

void reverseSet(set<string> s){
    for(set<string>::reverse_iterator it = s.rbegin(); it!=s.rend(); it++){
        cout << *it <<'\t';
    }
    cout<< endl;
} 

void replaceStringSet(set<string> &s, string old, string replacement){
    for(set<string>::iterator it=s.begin(); it!=s.end(); it++){
        if (*it == old){
            it = s.erase(it);
            it = s.insert(it, replacement);
        }
    }
}