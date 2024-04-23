#include <iostream>
#include "Polinom.h"

int main() {
	Polinom polinom1, polinom2, polinom1I;
	std::cin >> polinom1;
	std::cin >> polinom2;
	std::cout << "P1: " << polinom1 << std::endl;
	std::cout << "P2: " << polinom2 << std::endl;
	std::cout << "P1 + P2: " << polinom1 + polinom2 << std::endl;
	std::cout << "P1 - P2: " << polinom1 - polinom2 << std::endl;
	std::cout << "P1 * P2: " << polinom1 * polinom2 << std::endl;
	polinom1I = polinom1.izvod();
	std::cout << "P'1: " << polinom1I << std::endl;
	std::cout << "P'2: " << polinom2.izvod() << std::endl;

	std::cout << "Vrijednost P1 za [-10, 10]: " << std::endl;
	for (int i = -10; i <= 10; ++i) {
		std::cout << "P(" << i << ") = " << polinom1(i) << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Vrijednost P'1 za [-10, 10]: " << std::endl;
	for (int i = -10; i <= 10; ++i) {
		std::cout << "P'(" << i << ") = " << polinom1I(i) << std::endl;
	}

	return 0;
}