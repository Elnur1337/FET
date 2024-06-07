#pragma once

template <typename It>
void insertionsort(It begin, It end) {
	It helpIt{ begin + 1 }, tempIt;
	while (helpIt != end) {
		if (*(helpIt - 1) > *helpIt) {
			tempIt = helpIt;
			while (tempIt != begin) {
				if (*(tempIt - 1) > *tempIt) {
					std::swap(*(tempIt - 1), *tempIt);
				}
				--tempIt;
			}
		}
		++helpIt;
	}
	return;
}