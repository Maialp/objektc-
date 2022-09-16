#include "temps.h"

istream& operator>>(istream& is, Temps& t){
    is >> t.max >> t.min;
    return is;
}

vector<Temps> readTemps(string fileName){
    ifstream myFile{fileName};

    if (!myFile){
        error("Cannot open file");
    }
    vector<Temps> tempsVector; 
    Temps t; 

    while (!myFile.eof()){
        //operator>>(myFile, t);
        myFile>>t;
        tempsVector.push_back(t);
    }
    return tempsVector;
}

void tempStats(vector<Temps> tempVec){
    int warmestDay = 1; 
    int coldestDay = 1; 
    double maxTemp = tempVec[0].max; 
    double minTemp = tempVec[0].min; 

    for(int i = 1; i < tempVec.size();i++){
        if (tempVec[i].max > maxTemp){
            maxTemp = tempVec[i].max;
            warmestDay = i;
        }
        if (tempVec[i].min < minTemp){
            minTemp = tempVec[i].min;
            coldestDay = i;
        }
    }

    cout << "Day "<<warmestDay<<" was the wormest day, with " << maxTemp<<" degrees.\n";
    cout <<"Day "<<coldestDay<<" was the coldest day, with " << minTemp<<" degrees.\n";
}