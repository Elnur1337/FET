#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <iterator>
#include "splitString.h"

int main() {
	std::map<std::string, std::vector<size_t>> wordsPos;
	{
		std::string row;
		size_t posCounter{ 0 };
		std::ifstream data("./story.txt");
		while (std::getline(data, row)) {
			for (std::string& s : splitString(row, " ")) {
				++posCounter;
				std::map<std::string, std::vector<size_t>>::const_iterator it = wordsPos.find(s);
				wordsPos[s].push_back(posCounter);
			}
		}
		data.close();
	}
	for (std::map<std::string, std::vector<size_t>>::const_iterator begin = wordsPos.begin(); begin != wordsPos.end(); ++begin) {
		std::cout << "Rijec je \"" << begin->first << "\" i nalazi se na sljedecim pozicijama:\n";
		for (size_t n : begin->second) {
			std::cout << n << ", ";
		}
		std::cout << std::endl;
	}
	return 0;
}