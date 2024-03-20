#pragma once
#include <iostream>
#include <stdexcept>
#include <string>
#include <regex>

class Duration
{
private:
	unsigned short seconds;
	unsigned short minutes;
	unsigned int hours;

public:
	Duration() : seconds{ 0 }, minutes{ 0 }, hours{ 0 } {};
	Duration(const int&);
	Duration(const int&, const int&, const int&);
	Duration(const std::string&);

	const unsigned short get_s() const { return seconds; };
	const unsigned short get_m() const { return minutes; };
	const unsigned int get_h() const { return hours; };

	const int toSeconds() const;
	void setDurationFromSeconds(const int&);
	void setDurationFromString(std::string&);

	Duration& set_s(const int&);
	Duration& set_m(const int&);
	Duration& set_h(const int&);

	const bool operator==(const Duration&) const;
	const bool operator!=(const Duration&) const;
	const bool operator<(const Duration&) const;
	const bool operator>(const Duration&) const;
	const bool operator<=(const Duration&) const;
	const bool operator>=(const Duration&) const;

	explicit operator bool() const;
	bool operator!() const;

	Duration operator+(const Duration&) const;
	Duration& operator+=(const Duration&);

	Duration operator-(const Duration&) const;
	Duration& operator-=(const Duration&);

	Duration operator*(const int&) const;
	Duration& operator *=(const int&);

	Duration operator/(const int&) const;
	Duration& operator/=(const int&);
};

std::ostream& operator<<(std::ostream&, const Duration&);
std::istream& operator>>(std::istream&, Duration&);
