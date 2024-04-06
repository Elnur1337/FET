#include "loadCities.h"

void loadCities(std::vector<City>& cities, std::vector<Country>& countries, std::map<std::string, City*>& citiesMap, std::ifstream& dataStream) {
	std::cout << "Ucitivanje podataka, sacekajte malo..." << std::endl;
	std::string row;
	std::getline(dataStream, row);
	
	City tempCity;
	Country tempCountry;
	std::string cityName;
	std::string countryName;
	std::string cityType;
	std::string numberOfCitizensString;

	size_t cPos;
	while (std::getline(dataStream, row)) {
		row.erase(0, 1);

		cPos = row.find('"');
		cityName = row.substr(0, cPos);
		tempCity.setName(cityName);
		row.erase(0, cPos + 3);

		cPos = row.find('"');
		tempCity.setLat(std::stod(row.substr(0, cPos)));
		row.erase(0, cPos + 3);

		cPos = row.find('"');
		tempCity.setLng(std::stod(row.substr(0, cPos)));
		row.erase(0, cPos + 3);
		
		cPos = row.find('"');
		countryName = row.substr(0, cPos);
		tempCity.setCountry(countryName);
		row.erase(0, cPos + 3);

		cPos = row.find('"');
		cityType = row.substr(0, cPos);
		if (cityType.length() != 0) {
			tempCity.setType(cityType);
		}
		else {
			tempCity.setType(std::string("minor"));
		}
		row.erase(0, cPos + 3);

		cPos = row.find('"');
		numberOfCitizensString = row.substr(0, cPos);
		char* charArr = new char[numberOfCitizensString.length() + 1];
		strcpy(charArr, numberOfCitizensString.c_str());
		tempCity.setNumberOfCitizens(std::atoi(charArr));
		delete[] charArr;

		cities.push_back(std::move(tempCity));
	}

	std::vector<Country>::iterator it;
	for (City& city : cities) {
		it = std::find_if(countries.begin(), countries.end(), [&city](const Country& c) {
			if (c.getName() == city.getCountry()) {
				return true;
			}
			return false;
			});
		if (it == countries.end()) {
			tempCountry.setName(city.getCountry());
			if (city.getType() == "primary") {
				tempCountry.setCapital(&city);
			}
			tempCountry.setLargestCity(&city);
			tempCountry.addToCitizens(city.getNumberOfCitizens());
			tempCountry.addToCities();
			countries.push_back(std::move(tempCountry));
		}
		else {
			if (it->getCapital() == nullptr) {
				if (city.getType() == "primary") {
					it->setCapital(&city);
				}
			}
			if (it->getLargestCity()->getNumberOfCitizens() < city.getNumberOfCitizens()) {
				it->setLargestCity(&city);
			}
			it->addToCitizens(city.getNumberOfCitizens());
			it->addToCities();
		}
		citiesMap[city.getName() + ", " + city.getCountry()] = &city;
	}
	dataStream.close();
	std::cout << "Podaci ucitani!" << std::endl;
	return;
}