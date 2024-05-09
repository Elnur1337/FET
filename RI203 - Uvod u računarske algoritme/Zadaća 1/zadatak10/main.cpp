#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <chrono>
#include "splitString.h"
#include "cleanWord.h"

int main() {
	std::vector<std::string> words;
	{
		std::cout << "Ucitavanje rijeci, sacekajte malo..." << std::endl;
		std::string row;
		std::ifstream data("./shakespeare.txt");
		while (std::getline(data, row)) {
			for (std::string& s : splitString(row, " ")) {
				cleanWord(s);
				words.push_back(s);
			}
		}
		data.close();
		std::sort(words.begin(), words.end());
		words.erase(unique(words.begin(), words.end()), words.end());

	}
	
	std::string input;
	do {
		std::cout << "Unesite rijec koju zelite da pretrazite: ";
		std::cin >> input;
		if (input == std::string("EXIT")) {
			break;
		}
		cleanWord(input);
		auto now = std::chrono::system_clock::now();
		auto it = std::upper_bound(words.begin(), words.end(), input);
		auto elapsed = std::chrono::system_clock::now() - now;
		if (*(it - 1) == input) {
			std::cout << "Pronedjena je rijec " << *(it - 1) << " za " << elapsed.count() << " ns!" << std::endl;
		}
		else {
			std::cout << "Rijec " << input << " nije pronadjena!\nVrijeme pretrage " << elapsed.count() << " ns!" << std::endl;
		}
	} while (input != std::string("EXIT"));
	return 0;
}