#include "printCapitals.h"

void printCapitals(const std::vector<Country>& countries) {
	std::cout << std::endl;
	for (const Country& country : countries) {
		if (country.getCapital() == nullptr) {
			continue;
		}
		std::cout << *(country.getCapital()) << std::endl;
		std::cout << country << std::endl;
	}
	return;
}