#pragma once
#include <iostream>
#include <string>
#include "City.h"

class Country
{
private:
	std::string name;
	City *capital;
	City *largestCity;
	size_t numberOfCitizens;
	size_t numberOfCities;
public:
	Country() : numberOfCitizens{ 0 }, numberOfCities{ 0 }, capital{ nullptr }, largestCity{nullptr} {};
	Country(const Country& second) : name{ second.name }, capital{ second.capital }, largestCity{ second.largestCity }, numberOfCitizens{ second.numberOfCitizens }, numberOfCities{ second.numberOfCities } {};
	Country(Country&&);

	Country& operator=(const Country&);

	std::string getName() const { return name; };
	City * getCapital() const { return capital; };
	City * getLargestCity() const { return largestCity; };
	size_t getNumberOfCitizens() const { return numberOfCitizens; };
	size_t getNumberOfCities() const { return numberOfCities; };

	void setName(const std::string& nameInput) { name = nameInput; };
	void setCapital(City* capitalInput) { capital = capitalInput; };
	void setLargestCity(City* largestCityInput) { largestCity = largestCityInput; };
	void addToCitizens(size_t numberOfCitizensInput) { numberOfCitizens += numberOfCitizensInput; };
	void addToCities() { ++numberOfCities; };
};

std::ostream& operator<<(std::ostream&, const Country&);