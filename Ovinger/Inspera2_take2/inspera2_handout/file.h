#pragma once
#include "fstream"
#include "case.h"

template<typename T>
void writeToFile(string fileName, const T& object){
//Begin task F1
    ofstream myFile{fileName};
    if (!myFile) throw runtime_error{"Couldn't open file " + fileName};
    myFile << object;
//End task F1
}

void testWriteToFile();