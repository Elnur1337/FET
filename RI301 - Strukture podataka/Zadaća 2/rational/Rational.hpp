#pragma once
#include <iostream>
#include <cmath>
#include "isDigits.h"

class Rational {
private:
	int numerator_;
	int denominator_;
public:
	Rational() : numerator_{ 0 }, denominator_{ 1 } {};
	Rational(int numerator) : numerator_{ numerator }, denominator_{ 1 } {};
	Rational(int, int); //numerator, denominator
	Rational(const char*);
	Rational(const std::string&);
	Rational(const Rational& rational) : numerator_{ rational.numerator_ }, denominator_{ rational.denominator_ } {};
	Rational(Rational&&);

	Rational& operator=(const Rational&);
	Rational& operator=(Rational&&);
	Rational operator+(const Rational&) const;
	Rational operator+(int) const;
	Rational operator-(const Rational&) const;
	Rational operator-(int) const;
	Rational operator*(const Rational&) const;
	Rational operator*(int) const;
	Rational operator/(const Rational& rational) const;
	Rational operator/(int numerator) const;
	Rational operator^(int) const;

	Rational& operator++();
	Rational operator++(int);
	Rational& operator--();
	Rational operator--(int);

	bool operator==(const Rational&) const;
	bool operator==(const char*) const;
	bool operator==(const std::string&) const;
	bool operator!=(const Rational&) const;
	bool operator!=(const char*) const;
	bool operator!=(const std::string&) const;

	const int numerator() const { return numerator_; };
	const int denominator() const { return denominator_; };

	~Rational() = default;

};

std::ostream& operator<<(std::ostream&, const Rational&);
int gcd(int, int);
