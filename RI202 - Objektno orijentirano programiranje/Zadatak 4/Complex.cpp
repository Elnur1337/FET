#include "Complex.h"

Complex::Complex(int real, int imag) {
	x = real;
	y = imag;
	return;
}

Complex Complex::operator+(const Complex& sec) const {
	return Complex(x + sec.x, y + sec.y);
}

Complex Complex::operator-(const Complex& sec) const {
	return Complex(x - sec.x, y - sec.y);
}

Complex Complex::operator*(const Complex& sec) const {
	return Complex(x * sec.x - y * sec.y, x * sec.y + y * sec.x);
}

Complex Complex::operator/(const Complex& sec) const {
	int denominator = sec.x * sec.x + sec.y * sec.y;
	return Complex((x * sec.x + y * sec.y) / denominator, (-x * sec.y + y * sec.x) / denominator);
}

Complex& Complex::operator+=(const Complex& sec) {
	x += sec.x;
	y += sec.y;
	return *this;
}

Complex& Complex::operator-=(const Complex& sec) {
	x -= sec.x;
	y -= sec.y;
	return *this;
}