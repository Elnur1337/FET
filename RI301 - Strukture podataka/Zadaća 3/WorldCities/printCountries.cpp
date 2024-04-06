#include "printCountries.h"

void printCountries(std::vector<Country> countries) {
	unsigned short option;
	std::cout << "Sortiranja:\n";
	std::cout << "1. Sortirati po broju stanovnika\n";
	std::cout << "2. Sortirati po nazivu\n";
	std::cout << "Unesite broj opcije: ";
	std::cin >> option;
	if (option == 2) {
		std::sort(countries.begin(), countries.end(), [](const Country& country1, const Country& country2) {
			if (country1.getName() < country2.getName()) {
				return true;
			}
			return false;
			});
	}
	else {
		std::sort(countries.begin(), countries.end(), [](const Country& country1, const Country& country2) {
			if (country1.getNumberOfCitizens() > country2.getNumberOfCitizens()) {
				return true;
			}
			return false;
			});
	}
	std::cout << std::endl;
	for (const Country& country : countries) {
		std::cout << country << std::endl;
	}
	return;
}