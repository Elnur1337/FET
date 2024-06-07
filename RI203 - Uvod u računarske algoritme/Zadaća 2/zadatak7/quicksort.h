#pragma once
#include <algorithm>

template <typename Ptr, typename C>
void quicksort(Ptr ptr, size_t n, C comp) {
	if (n <= 1) {
		return;
	}

	Ptr pivot{ ptr };
	for (Ptr begin = ptr; begin != ptr + n - 1; ++begin) {
		if (comp(*begin, *(ptr + n - 1))) {
			std::swap(*pivot, *begin);
			++pivot;
		}
	}
	std::swap(*pivot, *(ptr + n - 1));

	size_t pivotIndex = pivot - ptr;
	quicksort(ptr, pivotIndex, comp);
	quicksort(ptr + pivotIndex + 1, n - pivotIndex - 1, comp);
}