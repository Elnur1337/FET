#include <iostream>

int lis(int*, int);

int main() {
	int arr[50]{ -1 };
	int i;
	for (i = 0; std::cin; ++i) {
		std::cin >> arr[i];
	}
	std::cout << std::endl << lis(arr, i);
	return 0;
}

int lis(int* arr, int n) {
	int* lis = new int[n];
	lis[0] = 1;

	for (int i = 1; i < n; ++i) {
		lis[i] = 1;
		for (int j = 0; j < i; ++j) {
			if (arr[i] > arr[j] && lis[i] < lis[j] + 1) {
				lis[i] = lis[j] + 1;
			}
		}
	}
	int lisNumber = 0;
	for (int i = 0; i < n; ++i) {
		if (lis[i] > lisNumber) {
			lisNumber = lis[i];
		}
	}
	delete[] lis;
	return lisNumber;
}