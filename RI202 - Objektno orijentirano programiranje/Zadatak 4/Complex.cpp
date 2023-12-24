#include "Complex.h"

Complex::Complex()
{
	return;
}

Complex::Complex(int real, int imag) {
	x = real;
	y = imag;
	return;
}

int Complex::getReal() const {
	return x;
}