#include <iostream>
#include <vector>
#include "upper_bound.h"

int main() {
	std::vector<int> v = { 1, 3, 4, 5, 6 };
	int e = 1;
	auto it = upper_bound(v.begin(), v.end(), e);
	for (int& x : v) {
		std::cout << x << std::endl;
	}
	std::cout << std::endl;
	v.insert(it, e);
	for (int& x : v) {
		std::cout << x << std::endl;
	}
	std::cout << std::endl;
	return 0;
}