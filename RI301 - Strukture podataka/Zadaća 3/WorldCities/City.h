#pragma once
#include <iostream>

class City
{
private:
	std::string name;
	double lat;
	double lng;
	std::string country;
	std::string type;
	size_t numberOfCitizens;
public:
	City() : lat{ 0.0 }, lng{ 0.0 }, numberOfCitizens{ 0 } {};
	City(const City& second) : name{ second.name }, lat{ second.lat }, lng{ second.lng }, country{ second.country }, type{ second.type }, numberOfCitizens{ second.numberOfCitizens } {};
	City(City&&);

	City& operator=(const City&);

	std::string getName() const { return name; };
	double getLat() const { return lat; };
	double getLng() const { return lng; };
	std::string getCountry() const { return country; };
	std::string getType() const { return type; };
	size_t getNumberOfCitizens() const { return numberOfCitizens; };

	void setName(const std::string& nameInput) { name = nameInput; };
	void setLat(double latInput) { lat = latInput; };
	void setLng(double lngInput) { lng = lngInput; };
	void setCountry(const std::string& countryInput) { country = countryInput; };
	void setType(const std::string& typeInput) { type = typeInput; };
	void setNumberOfCitizens(size_t numberOfCitizensInput) { numberOfCitizens = numberOfCitizensInput; };
};

std::ostream& operator<<(std::ostream&, const City&);

