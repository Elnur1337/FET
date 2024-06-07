#include <iostream>
#include "collatz.h"

int main() {
	int maxNumber = 0;
	int maxSteps = 0;
	int steps;
	for (int i = 2; i <= 100; ++i) {
		steps = collatz(i);
		if (steps > maxSteps) {
			maxSteps = steps;
			maxNumber = i;
		}
	}
	std::cout << "Broj u intervalu [2, 100] koji ima najduzu putanju do 1 je " << maxNumber << ", sa putoanjom od " << maxSteps << "!" << std::endl;
	return 0;
}