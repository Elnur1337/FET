#include "Complex.h"

Complex::Complex(const double& real, const double& imag) {
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
	const double denominator = sec.x * sec.x + sec.y * sec.y;
	if (denominator != 0) {
		return Complex((x * sec.x + y * sec.y) / denominator, (y * sec.x - x * sec.y) / denominator);
	}
	std::cout << "Nije moguce dijeliti sa 0 (nazivnik u formuli za dijeljenje je 0)!\n";
	return Complex();
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

Complex& Complex::operator*=(const Complex& sec) {
	const double re = (x * sec.x - y * sec.y);
	const double im = (x * sec.y + y * sec.x);
	x = re;
	y = im;
	return *this;
}

Complex& Complex::operator/=(const Complex& sec) {
	const double denominator = sec.x * sec.x + sec.y * sec.y;
	if (denominator != 0) {
		const double re = (x * sec.x + y * sec.y) / denominator;
		const double im = (-x * sec.y + y * sec.x) / denominator;
		x = re;
		y = im;
		return *this;
	}
	return *this;
}

std::ostream& operator<<(std::ostream& outputStream, const Complex& number) {
	outputStream << number.getReal() << (number.getImag() > -1 ? " + " : " - ") << (number.getImag() > -1 ? number.getImag() : -number.getImag()) << "i";
	return outputStream;
}