#include "palindrome.h"

bool palindrome(const char* s, int n) {
	if (n <= 1) {
		return true;
	}
	if (s[0] != s[n - 1]) {
		return false;
	}
	return palindrome(s + 1, n - 2);
}