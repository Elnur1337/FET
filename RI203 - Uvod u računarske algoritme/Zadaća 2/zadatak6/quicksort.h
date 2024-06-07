#pragma once
#include <algorithm>
#include "insertionsort.h"

template <typename It>
void quicksort(It begin, It end) {
	if (end - begin <= 16) {
		insertionsort(begin, end);
		return;
	}

	It pivot{ begin };
	for (It secondBegin = begin; secondBegin != end - 1; ++secondBegin) {
		if (*secondBegin < *(end - 1)) {
			std::swap(*pivot, *secondBegin);
			++pivot;
		}
	}
	std::swap(*pivot, *(end - 1));

	quicksort(begin, pivot);
	quicksort(pivot + 1, end);
}
//Vremenska slozenost
//Najbolji slucaj O(n * logn)
//Prosjecni slucaj O(n * logn)
//Najgori slucaj O(n^2)
//Radi sa bidirekcionim iteratorima
//In-place algoritam
//Algoritam nije stabilan