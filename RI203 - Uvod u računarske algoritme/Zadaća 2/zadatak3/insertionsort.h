#pragma once

template <typename It, typename C>
void insertionsort(It begin, It end, C comp) {
	It helpIt{ begin + 1 }, tempIt;
	while (helpIt != end) {
		if (!comp(*(helpIt - 1), *helpIt)) {
			tempIt = helpIt;
			while (tempIt != begin) {
				if (!comp(*(tempIt - 1), *tempIt)) {
					std::swap(*(tempIt - 1), *tempIt);
				}
				--tempIt;
			}
		}
		++helpIt;
	}
	return;
}
//Vremenska slozenost O(n^2)
//Radi sa bidirekcionim iteratorima
//In-place algoritam
//Algoritam je stabilan