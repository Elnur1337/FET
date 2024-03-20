#include <iostream>
#include <list>
#include <fstream>
#include <string>
#include <algorithm>
#include "FTeam.h"

int main() {
	std::list<FTeam> f1teams;
	std::ifstream data("./f1_teams.csv");
	std::string firstRow;
	std::string row;
	getline(data, firstRow);
	{
		FTeam tempTeam;
		while (getline(data, row)) {
			size_t cPos = row.find(',');
			try
			{
				tempTeam.setName(row.substr(0, cPos));
			}
			catch (const std::exception& e)
			{
				std::cout << "Error \"" << e.what() << "\" for value: " << row << "!\n";
			}
			row.erase(0, cPos + 1);

			cPos = row.find(',');
			try
			{
				tempTeam.setCountryOfOrigin(row.substr(0, cPos));
			}
			catch (const std::exception& e)
			{
				std::cout << "Error \"" << e.what() << "\" for value: " << row << "!\n";
			}
			row.erase(0, cPos + 1);

			cPos = row.find(',');
			try
			{
				tempTeam.setYearFounded(std::stoi(row.substr(0, cPos)));
			}
			catch (const std::exception& e)
			{
				std::cout << "Error \"" << e.what() << "\" for value: " << row << "!\n";
			}
			row.erase(0, cPos + 1);

			cPos = row.find(',');
			try
			{
				tempTeam.setNoc(std::stoi(row.substr(0, cPos)));
			}
			catch (const std::exception& e)
			{
				std::cout << "Error \"" << e.what() << "\" for value: " << row << "!\n";
			}
			row.erase(0, cPos + 1);

			cPos = row.find(',');
			try
			{
				tempTeam.setBudget(std::stoi(row.substr(0, cPos)));
			}
			catch (const std::exception& e)
			{
				std::cout << "Error \"" << e.what() << "\" for value: " << row << "!\n";
			}
			f1teams.push_back(tempTeam);
		}

	}

	{
		std::list<FTeam> f1teamsTemp = f1teams;
		for (FTeam& team1 : f1teams) {
			int isTeamFirst = 0;
			for (FTeam& team2 : f1teamsTemp) {
				if (team1 == team2) {
					if (isTeamFirst == 0) {
						team2.eraseFTeam();
						++isTeamFirst;
					} else {
						if (team1.getYearFounded() > team2.getYearFounded()) {
							team1.setYearFounded(team2.getYearFounded());
						}
						team1.setNoc(team1.getNoc() + team2.getNoc());
						team1.setBudget(team1.getBudget() + team2.getBudget());
						team2.eraseFTeam();
						++isTeamFirst;
					}
				}
			}
		}
	}

	f1teams.remove_if([](const FTeam& team) {
			if (!team) {
				return true;
			}
			return false;
		}
	);

	f1teams.sort([](const FTeam& team1, const FTeam& team2) {
		return team2 < team1;
		}
	);

	std::ofstream exportFile("f1_teams_sorted.csv");
	exportFile << firstRow << std::endl;
	for (const FTeam& team : f1teams) {
		exportFile << team;
	}
	return 0;
}