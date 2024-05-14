#pragma once

template <typename It, typename C>
void shellsort(It begin, It end, C comp) {
	int n = end - begin;
	for (int gap = n / 2; gap > 0; gap /= 2) {
		for (int i = gap; i < n; ++i) {
			auto temp = *(begin + i);
			int j;
			for (j = i; j >= gap && !comp(*(begin + j - gap), temp); j -= gap) {
				*(begin + j) = *(begin + j - gap);
			}
			*(begin + j) = temp;
		}
	}
	return;
}
//Vremenska slozenost
//Najbolji slucaj O(n * logn)
//Porsjecni slucaj O(n * logn)
//Najgori slucaj O(n^2)
//Radi sa random access iteratorima
//In-place algoritam
//Algoritam nije stabilan
