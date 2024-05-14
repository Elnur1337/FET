#pragma once

template <typename It, typename C>
void bubblesort(It begin, It end, C comp) {
	It helpIt;
	while (begin != end) {
		helpIt = begin;
		while ((helpIt + 1) != end) {
			if (!comp(*helpIt, *(helpIt + 1))) {
				std::swap(*helpIt, *(helpIt + 1));
			}
			++helpIt;
		}
		--end;
	}
	return;
}
//Vremenska slozenost O(n^2)
//Radi sa bidrekcionim iteratorima
//In-place algoritam
//Algoritam je stabilan