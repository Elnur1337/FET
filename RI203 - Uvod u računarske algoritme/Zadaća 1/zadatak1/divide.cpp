#include "divide.h"

int divide(int djeljenik, int djeljitelj, int res) {
	if (djeljenik < djeljitelj) {
		return res;
	}
	return divide(djeljenik - djeljitelj, djeljitelj, ++res);
}