#include "City.h"

City::City(City&& second) {
	name = std::move(second.name);
	lat = std::move(second.lat);
	lng = std::move(second.lng);
	country = std::move(second.country);
	type = std::move(second.type);
	numberOfCitizens = std::move(second.numberOfCitizens);
	second.lat = 0.0;
	second.lng = 0.0;
	second.numberOfCitizens = 0;
	return;
}


City& City::operator=(const City& second) {
	name = second.name;
	lat = second.lat;
	lng = second.lng;
	country = second.country;
	type = second.type;
	numberOfCitizens = second.numberOfCitizens;
	return *this;
}

std::ostream& operator<<(std::ostream& outputStream, const City& city) {
	outputStream << "Name: " << city.getName() << std::endl;
	outputStream << "Lat: " << city.getLat() << std::endl;
	outputStream << "Lng: " << city.getLng() << std::endl;
	outputStream << "Country: " << city.getCountry() << std::endl;
	outputStream << "Type: " << city.getType() << std::endl;
	outputStream << "Number of citizens: " << city.getNumberOfCitizens() << std::endl;
	return outputStream;
}