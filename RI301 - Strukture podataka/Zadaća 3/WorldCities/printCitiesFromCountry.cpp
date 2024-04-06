#include "printCitiesFromCountry.h"

void printCitiesFromCountry(const std::vector<City>& cities) {
	std::string country;
	std::cout << "Unesite drzavu: ";
	{
		std::string bufferClear;
		std::getline(std::cin, bufferClear);
	}
	std::getline(std::cin, country);
	unsigned short option;
	std::cout << "Sortiranja:\n";
	std::cout << "1. Sortirati po broju stanovnika\n";
	std::cout << "2. Sortirati po nazivu\n";
	std::cout << "Unesite broj opcije: ";
	std::cin >> option;
	std::vector<City> v;
	std::copy_if(cities.begin(), cities.end(), std::back_inserter(v), [&country](const City& city) {
		if (city.getCountry() == country) {
			return true;
		}
		return false;
		});
	if (option == 2) {
		std::sort(v.begin(), v.end(), [](const City& city1, const City& city2) {
			if (city1.getName() < city2.getName()) {
				return true;
			}
			return false;
		});
	}
	else {
		std::sort(v.begin(), v.end(), [](const City& city1, const City& city2) {
			if (city1.getNumberOfCitizens() > city2.getNumberOfCitizens()) {
				return true;
			}
			return false;
			});
	}
	std::cout << std::endl;
	for (const City& city : v) {
		std::cout << city << std::endl;
	}
	return;
}