#pragma once
#include <iostream>
#include <string>
#include "DoubleLinkedList.h"

class Number {
private:
	DoubleLinkedList<int> digits_;
	bool isNegative_;

	void generateDigits(long long);

	Number divide(Number, Number, Number res = 0) const;
	Number reminder(Number, Number) const;

	friend std::istream& operator>>(std::istream&, Number&);
	friend std::ostream& operator<<(std::ostream&, const Number&);
public:
	Number();
	Number(long long);
	Number(int);
	Number(std::string);
	Number(const char*);
	Number(const Number&);
	Number(Number&&);

	Number& operator=(const Number&);
	Number& operator=(Number&&);
	Number& operator=(long long);

	Number operator+(const Number&) const;
	Number operator+(int) const;
	Number operator-(const Number&) const;
	Number operator-(int) const;
	Number operator*(const Number&) const;
	Number operator*(int) const;
	Number operator/(const Number&) const;
	Number operator/(int) const;

	Number& operator+=(const Number&);
	Number& operator+=(int);
	Number& operator-=(const Number&);
	Number& operator-=(int);
	Number& operator*=(const Number&);
	Number& operator*=(int);
	Number& operator/=(const Number&);
	Number& operator/=(int);

	bool operator==(const Number&) const;
	bool operator==(int) const;
	bool operator!=(const Number&) const;
	bool operator!=(int) const;
	bool operator>(const Number&) const;
	bool operator>(int) const;
	bool operator<(const Number&) const;
	bool operator<(int) const;
	bool operator>=(const Number&) const;
	bool operator>=(int) const;
	bool operator<=(const Number&) const;
	bool operator<=(int) const;

	Number operator^(const Number&) const;
	Number operator^(int) const;

	operator bool() const;
	bool operator!() const;

	Number& operator++();
	Number operator++(int);
	
	Number& operator--();
	Number operator--(int);

	Number operator%(const Number&) const;

	Number abs() const;
	bool isOdd() const;
	bool isEven() const;
	bool isPositive() const { return !isNegative_; };
	bool isNegative() const { return isNegative_; };
};