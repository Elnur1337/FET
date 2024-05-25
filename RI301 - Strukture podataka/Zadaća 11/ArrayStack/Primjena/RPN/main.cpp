#include <iostream>
#include "PostfixCalc.h"

int main() {
	PostfixCalc calc;
	calc.add("4 5 +");
	std::cin >> calc;
	std::cout << calc.result() << std::endl;
	return 0;
}