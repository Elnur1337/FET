#include <iostream>
#include "palindrome.h"

int main() {
	std::cout << palindrome("aabaa", 5) << std::endl;
	std::cout << palindrome("aabbaa", 6) << std::endl;
	std::cout << palindrome("palindrome", 10) << std::endl;
	return 0;
}