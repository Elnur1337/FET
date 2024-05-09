#include <iostream>
#include "evenFactorial.h"

int main() {
	int n;
	std::cout << "Unesite broj n: ";
	std::cin >> n;
	std::cout << evenFactorial(n) << std::endl;
	return 0;
}