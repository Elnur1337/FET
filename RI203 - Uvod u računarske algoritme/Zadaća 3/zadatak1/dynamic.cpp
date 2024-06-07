#include "dynamic.h"

unsigned int dynamic(unsigned int n) {
	unsigned int first = 2;
	unsigned int second = 4;
	unsigned int third = 12;
	if (n == 0) {
		return first;
	}
	if (n == 1) {
		return second;
	}
	if (n == 2) {
		return third;
	}
	unsigned int curr = 2 * (2 * first + second);
	for (unsigned int i = 3; i < n; ++i) {
		first = second;
		second = third;
		third = curr;
		curr = 2 * (2 * first + second);
	}
	return curr;
}