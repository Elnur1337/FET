#include <iostream>
#include "City.h"
#include "Country.h"
#include "loadCities.h"
#include "showMenu.h"
#include "printCitiesFromCountry.h"
#include "printCountries.h"
#include "printCity.h"
#include "printCapitals.h"
#include "printLargests.h"

int main() {
	std::vector<City> cities;
	std::vector<Country> countries;
	std::map<std::string, City*> citiesMap;
	std::ifstream data("./WorldCities.csv");
	loadCities(cities, countries, citiesMap, data);

	unsigned short optionInput;
	do {
		showMenu();
		std::cout << "Unesite broj opcije: ";
		std::cin >> optionInput;
		switch (optionInput)
		{
		case 1:
			printCitiesFromCountry(cities);
			break;
		case 2:
			printCountries(countries);
			break;
		case 3:
			printCity(citiesMap);
			break;
		case 4:
			printCapitals(countries);
			break;
		case 5:
			printLargests(countries);
			break;
		default:
			if (optionInput != 6) {
				std::cout << "Unesensa opcija ne postoji!" << std::endl;
			}
			break;
		}
	} while (optionInput != 6);
	return 0;
}