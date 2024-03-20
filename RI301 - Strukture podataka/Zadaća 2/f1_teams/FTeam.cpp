#include "FTeam.h"

FTeam::FTeam(const std::string& nameInput, const std::string& countryOfOriginInput, const int& yearFoundedInput, const int& nocInput, const int& budgetInput) {
	if (yearFoundedInput < 1946) {
		throw std::invalid_argument("Foundation of the modern formula 1 began in 1946!");
	}
	if (nocInput < 0) {
		throw std::invalid_argument("Number of championships can't be less then zero!");
	}
	if (budgetInput < 0) {
		throw std::invalid_argument("Budget can't be less then zero!");
	}
	if (nameInput.length() < 1) {
		throw std::invalid_argument("Name must be at least 1 characther long!");
	}
	if (countryOfOriginInput.length() < 1) {
		throw std::invalid_argument("Country of origin must be at least 1 characther long!");
	}
	name = nameInput;
	countryOfOrigin = countryOfOriginInput;
	yearFounded = yearFoundedInput;
	noc = nocInput;
	budget = budgetInput;
	return;
}

FTeam::FTeam(FTeam&& second) {
	name = std::move(second.name);
	countryOfOrigin = std::move(second.countryOfOrigin);
	yearFounded = std::move(second.yearFounded);
	noc = std::move(second.noc);
	budget = std::move(second.budget);
	second.yearFounded = 0;
	second.noc = 0;
	second.budget = 0;
	return;
}

FTeam& FTeam::operator=(const FTeam& second) {
	name = second.name;
	countryOfOrigin = second.countryOfOrigin;
	yearFounded = second.yearFounded;
	noc = second.noc;
	budget = second.budget;
	return *this;
}

FTeam& FTeam::operator=(FTeam&& second) {
	name = std::move(second.name);
	countryOfOrigin = std::move(second.countryOfOrigin);
	yearFounded = std::move(second.yearFounded);
	noc = std::move(second.noc);
	budget = std::move(second.budget);
	second.yearFounded = 0;
	second.noc = 0;
	second.budget = 0;
	return *this;
}

bool FTeam::operator<(const FTeam& second) const {
	if (noc < second.noc) {
		return true;
	}
	return false;
}

bool FTeam::operator==(const FTeam& second) const {
	if (name == second.name && countryOfOrigin == second.countryOfOrigin) {
		return true;
	}
	return false;
}

FTeam::operator bool() const {
	if (noc != 0) {
		return true;
	}
	return false;
}

void FTeam::setName(const std::string& nameInput) {
	if (nameInput.length() < 1) {
		throw std::invalid_argument("Name must be at least 1 characther long!");
	}
	name = nameInput;
	return;
}

void FTeam::setCountryOfOrigin(const std::string& countryOfOriginInput) {
	if (countryOfOriginInput.length() < 1) {
		throw std::invalid_argument("Country of origin must be at least 1 characther long!");
	}
	countryOfOrigin = countryOfOriginInput;
	return;
}

void FTeam::setYearFounded(const int& yearFoundedInput) {
	if (yearFoundedInput < 1946) {
		throw std::invalid_argument("Foundation of the modern formula 1 began in 1946!");
	}
	yearFounded = yearFoundedInput;
	return;
}

void FTeam::setNoc(const int& nocInput) {
	if (nocInput < 0) {
		throw std::invalid_argument("Number of championships can't be less then zero!");
	}
	noc = nocInput;
	return;
}

void FTeam::setBudget(const int& budgetInput) {
	if (budgetInput < 0) {
		throw std::invalid_argument("Budget can't be less then zero!");
	}
	budget = budgetInput;
	return;
}

void FTeam::eraseFTeam() {
	name = "";
	countryOfOrigin = "";
	yearFounded = 0;
	noc = 0;
	budget = 0;
}

std::ostream& operator<<(std::ostream& outputStream, const FTeam& team) {
	outputStream << team.getName() << "," << team.getCountryOfOrigin() << "," << team.getYearFounded() << "," << team.getNoc() << "," << team.getBudget() << std::endl;
	return outputStream;
}