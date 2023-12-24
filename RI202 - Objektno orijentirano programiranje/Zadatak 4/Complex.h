#pragma once

class Complex {
private:
	int x = 0;
	int y = 0;

public:
	Complex() { return; }
	Complex(int, int);

	int getReal() const { return x; }
	int getImag() const { return y; }

	Complex operator+(const Complex&) const;
	Complex operator-(const Complex&) const;
	Complex operator*(const Complex&) const;
	Complex operator/(const Complex&) const;

	Complex& operator+=(const Complex&);
	Complex& operator-=(const Complex&);
	Complex& operator*=(const Complex&);
	Complex& operator/=(const Complex&);
};
