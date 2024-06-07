#include "cube.h"

void cube(size_t n, size_t s, std::vector<short>& currCombination) {
	if (currCombination.size() == n) {
		size_t currSum = 0;
		for (size_t i{ 0 }; i < currCombination.size(); ++i) {
			currSum += currCombination[i];
		}
		if (currSum < s) {
			for (short& e : currCombination) {
				std::cout << e << " ";
			}
			std::cout << std::endl;
		}
		return;
	}
	for (short i{ 1 }; i <= 6; ++i) {
		size_t currSum = 0;
		for (size_t i{ 0 }; i < currCombination.size(); ++i) {
			currSum += currCombination[i];
		}
		if (currSum + i < s) {
			currCombination.push_back(i);
			cube(n, s, currCombination);
			currCombination.pop_back();
		}
	}
	return;
}
