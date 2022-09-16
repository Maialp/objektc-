#include "file.h"

void testWriteToFile(){
    //Begin task F2
    //one possible solution:
    try{
        writeToFile("testFile.txt", "Dinosaurer, elkraft og pirater");
    }
    catch(const runtime_error& e){
        cerr << e.what() << '\n';
    }
    //End task F2
}