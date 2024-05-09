#include "fast_divide.h"

int fast_divide(int djeljenik, int djelilac, int res) {
	unsigned int mnozilac = 1;
	while (mnozilac * djelilac * 2 <= djeljenik) {
		mnozilac *= 2;
	}
	if (djeljenik < djelilac) {
		return res;
	}
	res += mnozilac;
	return fast_divide(djeljenik - mnozilac * djelilac, djelilac, res);
}