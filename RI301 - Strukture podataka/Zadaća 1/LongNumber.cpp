#include "LongNumber.hpp"

LongNumber::LongNumber(const LongNumber& second) {
	number_ = second.number_;
	return;
}

LongNumber::LongNumber(LongNumber&& second) {
	number_ = std::move(second.number_);
	return;
}

LongNumber::LongNumber(const long long& second) {
	number_ = second;
	return;
}

LongNumber::LongNumber(long long&& second) {
	number_ = std::move(second);
	return;
}

LongNumber& LongNumber::operator=(const LongNumber& second) {
	number_ = second.number_;
	return *this;
}

LongNumber& LongNumber::operator=(LongNumber&& second) {
	number_ = std::move(second.number_);
	return *this;
}

LongNumber LongNumber::operator+(const LongNumber& second) const {
	return LongNumber(number_ + second.number_);
}

LongNumber LongNumber::operator-(const LongNumber& second) const {
	return LongNumber(number_ - second.number_);
}

LongNumber LongNumber::operator*(const LongNumber& second) const {
	return LongNumber(number_ * second.number_);
}

LongNumber LongNumber::operator/(const LongNumber& second) const {
	if (second.number_ == 0) {
		return LongNumber();
	}
	return LongNumber(number_ / second.number_);
}

LongNumber& LongNumber::operator+=(const LongNumber& second) {
	number_ += second.number_;
	return *this;
}

LongNumber& LongNumber::operator-=(const LongNumber& second) {
	number_ -= second.number_;
	return *this;
}

LongNumber& LongNumber::operator*=(const LongNumber& second) {
	number_ *= second.number_;
	return *this;
}

LongNumber& LongNumber::operator/=(const LongNumber& second) {
	if (second.number_ == 0) {
		number_ = 0;
	} else {
		number_ /= second.number_;
	}
	return *this;
}

LongNumber& LongNumber::operator=(const long long& second) {
	number_ = second;
	return *this;
}

LongNumber& LongNumber::operator=(long long&& second) {
	number_ = std::move(second);
	return *this;
}

LongNumber LongNumber::operator+(const long long& second) const {
	return LongNumber(number_ + second);
}

LongNumber LongNumber::operator-(const long long& second) const {
	return LongNumber(number_ - second);
}

LongNumber LongNumber::operator*(const long long& second) const {
	return LongNumber(number_ * second);
}

LongNumber LongNumber::operator/(const long long& second) const {
	if (second == 0) {
		return LongNumber();
	}
	return LongNumber(number_ / second);
}

LongNumber& LongNumber::operator+=(const long long& second) {
	number_ += second;
	return *this;
}

LongNumber& LongNumber::operator-=(const long long& second) {
	number_ -= second;
	return *this;
}

LongNumber& LongNumber::operator*=(const long long& second) {
	number_ *= second;
	return *this;
}

LongNumber& LongNumber::operator/=(const long long& second) {
	if (second == 0) {
		number_ = 0;
	}
	else {
		number_ /= second;
	}
	return *this;
}

bool LongNumber::operator==(const LongNumber& second) const {
	if (number_ == second.number_) {
		return true;
	}
	return false;
}

bool LongNumber::operator!=(const LongNumber& second) const {
	if (number_ != second.number_) {
		return true;
	}
	return false;
}

bool LongNumber::operator>(const LongNumber& second) const {
	if (number_ > second.number_) {
		return true;
	}
	return false;
}

bool LongNumber::operator<(const LongNumber& second) const {
	if (number_ < second.number_) {
		return true;
	}
	return false;
}

bool LongNumber::operator>=(const LongNumber& second) const {
	if (number_ >= second.number_) {
		return true;
	}
	return false;
}

bool LongNumber::operator<=(const LongNumber& second) const {
	if (number_ <= second.number_) {
		return true;
	}
	return false;
}

bool LongNumber::operator==(const long long& second) const {
	if (number_ == second) {
		return true;
	}
	return false;
}

bool LongNumber::operator!=(const long long& second) const {
	if (number_ != second) {
		return true;
	}
	return false;
}

bool LongNumber::operator>(const long long& second) const {
	if (number_ > second) {
		return true;
	}
	return false;
}

bool LongNumber::operator<(const long long& second) const {
	if (number_ < second) {
		return true;
	}
	return false;
}

bool LongNumber::operator>=(const long long& second) const {
	if (number_ >= second) {
		return true;
	}
	return false;
}

bool LongNumber::operator<=(const long long& second) const {
	if (number_ <= second) {
		return true;
	}
	return false;
}

LongNumber LongNumber::operator^(int n) const {
	if (n == 0) {
		return LongNumber(1);
	}
	long long number = number_;
	long long returnValue = number_;
	for (int i = 1; i < n; ++i) {
		returnValue *= number;
	}
	return LongNumber(returnValue);
}

LongNumber::operator bool() const {
	if (number_ == 0) {
		return false;
	}
	return true;
}

bool LongNumber::operator!() const {
	if (number_ == 0) {
		return true;
	}
	return false;
}

LongNumber& LongNumber::operator++() {
	++number_;
	return *this;
}

LongNumber LongNumber::operator++(int) {
	LongNumber returnValue = LongNumber(number_);
	++number_;
	return returnValue;
}

LongNumber& LongNumber::operator--() {
	--number_;
	return *this;
}

LongNumber LongNumber::operator--(int) {
	LongNumber returnValue = LongNumber(number_);
	--number_;
	return returnValue;
}

LongNumber LongNumber::abs() const {
	if (number_ >= 0) {
		return LongNumber(number_);
	}
	return LongNumber(number_ * (-1));
}

bool LongNumber::isOdd() const {
	if (number_ % 2 != 0) {
		return true;
	}
	return false;
}

bool LongNumber::isEven() const {
	if (number_ % 2 == 0) {
		return true;
	}
	return false;
}

bool LongNumber::isPositive() const {
	if (number_ > 0) {
		return true;
	}
	return false;
}

bool LongNumber::isNegative() const {
	if (number_ < 0) {
		return true;
	}
	return false;
}

const long long& LongNumber::value() const {
	return number_;
}

long long& LongNumber::num() {
	return number_;
}

void LongNumber::setLongNumber(const long long& input) {
	number_ = input;
}

std::ostream& operator<<(std::ostream& outputStream, const LongNumber& object) {
	outputStream << object.value();
	return outputStream;
}

std::istream& operator>>(std::istream& inputStream, LongNumber& object) {
	long long input;
	inputStream >> input;
	object.setLongNumber(input);
	return inputStream;
}