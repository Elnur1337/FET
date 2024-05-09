#include "evenFactorial.h"

int evenFactorial(int n, int prod) {
	if (n <= 1) {
		if (prod == 1) {
			return 0;
		}
		return prod;
	}
	if (n % 2 != 0) {
		--n;
	}
	prod *= n;
	return evenFactorial(n - 2, prod);
}