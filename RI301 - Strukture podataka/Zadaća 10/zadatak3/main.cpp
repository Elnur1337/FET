#include <iostream>
#include "TripPlanner.hpp"
#include "loadLocations.h"
#include "showMenu.h"

int main() {
	TripPlanner planner;
	std::ifstream locations{ "./locations.txt" };
	loadLocations(planner, locations);
	locations.close();
	short optionInput;
	do {
		showMenu();
		std::cout << "Option number: ";
		std::cin >> optionInput;
		switch (optionInput) {
		case 0:
			break;
		case 1:
			planner.addLocation();
			break;
		case 2:
			planner.addStop();
			break;
		case 3:
			planner.insertStop();
			break;
		case 4:
			planner.removeStop();
			break;
		case 5:
			planner.printTrip();
			break;
		case 6:
			planner.showTripDistance();
			break;
		case 7:
			planner.renderTrip();
			break;
		case 8:
			planner.printLocations();
			break;
		case 9:
			planner.saveTrip();
			break;
		case 10:
			planner.loadTrip();
			break;
		default:
			std::cout << "Option with that number doesn't exist!\n";
			break;
		}
	} while (optionInput != 0);
	return 0;
}