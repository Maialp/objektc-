#include "file.h"

void testWriteToFile(){
    //Begin task F2
    try{
        writeToFile("testFile.txt", "Pirater, sjøreøver og kanelbolle");
    }
    catch(const runtime_error& e){
        cerr << e.what() << '\n';
    }
    //End task F2
}