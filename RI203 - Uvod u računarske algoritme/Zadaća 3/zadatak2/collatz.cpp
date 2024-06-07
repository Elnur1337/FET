#include "collatz.h"

int collatz(unsigned int n) {
	static int memoArr[1000];
	if (n == 1) {
		return 0;
	}
	if (memoArr[n] != 0) {
		return memoArr[n];
	}
	int res = 0;
	if (n % 2 == 0) {
		res = 1 + collatz(n / 2);
	}
	else {
		res = 1 + collatz(3 * n + 1);
	}
	if (n < 1000) {
		memoArr[n] = res;
	}
	return res;
}