#pragma once
#include <iostream>

class Complex {
private:
	double x = 0;
	double y = 0;

public:
	Complex() { return; }
	Complex(const double&, const double&);

	double getReal() const { return x; }
	double getImag() const { return y; }

	Complex operator+(const Complex&) const;
	Complex operator-(const Complex&) const;
	Complex operator*(const Complex&) const;
	Complex operator/(const Complex&) const;

	Complex& operator+=(const Complex&);
	Complex& operator-=(const Complex&);
	Complex& operator*=(const Complex&);
	Complex& operator/=(const Complex&);
};

std::ostream& operator<<(std::ostream&, const Complex&);