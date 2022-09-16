//Oppgave 1

//a) Oversett kodensutt til Python
//def isFibonacciNumber(n):
//		a = 0
//		b = 0
// 		while b < n:
//			temp = b
// 			b += a
// 			a = temp
//		return bool(b == n)

#include "std_lib_facilities.h"

//Oppgave 2: Oversett kode fra Python til c++

// a) Største av to tall
int maxOfTwo(int a, int b) {
	if (a>b) {
		cout << a <<" is grater than " << b<< endl;
		return a;
	}
	else{
		cout << b <<" is grater than or equal to A " << a << endl;
		return b;
	}
}

//c) Fibonacci-rekker
int fibonacci(int n) {
	int a = 0;
	int b = 1;
	cout << "Fibonacci numbers \n";
	for(int x = 1; x < n+1; ++x){
		cout << x << '\t' << b <<'\n';
		int temp = b;
		b += a;
		a = temp;
	}
	cout << "----\n";
	return b; 
}

//d) Sum av kvadrerte tall
int squereNumberSum(int n) {
	int totalSum = 0;
	for(int i = 1; i < n; ++i) {
		totalSum += i*i;
		cout << i*i << '\t';
	}
	cout << '\n' << totalSum << '\n';
	return totalSum;
}


//e) Trekanttall
void triangleNumbersBelow(int n) {
	int acc = 1;
	int num = 2;
	cout << "Triangle numbers below " << n << ": \n";
	while (acc < n) {
		cout << acc << '\n';
		acc += num;
		num += 1;

	}
	cout << '\n';
}

//f) Primtall 1
bool isPrime(int n) {
	for(int j = 2; j <= n; ++j) {
		if(n%j==0) {
			return false; 
		}
		else {
			return true;
		}
	}
	return false;
}

//g) Primtall 2
void naivePrimeNumberSearch(int n){
	for(int number = 2; number <= n; ++number){
		if (isPrime(number)){
			cout << number << " is a prime \n";
		}
	}
}

//h) Største nevner mindre enn tallet selv
int findGratestDivisor(int n) {
	for(int divisor = n-1; divisor >= 0; divisor+=(-1)){
		if(n%divisor == 0) {
			return divisor;
		}
	}
	return 0;
}


int main(){
	cout << "Oppgave a) \n";
	cout << maxOfTwo(5,7) << "\n";
	cout << '\n';

	cout << "Oppgave c) \n";
	cout << fibonacci(5) << '\n';
	cout << '\n';

	cout << "Oppgave d) \n";
	cout << squereNumberSum(5) << "\n";
	cout << '\n';

	cout << "Oppgave e) \n";
	triangleNumbersBelow(7);

	cout << "oppgave f) \n";
	cout << isPrime(11) << '\n';
	cout << '\n';

	cout << "Oppgave g) \n";
	naivePrimeNumberSearch(8);
	cout << '\n';

	cout << "Oppgave h) \n";
	cout << findGratestDivisor(42) << '\n';
	cout << '\n';
}