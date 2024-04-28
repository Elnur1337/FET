#include <iostream>
#include <algorithm>
#include "MojVektor.hpp"

int main(int argc, char* argv[]) {
	MojVektor<int> v = { 1, 2, 3, 4, 5 };
	std::cout << v << std::endl;
	v.erase(2);
	std::cout << v << std::endl;
	v.rotate();
	std::cout << v << std::endl;
}