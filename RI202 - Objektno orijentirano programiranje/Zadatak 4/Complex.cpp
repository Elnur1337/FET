#include "Complex.h"

Complex::Complex(int real, int imag) {
	x = real;
	y = imag;
	return;
}

Complex Complex::operator+(const Complex& sec) const
{
	return Complex(x + sec.x, y + sec.y);
}

Complex Complex::operator-(const Complex& sec) const {
	return Complex(x - sec.x, y - sec.y);
}