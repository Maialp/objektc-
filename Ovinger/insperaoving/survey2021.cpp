#include "survey2021.h"

// Implement all the necessary functions as described in the task.

map<string,int> mapSurvey(string fileName){
    ifstream myFile{fileName};
    if (!myFile){
        error("Cannot open file");          //Åpner filen og sjekker at det faktisk er mulig å åpne den 
    }
    string word; 
    map<string,int> adjektiv; 
    while (myFile >> word){  //Itererer så lenge det er mer å lese i filen
        myFile >> word; 

        if(adjektiv[word]){ //Hvis denne finnes (denne er true)
            adjektiv[word] ++; //leggger på en verdi på den eksisterende verdien
        }
        else if (!adjektiv[word]){
            adjektiv.insert({word, 1});
        }
    }
    return adjektiv;
}
bool sortByVal(const pair<string, int> a, const pair<string, int> b){ //En funskjon som forteller hvodan jeg vil at den skal sammenligne to pairs
    return (a.second > b.second);  //returnerer true om adjektiv a er brukt flere ganger enn adjektiv b
}

vector<string> sortVector(map<string,int> mapName){
    vector<pair<string, int>> adjPairVec;
    for (auto s : mapName){
        adjPairVec.push_back(s.first, s.second); //Lagrer alle verdiene til adjektiv-mappet til en vektor
    }
    sort(adjPairVec.begin(), adjPairVec.end(), sortByVal); //Burker sortfunksjonen på vektoren min som inneholder pairs
    vector<string> adjVec;
    for (pair<string, int> p : adjPairVec){ //Legger så til de sorterte ordene i vektoren
        adjVec.push_back(p.first);
    }
    return adjVec;
}

void surveyResults(string fromFile, string toFile){
    //Henter et map som inneholder adjektiv med antall ganger brukt:
    map<string,int> adjMap = mapSurvey(fromFile);

    //henter en vektor som er sortert etter hvor mange ganger adjektivet ble brukt: 
    vector<string> adjSortVec = sortVector(adjMap);

    ofstream myFile{toFile};
    if (!myFile){
        error("Cannot open file"); //Sjekker at man kan skrive til den filen man ønsker å skrive til
    } 
    for(string s : adjSortVec){
        myFile << s << ", " << adjMap[s] << endl; //legger til adjektiv og antall ganger det ble brukt før den går på en ny linje og skirver neste
    }

}
