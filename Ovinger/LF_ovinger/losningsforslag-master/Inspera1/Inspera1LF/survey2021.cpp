#include "survey2021.h"

map<string, int> mapSurvey() {
    ifstream ifs{"survey_2021.txt"};
    if (!ifs) {
        error("Could not open input file");
    }
    map<string, int> answer_map;
    for (string s; ifs >> s;) {  // Mens det er svar igjen i filen, fortsett å lese
        ++answer_map[s];
    }
    return answer_map;
}
//Løsning med en lettere løkke: 
map<string, int> mapSurvey() {
    ifstream ifs{"survey_2021.txt"};
    if (!ifs) {
        error("Could not open input file");
    }
    map<string, int> answer_map;
    string s; 
    while(ifs >> s) {  // Mens det er svar igjen i filen, fortsett å lese
        ++answer_map[s];
    }
    return answer_map;
}

// Sorterer vektoren
vector<string> sortVector(map<string, int> m) {
    vector<string> sortedVector;
    // Les mappet så lenge det ikke er tomt
    while (!m.empty()) {
        int max_value = -1;
        string adjective;
        // Går igjennom hvert element og leser det (lagres i m)
        for (auto &elem : m) {
            if (elem.second > max_value) {
                max_value = elem.second;
                adjective = elem.first;
            }
        }
        m.erase(adjective);
        sortedVector.push_back(adjective);
    }
    return sortedVector;
}
//Man kan også bruke STL::sort() for å løse denne oppgaven. 

// Resultat av sorteringen
void surveyResults(const vector<string> &v, const map<string, int> &m) {
    // Åpner filen for skriving
    ofstream ofs{"survey_2021_results.txt"};
    if (!ofs) {
        error("Could not open file");
    }

    string element;
    // Går igjennom hvert element og legger det til fra den sorterte vektoren vår
    for (string adjective : v) {
        ofs << adjective << ", " << m.at(adjective) << endl;
    }
}