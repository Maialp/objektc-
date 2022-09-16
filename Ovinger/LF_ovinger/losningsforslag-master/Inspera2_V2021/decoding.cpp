#include "decoding.h"

#include <iostream>
#include <fstream>
#include <algorithm>

	
void decoding(string inFileName, string outFileName){
    //Begin task K1
    //one possible solution:
    ifstream inFile{inFileName};
    if(!inFile){
        throw "Could not open inFile named: " + inFileName;
    }

    ofstream outFile{outFileName};
    if(!outFile){
        throw "Could not open outFile named: " + outFileName;
    }

    char start;
    char end;
    char temp;
    inFile >> start >> temp >> temp >> end;
    int shift = end - start;

    string line;
    char lowerShift = 'a' + shift;
    char upperShift = 'A' + shift;
    while(getline(inFile, line)){
        for(int i = 0; i < line.length(); ++i){
            if(isalpha(line[i])){
                if((islower(line[i])&& line[i] >= lowerShift) || (isupper(line[i])&& line[i] >= upperShift)){
                    line[i] -= shift;
                }
                else{
                    line[i] -= shift - 'z' + 'a' - 1;
                }
            }
        }
        outFile << line << endl;
    }

    //End task K1
}
