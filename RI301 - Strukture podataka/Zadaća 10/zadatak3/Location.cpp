#include "Location.h"

Location::Location() : name_{ std::string{""} }, lat_{ 0.0 }, lng_{ 0.0 } {};

Location::Location(const Location& second) : name_{ second.name_ }, lat_{ second.lat_ }, lng_{ second.lng_ } {};

Location::Location(Location&& second) : name_{ std::move(second.name_) }, lat_{ second.lat_ }, lng_{ second.lng_ } {
	second.lat_ = 0.0;
	second.lng_ = 0.0;
	return;
}

Location::Location(const std::string& name, double lat, double lng) : lat_{ lat }, lng_{ lng } {
	setName(name);
	return;
}

Location::Location(std::string&& name, double lat, double lng) : lat_{ lat }, lng_{ lng } {
	setName(std::move(name));
	return;
}

Location& Location::operator=(const Location& second) {
	name_ = second.name_;
	lat_ = second.lat_;
	lng_ = second.lng_;
	return *this;
}

Location& Location::operator=(Location&& second) {
	name_ = std::move(second.name_);
	lat_ = second.lat_;
	lng_ = second.lng_;
	second.lat_ = second.lng_ = 0.0;
	return *this;
}

Location& Location::setName(const std::string& name) {
	if (name.length() < 2) {
		throw std::invalid_argument("Name must be at least 2 characters long!");
	}
	bool areAllSpace{ true };
	size_t spaceCounter{ 0 };
	for (const char c : name) {
		if (c != ' ') {
			areAllSpace = false;
			break;
		}
		++spaceCounter;
	}
	if (areAllSpace) {
		throw std::invalid_argument("Name can't be all space characters!");
	}
	if (spaceCounter == 0) {
		name_ = name;
		return *this;
	}
	std::string newName{ name.substr(spaceCounter, name.length()) };
	if (newName.length() < 2) {
		throw std::invalid_argument("Name must be at least 2 characters long!");
	}
	name_ = std::move(newName);
	return *this;
}

Location& Location::setName(std::string&& name) {
	if (name.length() < 2) {
		throw std::invalid_argument("Name must be at least 2 characters long!");
	}
	bool areAllSpace{ true };
	size_t spaceCounter{ 0 };
	for (const char c : name) {
		if (c != ' ') {
			areAllSpace = false;
			break;
		}
		++spaceCounter;
	}
	if (areAllSpace) {
		throw std::invalid_argument("Name can't be all space characters!");
	}
	if (spaceCounter == 0) {
		name_ = std::move(name);
		return *this;
	}
	std::string newName{ name.substr(spaceCounter, name.length()) };
	if (newName.length() < 2) {
		throw std::invalid_argument("Name must be at least 2 characters long!");
	}
	name_ = std::move(newName);
	return *this;
}

Location& Location::setLat(const std::string& lat) {
	try
	{
		lat_ = std::stod(lat);
	}
	catch (const std::exception& e)
	{
		throw std::invalid_argument("Lat can only be number!");
	}
	return *this;
}

Location& Location::setLng(const std::string& lng) {
	try
	{
		lng_ = std::stod(lng);
	}
	catch (const std::exception& e)
	{
		throw std::invalid_argument("Lng can only by number!");
	}
	return *this;
}

std::ostream& operator<<(std::ostream& outputStream, const Location& location) {
	outputStream << "Location: " << location.name_ << std::endl;
	outputStream << "Lat: " << location.lat_ << std::endl;
	outputStream << "Lng: " << location.lng_;
	return outputStream;
}