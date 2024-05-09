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
	auto now = std::chrono::system_clock::now();
	{
		std::string row;
		std::ifstream data("./shakespeare1_4.txt");
		while (std::getline(data, row)) {
			for (std::string& s : splitString(row, " ")) {
				cleanWord(s);
				words.push_back(s);
			}
		}
		data.close();
		std::sort(words.begin(), words.end());
	}
	auto elapsed = std::chrono::system_clock::now() - now;
	std::cout << elapsed.count() / 10000000 << "s" << std::endl;
	return 0;
}