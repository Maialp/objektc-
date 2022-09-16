#include "iterator.h"
#include "person.h"
#include "LinkedList.h"
#include "templates.h"

int main(){
    srand(static_cast<unsigned int>(time(nullptr)));

	vector<string> b{"one", "two", "three", "four"};
    printVec(b);
    shuffle(b); 
    printVec(b);

};
