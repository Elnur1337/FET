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
				std::cout << s << std::endl;
				auto it = std::upper_bound(words.begin(), words.end(), s);
				words.insert(it, s);
			}
		}
		data.close();
	}
	auto elapsed = std::chrono::system_clock::now() - now;
	std::cout << elapsed.count() / 10000000 << "s" << std::endl;
	return 0;
}