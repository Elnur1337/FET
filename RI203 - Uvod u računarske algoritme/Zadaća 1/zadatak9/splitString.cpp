#include "splitString.h"

std::vector<std::string> splitString(std::string& row, const char* delimiter) {
	std::vector<std::string> words;
	if (row.length() == 0) {
		return words;
	}
	size_t delimiterPos;
	while (row.length() > 0) {
		delimiterPos = row.find(delimiter);
		if (delimiterPos > row.length()) {
			words.push_back(row);
			row.erase();
		}
		else {
			words.push_back(row.substr(0, delimiterPos));
			row.erase(0, delimiterPos + 1);
		}
	}
	return words;
}