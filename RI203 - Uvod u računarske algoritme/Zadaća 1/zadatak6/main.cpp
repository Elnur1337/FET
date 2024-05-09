#include <iostream>
#include "push_unique.h"

int main() {
	std::vector<int> v = { 1, 2, 3, 4, 5 };
	std::cout << push_unique(v, 5) << std::endl;
	for (int e : v) {
		std::cout << e << std::endl;
	}
	std::cout << "-------------------" << std::endl;
	std::cout << push_unique(v, 6) << std::endl;
	for (int e : v) {
		std::cout << e << std::endl;
	}
	return 0;
}