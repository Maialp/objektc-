#pragma once 
#include <cstdlib> 
#include <ctime> 
#include <iostream>
#include <vector>

template<typename T>
T maximum(T a, T b){
    if (a<b) {return b;}
    else {return a;}
}

template<typename T>
void shuffle(std::vector<T>& v){
    for (unsigned int i = 0; i < v.size(); i++){
        int j = rand() % v.size();
        T a = v[i];
        T b = v[j];
        v[i] = b;
        v[j] = a;
    }
}

template<typename T>
void printVec(std::vector<T> v){
    for(int i = 0; i < v.size(); i++){
        std::cout<<v[i]<< "  ";
    }
    std::cout<<std::endl;
}