#include "fibonacci.h"

void fillInFibonacciNumbers(int result[], int length){
    int a = 0;
    int b = 1;
    for(int i = 0; i < length; ++i){
        if(i == 0){
            result[i]=a;
        }
        else if(i == 1){
            result[i] = b;
        }
        else{
            result[i] = result[i-1]+result[i-2];
        }
    }
}

void printArray(int arr[], int length){
    for(int i=0; i<length; i++){
		cout << arr[i] << endl;
	}
}

void createFibonacci(){
    int length; 
    cout << "Antall fibonaccitall: ";
    cin >> length;
    
    int* fibonaccitall = new int[length];
    
    fillInFibonacciNumbers(fibonaccitall, length);
    printArray(fibonaccitall, length);
    
    delete[] fibonaccitall;
}