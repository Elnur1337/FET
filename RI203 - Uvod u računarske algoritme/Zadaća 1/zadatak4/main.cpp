#include <iostream>
#include "sum.h"

int main() {
	int niz1[4] = { 5, 5, 6, 2 };
	int niz2[1] = { 5 };
	int niz3[2] = { 4, 8 };
	std::cout << sum(niz1, 4) << std::endl;
	std::cout << sum(niz2, 1) << std::endl;
	std::cout << sum(niz3, 2) << std::endl;
	return 0;
}