#pragma once

template <typename It>
void mergesort(It begin, It end) {
	if (end - begin <= 1) {
		return;
	}

	It mid{ begin + (end - begin) / 2 };

	mergesort(begin, mid);
	mergesort(mid, end);

	It left{ begin };
	It right{ mid };

	while (left != mid && right != end) {
		if (*left <= *right) {
			++left;
		}
		else {
			auto value{ *right };
			It index{ right };
			while (index != left) {
				*index = *(index - 1);
				--index;
			}
			*left = value;
			++left;
			++right;
			++mid;
		}
	}
	return;
}
//Vremenska slozenost
//In-place implementacija O(n^2 * logn)
//Implementacija sa dodatnom memorijom O(n * logn)
//Radi sa bidirekcionim iteratorima
//In-place algoritam
//Algoritam je stabilan