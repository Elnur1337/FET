#include "cleanWord.h"

void cleanWord(std::string& s) {
	for (auto& c : s) {
		c = tolower(c);
	}
	s.erase(
		std::remove_if(s.begin(), s.end(), [](char c) {
			return !std::isalpha(c);
		}), s.end()
	);
	return;
}