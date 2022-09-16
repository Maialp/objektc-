#include "std_lib_facilities.h"
#include "Card.h"

//----------------Oppgave 1-----------------

string suitToString(Suit suit){
    return suitAndString.at(suit);
}
string rankToStrng(Rank rank){
    return rankAndString.at(rank);
}

//----------------Oppgave 2-----------------
Card::Card(Suit suit, Rank rank) : s{suit}, r{rank}{}
Suit Card::getSuit(){
    return s;
}
Rank Card::getRank(){
    return r;
}
string Card::toString(){
    return rankToStrng(r) + " of " + suitToString(s);
}
string Card::toStringShort(){
    char suit = suitToString(s).at(0);
    int rankInt = static_cast<int>(r);
    string rank = to_string(rankInt);
    return suit+rank;
}