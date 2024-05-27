#include "TripPlanner.hpp"

TripPlanner::not_found::not_found(const std::string& msg) : msg_{ msg } {};

const char* TripPlanner::not_found::what() const noexcept {
	return msg_.c_str();
}

TripPlanner::TripPlanner(const TripPlanner& second) : locations_{ second.locations_ }, stops_{ second.stops_ } {};

TripPlanner::TripPlanner(TripPlanner&& second) : locations_{ std::move(second.locations_) }, stops_{ std::move(second.stops_) } {};

TripPlanner& TripPlanner::operator=(const TripPlanner& second) {
	locations_ = second.locations_;
	stops_ = second.stops_;
	return *this;
}

TripPlanner& TripPlanner::operator=(TripPlanner&& second) {
	locations_ = std::move(second.locations_);
	stops_ = std::move(second.stops_);
	return *this;
}

TripPlanner& TripPlanner::addLocation(const Location& location) {
	locations_.push_back(location);
	return *this;
}

TripPlanner& TripPlanner::addLocation(Location&& location) {
	locations_.push_back(std::move(location));
	return *this;
}

void TripPlanner::addLocation() {
	Location newLocation;
	std::string stringInput;
	std::cout << "Location name: ";
	std::getline(std::cin >> std::ws, stringInput);
	newLocation.setName(stringInput);
	
	std::cout << "Lat: ";
	std::cin >> stringInput;
	newLocation.setLat(stringInput);

	std::cout << "Lng: ";
	std::cin >> stringInput;
	newLocation.setLng(stringInput);

	locations_.push_back(std::move(newLocation));
	return;
}

void TripPlanner::addStop() {
	std::string inputString;
	std::cout << "Location name: ";
	std::getline(std::cin >> std::ws, inputString);
	DoubleLinkedList<Location>::Iterator it = std::find_if(locations_.begin(), locations_.end(), [&inputString](const Location& location) {
			if (location.getName() == inputString) {
				return true;
			}
			return false;
		}
	);
	if (it == locations_.end()) {
		std::cout << "Location not found!" << std::endl;
		return;
	}
	stops_.push_back(*it);
	return;
}

void TripPlanner::insertStop() {
	std::string inputString;
	std::cout << "Location name where you want to insert new location: ";
	std::getline(std::cin >> std::ws, inputString);
	DoubleLinkedList<Location>::Iterator it1 = std::find_if(stops_.begin(), stops_.end(), [&inputString](const Location& location) {
			if (location.getName() == inputString) {
				return true;
			}
			return false;
		}
	);

	std::cout << "Location name: ";
	std::getline(std::cin >> std::ws, inputString);
	DoubleLinkedList<Location>::Iterator it2 = std::find_if(locations_.begin(), locations_.end(), [&inputString](const Location& location) {
		if (location.getName() == inputString) {
			return true;
		}
		return false;
		}
	);
	if (it2 == locations_.end()) {
		std::cout << "Location not found!" << std::endl;
		return;
	}
	stops_.insert(it1, *it2);
	return;
}

void TripPlanner::removeStop() {
	std::string inputString;
	std::cout << "Location name: ";
	std::getline(std::cin >> std::ws, inputString);
	stops_.remove_if([&inputString](const Location& location) {
			if (location.getName() == inputString) {
				return true;
			}
			return false;
		}
	);
	return;
}

void TripPlanner::printTrip() const {
	for (const Location& location : stops_) {
		std::cout << location << std::endl << std::endl;
	}
	return;
}

double TripPlanner::tripDistance() const {
	double distance = 0.0;
	if (stops_.size() < 2) {
		return distance;
	}
	double lat1, lat2, lng1, lng2;
	DoubleLinkedList<Location>::Iterator it = stops_.begin();
	while (it + 1 != stops_.end()) {
		lat1 = it->getLat() / 57.29577951;
		lng1 = it->getLng() / 57.29577951;
		lat2 = (it + 1)->getLat() / 57.29577951;
		lng2 = (it + 1)->getLng() / 57.29577951;

		distance += 3963.0 * acos((sin(lat1) * sin(lat2)) + cos(lat1) * cos(lat2) * cos(lng2 - lng1));
		++it;
	}
	distance *= 1.609344;
	return distance;
}

void TripPlanner::showTripDistance() const {
	std::cout << "Distance: " << tripDistance() << "km" << std::endl;
	return;
}

void TripPlanner::renderTrip() const {
	const double IMAGEWIDTH{ 1063.0 };
	const double IMAGEHEIGHT{ 1014.0 };
	const double NORTHEDGE{ 45.4 };
	const double SOUTHEDGE{ 42.4 };
	const double WESTEDGE{ 15.5 };
	const double EASTEDGE{ 19.9 };

	std::string line;
	std::ifstream templateFile{ "./outputTemplateP1.html" };
	std::ofstream templateResult{ "trip.html" };
	while (std::getline(templateFile, line)) {
		templateResult << line << "\n";
	}
	templateFile.close();

	double x1, x2, y1, y2;
	DoubleLinkedList<Location>::Iterator it = stops_.begin();
	while (it + 1 != stops_.end()) {
		x1 = (it->getLng() - WESTEDGE) / (EASTEDGE - WESTEDGE) * IMAGEWIDTH;
		x2 = ((it + 1)->getLng() - WESTEDGE) / (EASTEDGE - WESTEDGE) * IMAGEWIDTH;
		y1 = (it->getLat() - NORTHEDGE) / (SOUTHEDGE - NORTHEDGE) * IMAGEHEIGHT;
		y2 = ((it + 1)->getLat() - NORTHEDGE) / (SOUTHEDGE - NORTHEDGE) * IMAGEHEIGHT;

		line = "<line x1=\"" + std::to_string(x1) + "\" y1=\"" + std::to_string(y1) + "\" x2=\"" + std::to_string(x2) + "\" y2=\"" + std::to_string(y2) + "\" stroke=\"orange\" stroke-width=\"4\"/>\n";
		templateResult << line;
		++it;
	}
	templateResult << "</svg>";
	templateResult.close();
	
	{
		std::string filePath = "trip.html";
		#ifdef _WIN32
			std::string command = "start " + filePath;
		#elif __APPLE__
			std::string command = "open " + filePath;
		#else 
			std::string command = "xdg-open " + filePath;
		#endif
		system(command.c_str());
	}
	return;
}

void TripPlanner::printLocations() const {
	for (const Location& location : locations_) {
		std::cout << location << std::endl << std::endl;
	}
	return;
}

void TripPlanner::saveTrip() const {
	std::ofstream trip{ "savedTrip.txt" };
	std::string line;
	for (const Location& location : stops_) {
		line = location.getName() + ":" + std::to_string(location.getLat()) + ":" + std::to_string(location.getLng()) + "\n";
		trip << line;
	}
	trip.close();
	return;
}

void TripPlanner::loadTrip() {
	std::ifstream trip{ "./savedTrip.txt" };
	if (!trip.is_open()) {
		throw not_found("Save file not found!");
	}
	Location location;
	std::string line;
	size_t cPos;
	while (std::getline(trip, line)) {
		cPos = line.find(":");
		location.setName(line.substr(0, cPos));
		line = line.substr(cPos + 1, line.length());
		cPos = line.find(":");
		location.setLat(line.substr(0, cPos));
		line = line.substr(cPos + 1, line.length());
		location.setLng(line);
		stops_.push_back(location);
	}
	trip.close();
	return;
}

std::ostream& operator<<(std::ostream& outputStream, const TripPlanner& trip) {
	for (const Location& location : trip.stops_) {
		std::cout << location << std::endl << std::endl;
	}
	return outputStream;
}