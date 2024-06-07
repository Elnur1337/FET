#include <iostream>

int lps(char*, size_t, size_t);

int main() {
	char s[] = "ELNURUNLER";
	std::cout << lps(s, 0, std::strlen(s) - 1);
	return 0;
}

int lps(char* arr, size_t begin, size_t end) {
	if (begin == end) {
		return 1;
	}
	if (arr[begin] == arr[end] && begin + 1 == end) {
		return 2;
	}
	if (arr[begin] == arr[end]) {
		return 2 + lps(arr, begin + 1, end - 1);
	}
	return std::max(lps(arr, begin + 1, end), lps(arr, begin, end - 1));
}