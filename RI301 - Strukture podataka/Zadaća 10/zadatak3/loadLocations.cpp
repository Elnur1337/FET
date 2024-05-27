#include "loadLocations.h"

void loadLocations(TripPlanner& planner, std::ifstream& inputStream) {
	std::string line;
	Location location;
	size_t cPos;
	while (std::getline(inputStream, line)) {
		cPos = line.find(":");
		location.setName(line.substr(0, cPos));
		line = line.substr(cPos + 1, line.length());
		cPos = line.find(":");
		location.setLat(line.substr(0, cPos));
		line = line.substr(cPos + 1, line.length());
		location.setLng(line);
		planner.addLocation(location);
	}
	return;
}