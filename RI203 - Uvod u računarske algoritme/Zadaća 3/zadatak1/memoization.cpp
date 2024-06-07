#include "memoization.h"

unsigned int memoization(unsigned int n) {
	static unsigned int memoArr[1000];
	if (memoArr[0] == 0) {
		memoArr[0] = 2;
		memoArr[1] = 4;
		memoArr[2] = 12;
	}
	if (memoArr[n] != 0) {
		return memoArr[n];
	}
	memoArr[n] = 2 * (2 * memoization(n - 3) + memoization(n - 2));
	return memoArr[n];
}