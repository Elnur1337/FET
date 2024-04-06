#include "printCity.h"

void printCity(const std::map<std::string, City*>& citiesMap) {
	std::string searchInput;
	std::cout << "Pretrazite grad po nazivu\n";
	std::cout << "Format: Ime grada, ime drzave\n";
	std::cout << "Unos: ";
	{
		std::string bufferClear;
		std::getline(std::cin, bufferClear);
	}
	std::getline(std::cin, searchInput);
	std::map<std::string, City*>::const_iterator it = citiesMap.find(searchInput);
	std::cout << std::endl;
	if (it != citiesMap.end()) {
		std::cout << *(it->second);
	}
	else {
		std::cout << "Uneseni grad ne postoji!";
	}
	std::cout << std::endl;
	return;
}