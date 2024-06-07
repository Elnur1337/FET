#include "recursion.h"

unsigned int recursion(unsigned int n) {
	if (n == 0) {
		return 2;
	}
	if (n == 1) {
		return 4;
	}
	if (n == 2) {
		return 12;
	}
	return 2 * (2 * recursion(n - 3) + recursion(n - 2));
}