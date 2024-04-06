#include "Country.h"

Country::Country(Country&& second) {
	name = std::move(second.name);
	capital = std::move(second.capital);
	largestCity = std::move(second.largestCity);
	numberOfCitizens = std::move(second.numberOfCitizens);
	numberOfCities = std::move(second.numberOfCities);
	second.capital = nullptr;
	second.largestCity = nullptr;
	second.numberOfCitizens = 0;
	second.numberOfCities = 0;
	return;
}

Country& Country::operator=(const Country& second) {
	name = second.name;
	capital = second.capital;
	largestCity = second.largestCity;
	numberOfCitizens = second.numberOfCitizens;
	numberOfCities = second.numberOfCities;
	return *this;
}

std::ostream& operator<<(std::ostream& outputStream, const Country& country) {
	outputStream << "Name: " << country.getName() << std::endl;
	outputStream << "Capital: " << (country.getCapital() == nullptr ? "Unknown" : country.getCapital()->getName()) << std::endl;
	outputStream << "Largest city: " << (country.getLargestCity() == nullptr ? "Unknown" : country.getLargestCity()->getName()) << std::endl;
	outputStream << "Number of citizens: " << country.getNumberOfCitizens() << std::endl;
	outputStream << "Number of cities: " << country.getNumberOfCities() << std::endl;
	return outputStream;
}