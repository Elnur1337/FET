#include "printLargests.h"

void printLargests(const std::vector<Country>& countries) {
	std::cout << std::endl;
	for (const Country& country : countries) {
		std::cout << *(country.getLargestCity()) << std::endl;
		std::cout << country << std::endl;
	}
	return;
}