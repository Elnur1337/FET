#pragma once

template <typename It, typename C>
void selectionsort(It begin, It end, C comp) {
	It index, helpIt;
	while (begin != end) {
		index = begin;
		helpIt = begin;
		while (helpIt != end) {
			if (!comp(*index, *helpIt)) {
				index = helpIt;
			}
			++helpIt;
		}
		if (index != begin) {
			std::swap(*index, *begin);
		}
		++begin;
	}
	return;
}
//Vremenska slozenost O(n^2)
//Radi sa forward iteratorima
//In-place algoritam
//Algoritam nije stabilan