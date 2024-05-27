#pragma once
#include <string>
#include <cmath>
#include <fstream>
#include "Location.h"
#include "DoubleLinkedList.h"

class TripPlanner {
private:
	DoubleLinkedList<Location> locations_;
	DoubleLinkedList<Location> stops_;

	class not_found : public std::exception {
	private:
		std::string msg_;
	public:
		not_found(const std::string&);

		const char* what() const noexcept override;
	};

	friend std::ostream& operator<<(std::ostream&, const TripPlanner&);
public:
	TripPlanner() = default;
	TripPlanner(const TripPlanner&);
	TripPlanner(TripPlanner&&);

	TripPlanner& operator=(const TripPlanner&);
	TripPlanner& operator=(TripPlanner&&);

	TripPlanner& addLocation(const Location&);
	TripPlanner& addLocation(Location&&);
	void addLocation();
	void addStop();
	void insertStop();
	void removeStop();
	void printTrip() const;
	double tripDistance() const;
	void showTripDistance() const;
	void renderTrip() const;
	void printLocations() const;
	void saveTrip() const;
	void loadTrip();
};
