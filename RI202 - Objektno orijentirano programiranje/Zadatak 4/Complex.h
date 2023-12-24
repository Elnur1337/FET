#pragma once

class Complex {
private:
	int x = 0;
	int y = 0;

public:
	Complex();
	Complex(int, int);

	int getReal() const;
	int getImag() const;

	Complex operator+(const Complex& sec) const;
	Complex operator-(const Complex& sec) const;
	Complex operator*(const Complex& sec) const;
	Complex operator/(const Complex& sec) const;
	Complex& operator+=(const Complex& sec);
	Complex& operator-=(const Complex& sec);
	Complex& operator*=(const Complex& sec);
	Complex& operator/=(const Complex& sec);
};
