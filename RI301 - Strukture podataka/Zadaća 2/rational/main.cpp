#include <iostream>
#include <fstream>
#include <vector>
#include "Rational.hpp"

int main(int argc, char* argv[]) {
	std::vector<Rational> rationals;
	std::ifstream data("./input.txt");
	std::string row;
	while (getline(data, row)) {
		try
		{
			rationals.push_back(Rational(row));
		}
		catch (const std::exception& e)
		{
			std::cout << "Error \"" << e.what() << "\" for value: " << row << "!\n";
		}
	}
	std::cout << std::endl;

	Rational a, b(12, 5), c("-5/-8");
	Rational d(b), e(std::move(c));
	std::cout << a << std::endl << b << std::endl << c << std::endl << d << std::endl << e << std::endl;
	std::cout << std::endl;

	a = b + e;
	std::cout << a << std::endl;
	a = a + 2;
	std::cout << a << std::endl;
	std::cout << std::endl;

	a = a - b;
	std::cout << a << std::endl;
	a = a - 2;
	std::cout << a << std::endl;
	std::cout << std::endl;

	a = a * e;
	std::cout << a << std::endl;
	a = a * -2;
	std::cout << a << std::endl;
	std::cout << std::endl;

	a = a / Rational(2, 3);
	std::cout << a << std::endl;
	a = a / -2;
	std::cout << a << std::endl;
	std::cout << std::endl;

	a = a ^ 2;
	std::cout << a << std::endl;

	a = a ^ 0;
	std::cout << a << std::endl;
	std::cout << std::endl;

	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << std::endl;

	std::cout << a-- << std::endl;
	std::cout << a << std::endl;
	std::cout << --a << std::endl;
	std::cout << std::endl;

	std::cout << (a == b) << std::endl;
	std::cout << (a == "-1/-1") << std::endl;
	std::cout << (a == std::string("-2")) << std::endl;
	std::cout << std::endl;

	std::cout << (a != b) << std::endl;
	std::cout << (a != "-1/-1") << std::endl;
	std::cout << (a != std::string("ab-2")) << std::endl;
	std::cout << std::endl;

	std::cout << b.numerator() << "/" << b.denominator() << std::endl;
	return 0;
}
