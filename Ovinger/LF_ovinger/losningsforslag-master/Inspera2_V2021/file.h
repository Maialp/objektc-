#pragma once
#include "fstream"
#include "case.h"

template<typename T>
void writeToFile(string fileName, const T& object){
//Begin task F1
    //one possible solution:
    ofstream outFile{fileName};
    if(!outFile){
        throw runtime_error("Could not open file: " + fileName);
    }

    outFile << object;
//End task F1
}

void testWriteToFile();