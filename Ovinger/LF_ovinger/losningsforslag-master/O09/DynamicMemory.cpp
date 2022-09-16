#include <cassert>
#include <iostream>

#include "DynamicMemory.h"

void fillInFibonacciNumbers(int result[], int length) {
	assert(length >= 1);
	result[0] = 0;

	if (length == 1) {
		return;
	}

	result[1] = 1;

	for (int i = 2; i < length; i++) {
		result[i] = result[i - 1] + result[i - 2];
	}
}

void printArray(int array[], int length) {
	assert(length >= 1);
	for (int i = 0; i < length; i++) {
		std::cout << array[i] << " ";
	}
	std::cout << '\n';
}

void createFibonacci() {
	std::cout << "How many Fibonacci numbers should be generated? ";
	int length;
	std::cin >> length;

	int *result = new int[length]; // Allokerer plass til length antall heltall
	fillInFibonacciNumbers(result, length);

	std::cout << "The Fibonacci numbers:\n";
	printArray(result, length);

	delete[] result; // Frigjør minnet når vi ikke trenger det lenger
}
