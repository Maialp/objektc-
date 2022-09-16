#pragma once
#include "fstream"
#include "case.h"

template<typename T>
void writeToFile(string fileName, const T& object){
//Begin task F1
    ofstream of;
    if (of){
        of<<object;
    }
//End task F1
}

void testWriteToFile();