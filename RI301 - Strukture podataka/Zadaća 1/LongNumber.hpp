#pragma once

#include <iostream>

class LongNumber {
private:
	long long number_;

public:
	LongNumber() : number_{ 0 } {};
	LongNumber(const LongNumber&);
	LongNumber(LongNumber&&);
	LongNumber(const long long&);
	LongNumber(long long&&);

	LongNumber& operator=(const LongNumber&);
	LongNumber& operator=(LongNumber&&);
	LongNumber operator+(const LongNumber&) const;
	LongNumber operator-(const LongNumber&) const;
	LongNumber operator*(const LongNumber&) const;
	LongNumber operator/(const LongNumber&) const;
	LongNumber& operator+=(const LongNumber&);
	LongNumber& operator-=(const LongNumber&);
	LongNumber& operator*=(const LongNumber&);
	LongNumber& operator/=(const LongNumber&);
	LongNumber& operator=(const long long&);
	LongNumber& operator=(long long&&);
	LongNumber operator+(const long long&) const;
	LongNumber operator-(const long long&) const;
	LongNumber operator*(const long long&) const;
	LongNumber operator/(const long long&) const;
	LongNumber& operator+=(const long long&);
	LongNumber& operator-=(const long long&);
	LongNumber& operator*=(const long long&);
	LongNumber& operator/=(const long long&);

	bool operator==(const LongNumber&) const;
	bool operator!=(const LongNumber&) const;
	bool operator>(const LongNumber&) const;
	bool operator<(const LongNumber&) const;
	bool operator>=(const LongNumber&) const;
	bool operator<=(const LongNumber&) const;
	bool operator==(const long long&) const;
	bool operator!=(const long long&) const;
	bool operator>(const long long&) const;
	bool operator<(const long long&) const;
	bool operator>=(const long long&) const;
	bool operator<=(const long long&) const;
	LongNumber operator^(int) const;

	operator bool() const;

	bool operator!() const;

	LongNumber& operator++();
	LongNumber operator++(int);
	LongNumber& operator--();
	LongNumber operator--(int);

	LongNumber abs() const;
	bool isOdd() const;
	bool isEven() const;
	bool isPositive() const;
	bool isNegative() const;
	const long long& value() const;
	long long& num();

	void setLongNumber(const long long&);
};

std::ostream& operator<<(std::ostream&, const LongNumber&);
std::istream& operator>>(std::istream&, LongNumber&);
