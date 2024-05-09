#include "sum.h"

int sum(const int* array, int n) {
	if (n == 1) {
		return array[0];
	}
	return array[0] + sum(array + 1, n - 1);
}