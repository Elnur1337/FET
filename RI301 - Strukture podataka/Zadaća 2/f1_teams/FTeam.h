#pragma once
#include <iostream>
#include <string>

class FTeam
{
private:
	std::string name;
	std::string countryOfOrigin;
	unsigned int yearFounded;
	unsigned int noc;
	unsigned int budget;
public:
	FTeam() : name{ "" }, countryOfOrigin{ "" }, yearFounded{ 0 }, noc{ 0 }, budget{ 0 } {};
	FTeam(const std::string&, const std::string&, const int&, const int&, const int&);
	FTeam(const FTeam& second) : name{ second.name }, countryOfOrigin{ second.countryOfOrigin }, yearFounded{ second.yearFounded }, noc{ second.noc }, budget{ second.budget } {};
	FTeam(FTeam&&);
	
	FTeam& operator=(const FTeam&);
	FTeam& operator=(FTeam&&);

	bool operator<(const FTeam&) const;
	bool operator==(const FTeam&) const;

	operator bool() const;

	std::string getName() const { return name; };
	std::string getCountryOfOrigin() const { return countryOfOrigin; };
	unsigned int getYearFounded() const { return yearFounded; };
	unsigned int getNoc() const { return noc; };
	unsigned int getBudget() const { return budget; };

	void setName(const std::string&);
	void setCountryOfOrigin(const std::string&);
	void setYearFounded(const int&);
	void setNoc(const int&);
	void setBudget(const int&);

	void eraseFTeam();
};

std::ostream& operator<<(std::ostream&, const FTeam&);

