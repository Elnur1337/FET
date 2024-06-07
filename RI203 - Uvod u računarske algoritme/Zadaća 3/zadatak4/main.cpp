#include <iostream>

void lscs(int*, int);

int main() {
	int arr[50];
	int i;
	for (i = 0; std::cin; ++i) {
		std::cin >> arr[i];
	}
	lscs(arr, i);
	return 0;
}

void lscs(int* arr, int n) {
	int maxSoFar{ arr[0] };
	int maxEndingHere = { arr[0] };

	int begin{ 0 };
	int end{ 0 };
	int tempBegin{ 0 };

	for (int i{ 1 }; i < n; ++i) {
		if (arr[i] > maxEndingHere + arr[i]) {
			maxEndingHere = arr[i];
			tempBegin = i;
		}
		else {
			maxEndingHere += arr[i];
		}

		if (maxEndingHere > maxSoFar) {
			maxSoFar = maxEndingHere;
			begin = tempBegin;
			end = i;
		}

	}

	while (begin != end) {
		std::cout << arr[begin++] << " ";
	}
	std::cout << std::endl << maxSoFar;
	return;
}