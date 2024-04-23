#include "Rational.hpp"

Rational::Rational(double decimalNumber) {
	int numberInt = decimalNumber;
	if (decimalNumber - numberInt == 0.0) {
		numerator_ = numberInt;
		denominator_ = 1;
		return;
	}
	size_t digits = 0;
	while (decimalNumber - numberInt != 0 && digits < 9) {
		decimalNumber *= 10;
		numberInt = decimalNumber;
		++digits;
	}
	numerator_ = numberInt;
	denominator_ = 1;
	for (size_t i = 0; i < digits; ++i) {
		denominator_ *= 10;
	}
	if (numerator_ == 0) {
		denominator_ = 1;
	}
	else {
		const int gcdNumber = gcd(std::abs(numerator_), std::abs(denominator_));
		if (gcdNumber != 1) {
			numerator_ /= gcdNumber;
			denominator_ /= gcdNumber;
		}
	}
	return;
}

Rational::Rational(int numerator, int denominator) : numerator_{ numerator } {
	if (denominator == 0) {
		throw std::invalid_argument("Denominator can't be zero!");
	}
	denominator_ = denominator;
	if ((numerator_ < 0 && denominator_ < 0) || (numerator_ >= 0 && denominator_ < 0)) {
		numerator_ *= -1;
		denominator_ *= -1;
	}
	if (numerator_ == 0) {
		denominator_ = 1;
	}
	else {
		const int gcdNumber = gcd(std::abs(numerator_), std::abs(denominator_));
		if (gcdNumber != 1) {
			numerator_ /= gcdNumber;
			denominator_ /= gcdNumber;
		}
	}
	return;
}

Rational::Rational(const char* rational) {
	const std::string rationalString = rational;
	if (isDigits(rationalString)) {
		numerator_ = std::stoi(rationalString);
		denominator_ = 1;

	}
	else if (isDigits(rationalString.substr(1, rationalString.length())) && rationalString.at(0) == '-') {
		numerator_ = std::stoi(rationalString.substr(1, rationalString.length())) * -1;
		denominator_ = 1;
	}
	else {
		const size_t delimiterPos = rationalString.find('/');
		if (delimiterPos == std::string::npos) {
			throw std::invalid_argument("Invalid format!");
		}
		const std::string numeratorString = rationalString.substr(0, delimiterPos);
		const std::string denominatorString = rationalString.substr(delimiterPos + 1, rationalString.length());
		if (numeratorString.length() < 1 || denominatorString.length() < 1 || (numeratorString.length() == 1 && numeratorString.at(0) == '-') || (denominatorString.length() == 1 && denominatorString.at(0) == '-')) {
			throw std::invalid_argument("Invalid format!");
		}
		if (isDigits(numeratorString)) {
			numerator_ = std::stoi(numeratorString);
		}
		else if (isDigits(numeratorString.substr(1, numeratorString.length())) && numeratorString.at(0) == '-') {
			numerator_ = std::stoi(numeratorString.substr(1, numeratorString.length())) * -1;
		}
		else {
			throw std::invalid_argument("Invalid format!");
		}
		if (isDigits(denominatorString)) {
			denominator_ = std::stoi(denominatorString);
		}
		else if (isDigits(denominatorString.substr(1, denominatorString.length())) && denominatorString.at(0) == '-') {
			denominator_ = std::stoi(denominatorString.substr(1, denominatorString.length())) * -1;
		}
		else {
			throw std::invalid_argument("Invalid format!");
		}
		if (denominator_ == 0) {
			throw std::invalid_argument("Denominator can't be zero!");
		}
		if ((numerator_ < 0 && denominator_ < 0) || (numerator_ >= 0 && denominator_ < 0)) {
			numerator_ *= -1;
			denominator_ *= -1;
		}
		if (numerator_ == 0) {
			denominator_ = 1;
		}
		else {
			const int gcdNumber = gcd(std::abs(numerator_), std::abs(denominator_));
			if (gcdNumber != 1) {
				numerator_ /= gcdNumber;
				denominator_ /= gcdNumber;
			}
		}
		return;
	}
}

Rational::Rational(const std::string& rational) {
	if (isDigits(rational)) {
		numerator_ = std::stoi(rational);
		denominator_ = 1;
	}
	else if (isDigits(rational.substr(1, rational.length())) && rational.at(0) == '-') {
		numerator_ = std::stoi(rational.substr(1, rational.length())) * -1;
		denominator_ = 1;
	}
	else {
		const size_t delimiterPos = rational.find('/');
		if (delimiterPos == std::string::npos) {
			throw std::invalid_argument("Invalid format!");
		}
		const std::string numeratorString = rational.substr(0, delimiterPos);
		const std::string denominatorString = rational.substr(delimiterPos + 1, rational.length());
		if (numeratorString.length() < 1 || denominatorString.length() < 1 || (numeratorString.length() == 1 && numeratorString.at(0) == '-') || (denominatorString.length() == 1 && denominatorString.at(0) == '-')) {
			throw std::invalid_argument("Invalid format!");
		}
		if (isDigits(numeratorString)) {
			numerator_ = std::stoi(numeratorString);
		}
		else if (isDigits(numeratorString.substr(1, numeratorString.length())) && numeratorString.at(0) == '-') {
			numerator_ = std::stoi(numeratorString.substr(1, numeratorString.length())) * -1;
		}
		else {
			throw std::invalid_argument("Invalid format!");
		}
		if (isDigits(denominatorString)) {
			denominator_ = std::stoi(denominatorString);
		}
		else if (isDigits(denominatorString.substr(1, denominatorString.length())) && denominatorString.at(0) == '-') {
			denominator_ = std::stoi(denominatorString.substr(1, denominatorString.length())) * -1;
		}
		else {
			throw std::invalid_argument("Invalid format!");
		}
		if (denominator_ == 0) {
			throw std::invalid_argument("Denominator can't be zero!");
		}
		if ((numerator_ < 0 && denominator_ < 0) || (numerator_ >= 0 && denominator_ < 0)) {
			numerator_ *= -1;
			denominator_ *= -1;
		}
		if (numerator_ == 0) {
			denominator_ = 1;
		}
		else {
			const int gcdNumber = gcd(std::abs(numerator_), std::abs(denominator_));
			if (gcdNumber != 1) {
				numerator_ /= gcdNumber;
				denominator_ /= gcdNumber;
			}
		}
		return;
	}
}

Rational::Rational(Rational&& rational) {
	numerator_ = std::move(rational.numerator_);
	denominator_ = std::move(rational.denominator_);
	rational.numerator_ = 0;
	rational.denominator_ = 1;
	return;
}

Rational& Rational::operator=(const Rational& rational) {
	numerator_ = rational.numerator_;
	denominator_ = rational.denominator_;
	return *this;
}

Rational& Rational::operator=(Rational&& rational) {
	numerator_ = std::move(rational.numerator_);
	denominator_ = std::move(rational.denominator_);
	rational.numerator_ = 0;
	rational.denominator_ = 1;
	return *this;
}

Rational Rational::operator+(const Rational& rational) const {
	if (denominator_ == rational.denominator_) {
		return Rational(numerator_ + rational.numerator_, denominator_);
	}
	Rational rational1 = *this;
	Rational rational2 = rational;
	if (rational1.denominator_ > rational2.denominator_) {
		if (rational1.denominator_ % rational2.denominator_ == 0) {
			rational2.numerator_ *= (rational1.denominator_ / rational2.denominator_);
			rational2.denominator_ *= (rational1.denominator_ / rational2.denominator_);
		}
	}
	else {
		if (rational2.denominator_ % rational1.denominator_ == 0) {
			rational1.numerator_ *= (rational2.denominator_ / rational1.denominator_);
			rational1.denominator_ *= (rational2.denominator_ / rational1.denominator_);
		}
	}
	if (rational1.denominator_ != rational2.denominator_) {
		const int tempDenominator = rational1.denominator_;
		rational1.numerator_ *= rational2.denominator_;
		rational1.denominator_ *= rational2.denominator_;
		rational2.numerator_ *= tempDenominator;
		rational2.denominator_ *= tempDenominator;
	}
	return Rational(rational1.numerator_ + rational2.numerator_, rational1.denominator_);
}

Rational Rational::operator+(int numerator) const {
	if (denominator_ == 1) {
		return Rational(numerator_ + numerator);
	}
	numerator *= denominator_;
	return Rational(numerator_ + numerator, denominator_);
}

Rational Rational::operator-(const Rational& rational) const {
	if (denominator_ == rational.denominator_) {
		return Rational(numerator_ - rational.numerator_, denominator_);
	}
	Rational rational1 = *this;
	Rational rational2 = rational;
	if (rational1.denominator_ > rational2.denominator_) {
		if (rational1.denominator_ % rational2.denominator_ == 0) {
			rational2.numerator_ *= (rational1.denominator_ / rational2.denominator_);
			rational2.denominator_ *= (rational1.denominator_ / rational2.denominator_);
		}
	}
	else {
		if (rational2.denominator_ % rational1.denominator_ == 0) {
			rational1.numerator_ *= (rational2.denominator_ / rational1.denominator_);
			rational1.denominator_ *= (rational2.denominator_ / rational1.denominator_);
		}
	}
	if (rational1.denominator_ != rational2.denominator_) {
		const int tempDenominator = rational1.denominator_;
		rational1.numerator_ *= rational2.denominator_;
		rational1.denominator_ *= rational2.denominator_;
		rational2.numerator_ *= tempDenominator;
		rational2.denominator_ *= tempDenominator;
	}
	return Rational(rational1.numerator_ - rational2.numerator_, rational1.denominator_);
}

Rational Rational::operator-(int numerator) const {
	if (denominator_ == 1) {
		return Rational(numerator_ - numerator);
	}
	numerator *= denominator_;
	return Rational(numerator_ - numerator, denominator_);
}

Rational Rational::operator*(const Rational& rational) const {
	return Rational(numerator_ * rational.numerator_, denominator_ * rational.denominator_);
}

Rational Rational::operator*(int numerator) const {
	return Rational(numerator_ * numerator, denominator_);
}

Rational Rational::operator*(double decimalNumber) const {
	const Rational decimalRational{ decimalNumber };
	return Rational(numerator_ * decimalRational.numerator_, denominator_ * decimalRational.denominator_);
}

Rational Rational::operator/(const Rational& rational) const {
	if (numerator_ % rational.numerator_ == 0 && denominator_ % rational.denominator_ == 0) {
		return Rational(numerator_ / rational.numerator_, denominator_ / rational.denominator_);
	}
	return Rational(numerator_ * rational.denominator_, denominator_ * rational.numerator_);
}

Rational Rational::operator/(int numerator) const {
	if (numerator_ % numerator == 0) {
		return Rational(numerator_ / numerator, denominator_);
	}
	return Rational(numerator_, denominator_ * numerator);
}

Rational Rational::operator^(int power) const {
	if (power == 0) {
		return Rational(1);
	}
	return Rational(pow(numerator_, power), pow(denominator_, power));
}

Rational& Rational::operator++() {
	numerator_ += denominator_;
	return *this;
}

Rational Rational::operator++(int) {
	const Rational returnValue = *this;
	numerator_ += denominator_;
	return returnValue;
}

Rational& Rational::operator--() {
	numerator_ -= denominator_;
	return *this;
}

Rational Rational::operator--(int) {
	const Rational returnValue = *this;
	numerator_ -= denominator_;
	return returnValue;
}

bool Rational::operator==(const Rational& rational) const {
	if (numerator_ == rational.numerator_ && denominator_ == rational.denominator_) {
		return true;
	}
	return false;
}

bool Rational::operator==(const char* rational) const {
	try {
		const Rational tempRational(rational);
		if (numerator_ == tempRational.numerator_ && denominator_ == tempRational.denominator_) {
			return true;
		}
		return false;

	}
	catch (const std::exception& e) {
		return false;
	}
}

bool Rational::operator==(const std::string& rational) const {
	try {
		const Rational tempRational(rational);
		if (numerator_ == tempRational.numerator_ && denominator_ == tempRational.denominator_) {
			return true;
		}
		return false;

	}
	catch (const std::exception& e) {
		return false;
	}
}

bool Rational::operator!=(const Rational& rational) const {
	if (numerator_ != rational.numerator_ || denominator_ != rational.denominator_) {
		return true;
	}
	return false;
}

bool Rational::operator!=(const char* rational) const {
	try {
		const Rational tempRational(rational);
		if (numerator_ != tempRational.numerator_ || denominator_ != tempRational.denominator_) {
			return true;
		}
		return false;

	}
	catch (const std::exception& e) {
		return true;
	}
}

bool Rational::operator!=(const std::string& rational) const {
	try {
		const Rational tempRational(rational);
		if (numerator_ != tempRational.numerator_ || denominator_ != tempRational.denominator_) {
			return true;
		}
		return false;

	}
	catch (const std::exception& e) {
		return true;
	}
}

std::ostream& operator<<(std::ostream& outputStream, const Rational& rational) {
	if (rational.denominator() != 1) {
		outputStream << rational.numerator() << "/" << rational.denominator();
	}
	else {
		outputStream << rational.numerator();
	}
	return outputStream;
}

int gcd(int numerator, int denominator) {
	const int num = numerator;
	const int denom = denominator;
	int shift;
	for (shift = 0; ((numerator | denominator) & 1) == 0; ++shift) {
		numerator >>= 1;
		denominator >>= 1;
	}
	while ((numerator & 1) == 0) {
		numerator >>= 1;
	}
	while (denominator != 0) {
		while ((denominator & 1) == 0) {
			denominator >>= 1;
		}
		if (numerator > denominator) {
			std::swap(numerator, denominator);
		}
		denominator -= numerator;
	}
	return numerator << shift;
}