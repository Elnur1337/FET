#pragma once
#include <iostream>
#include <string>


class Location {
private:
	std::string name_;
	double lat_;
	double lng_;

	friend std::ostream& operator<<(std::ostream&, const Location&);
public:
	Location();
	Location(const Location&);
	Location(Location&&);
	Location(const std::string&, double, double);
	Location(std::string&&, double, double);

	Location& operator=(const Location&);
	Location& operator=(Location&&);

	Location& setName(const std::string&);
	Location& setName(std::string&&);
	inline Location& setLat(double lat) { lat_ = lat; };
	Location& setLat(const std::string&);
	inline Location& setLng(double lng) { lng_ = lng; };
	Location& setLng(const std::string&);

	inline std::string getName() const { return name_; };
	inline double getLat() const { return lat_; };
	inline double getLng() const { return lng_; };
};