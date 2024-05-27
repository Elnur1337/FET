#include "Number.hpp"

void Number::generateDigits(long long value) {
	if (value < 0) {
		isNegative_ = true;
		value *= -1;
	}
	else {
		isNegative_ = false;
	}
	if (value == 0) {
		digits_.push_front(value);
		return;
	}
	while (value != 0) {
		digits_.push_front(value % 10);
		value /= 10;
	}
	return;
}

Number Number::divide(Number djeljenik, Number djelitelj, Number res) const {
	if (djeljenik < djelitelj) {
		return res;
	}
	return divide(djeljenik - djelitelj, djelitelj, ++res);
}

Number Number::reminder(Number djeljenik, Number djeljitelj) const {
	if (djeljenik < djeljitelj) {
		return djeljenik;
	}
	return reminder(djeljenik - djeljitelj, djeljitelj);
}

Number::Number() : isNegative_{ false } {
	digits_.push_front(0);
	return;
}

Number::Number(long long value) {
	generateDigits(value);
	return;
}

Number::Number(int value) {
	generateDigits(value);
	return;
}

Number::Number(std::string value) {
	if (value.length() == 0) {
		throw std::invalid_argument("String is empty!");
	}
	bool areAllSpace{ true };
	size_t spaceCounter{ 0 };
	for (const char c : value) {
		if (c != ' ') {
			areAllSpace = false;
			break;
		}
		++spaceCounter;
	}
	if (areAllSpace) {
		throw std::invalid_argument("String must contain digits!");
	}
	if (spaceCounter > 0) {
		value = value.substr(spaceCounter, value.length());
	}
	if (value[0] == '-') {
		isNegative_ = true;
		value = value.substr(1, value.length());
		if (value.length() < 1) {
			throw std::invalid_argument("String must contain digits!");
		}
	}
	else {
		isNegative_ = false;
	}
	for (const char c : value) {
		if (c < '0' || c > '9') {
			throw std::invalid_argument("String can only contain digits!");
		}
	}
	for (char c : value) {
		digits_.push_back(std::stoi(std::string{ std::move(c) }));
	}
	return;
}

Number::Number(const char* valueArr) {
	std::string value{ valueArr };
	if (value.length() == 0) {
		throw std::invalid_argument("String is empty!");
	}
	bool areAllSpace{ true };
	size_t spaceCounter{ 0 };
	for (const char c : value) {
		if (c != ' ') {
			areAllSpace = false;
			break;
		}
		++spaceCounter;
	}
	if (areAllSpace) {
		throw std::invalid_argument("String must contain digits!");
	}
	if (spaceCounter > 0) {
		value = value.substr(spaceCounter, value.length());
	}
	if (value[0] == '-') {
		isNegative_ = true;
		value = value.substr(1, value.length());
		if (value.length() < 1) {
			throw std::invalid_argument("String must contain digits!");
		}
	}
	else {
		isNegative_ = false;
	}
	for (const char c : value) {
		if (c < '0' || c > '9') {
			throw std::invalid_argument("String can only contain digits!");
		}
	}
	for (char c : value) {
		digits_.push_back(std::stoi(std::string{ std::move(c) }));
	}
	return;
}

Number::Number(const Number& second) : digits_{ second.digits_ }, isNegative_{ second.isNegative_ } {};

Number::Number(Number&& second) : digits_{ std::move(second.digits_) }, isNegative_{ second.isNegative_ } {
	second.digits_.push_back(0);
	second.isNegative_ = false;
	return;
};

Number& Number::operator=(const Number& second) {
	digits_ = second.digits_;
	isNegative_ = second.isNegative_;
	return *this;
}

Number& Number::operator=(Number&& second) {
	digits_ = std::move(second.digits_);
	isNegative_ = second.isNegative_;
	second.digits_.push_back(0);
	second.isNegative_ = false;
	return *this;
}

Number& Number::operator=(long long value) {
	digits_.clear();
	generateDigits(value);
	return *this;
}

Number Number::operator+(const Number& second) const {
	Number returnValue;
	returnValue.digits_.clear();
	DoubleLinkedList<int>::Iterator nullIt{ nullptr };
	if (!isNegative_ && !second.isNegative_) {
		DoubleLinkedList<int>::Iterator it1{ digits_.rbegin() };
		DoubleLinkedList<int>::Iterator it2{ second.digits_.rbegin() };
		//Sabiranje
		while ((it1 != nullIt) && (it2 != nullIt)) {
			returnValue.digits_.push_front(*it1 + *it2);
			--it1;
			--it2;
		}
		if (it1 == nullIt) {
			while (it2 != nullIt) {
				returnValue.digits_.push_front(*it2);
				--it2;
			}
		}
		if (it2 == nullIt) {
			while (it1 != nullIt) {
				returnValue.digits_.push_front(*it1);
				--it1;
			}
		}
		//Smanjivanje koeficijenata
		it1 = returnValue.digits_.rbegin();
		while (it1 != nullIt) {
			if (*it1 >= 10) {
				*it1 -= 10;
				if (it1 - 1 == nullIt) {
					returnValue.digits_.push_front(0);
				}
				++(*(it1 - 1));
			}
			--it1;
		}
		return returnValue;
	}
	if (!isNegative_ && second.isNegative_) {
		if (this->abs() == second.abs()) {
			returnValue.digits_.push_front(0);
			return returnValue;
		}
		if (this->abs() > second.abs()) {
			DoubleLinkedList<int>::Iterator it1{ digits_.rbegin() };
			DoubleLinkedList<int>::Iterator it2{ second.digits_.rbegin() };
			while (it1 != nullIt && it2 != nullIt) {
				if (*it1 < *it2) {
					DoubleLinkedList<int>::Iterator it3 = it1 - 2;
					while (*(it1 - 1) == 0) {
						if (*it3 == 0) {
							--it3;
						}
						else {
							--(*it3);
							*(it3 + 1) += 10;
							++it3;
						}
					}
					--(*(it1 - 1));
					*it1 += 10;
				}
				returnValue.digits_.push_front(*it1 - *it2);
				--it1;
				--it2;
			}
			if (it1 == nullIt) {
				while (it2 != nullIt) {
					returnValue.digits_.push_front(*it2);
					--it2;
				}
			}
			if (it2 == nullIt) {
				while (it1 != nullIt) {
					returnValue.digits_.push_front(*it1);
					--it1;
				}
			}
			while (*(returnValue.digits_.begin()) == 0) {
				returnValue.digits_.pop_front();
			}
			return returnValue;
		}
		Number temp = *this;
		temp.isNegative_ = true;
		returnValue = second.abs() + temp;
		returnValue.isNegative_ = true;
		return returnValue;
	}
	if (isNegative_ && !second.isNegative_) {
		if (this->abs() == second.abs()) {
			returnValue.digits_.push_front(0);
			return returnValue;
		}
		return second + *this;
	}
	returnValue = this->abs() + second.abs();
	returnValue.isNegative_ = true;
	return returnValue;
}

Number Number::operator+(int second) const {
	return operator+(Number{ second });
}

Number Number::operator-(const Number& second) const {
	Number temp = second;
	temp.isNegative_ = !temp.isNegative_;
	return operator+(temp);
}

Number Number::operator-(int second) const {
	return operator-(Number{ second });
}

Number Number::operator*(const Number& second) const {
	if (*this == Number{ 0 } || second == Number{ 0 }) {
		return Number{ 0 };
	}
	if (*this == Number{ 1 } && second == Number{ 1 }) {
		return Number{ 1 };
	}
	if (*this == Number{ 1 } && second != Number{ 1 }) {
		return second;
	}
	if (*this != Number{ 1 } && second == Number{ 1 }) {
		return *this;
	}
	if (second.digits_.size() < digits_.size()) {
		return second.operator+(*this);
	}
	DoubleLinkedList<DoubleLinkedList<int>> matrix;
	DoubleLinkedList<int>::Iterator it1{ digits_.begin() };
	DoubleLinkedList<int>::Iterator it2;
	DoubleLinkedList<int>::Iterator it3;
	DoubleLinkedList<int>::Iterator nullIt{ nullptr };
	size_t offset{ 0 };
	while (it1 != nullIt) {
		DoubleLinkedList<int> row;
		for (size_t i = 0; i < second.digits_.size() + digits_.size() - 1; ++i) {
			row.push_back(0);
		}
		it2 = second.digits_.begin();
		it3 = row.begin() + offset;
		while (it2 != nullIt) {
			*it3 = (*it1) * (*it2);
			++it3;
			++it2;
		}
		matrix.push_back(std::move(row));
		++offset;
		++it1;
	}
	Number returnValue;
	returnValue.digits_.clear();
	DoubleLinkedList<DoubleLinkedList<int>>::Iterator it4{ matrix.begin() };
	it1 = it4->begin();
	DoubleLinkedList<DoubleLinkedList<int>>::Iterator nullItMatrix{ nullptr };
	offset = 0;
	int sum = 0;
	while (it1 != nullIt) {
		while (it4 != nullItMatrix) {
			it1 = it4->begin() + offset;
			sum += *it1;
			++it4;
		}
		returnValue.digits_.push_back(sum);
		it4 = matrix.begin();
		++offset;
		sum = 0;
		++it1;
	}
	//Smanjivanje koeficijenata
	it1 = returnValue.digits_.rbegin();
	while (it1 != nullIt) {
		if (*it1 >= 10) {
			*it1 -= 10;
			if (it1 - 1 == nullIt) {
				returnValue.digits_.push_front(0);
			}
			++(*(it1 - 1));
		}
		--it1;
	}
	if ((!isNegative_ && !second.isNegative_) || (isNegative_ && second.isNegative_)) {
		returnValue.isNegative_ = false;
	}
	else {
		returnValue.isNegative_ = true;
	}
	return returnValue;
}

Number Number::operator*(int second) const {
	return operator*(Number{ second });
}

Number Number::operator/(const Number& second) const {
	if (second == Number{ 0 }) {
		throw std::invalid_argument("Division by zero!");
	}
	Number returnValue = divide(this->abs(), second.abs());
	if ((!isNegative_ && !second.isNegative_) || (isNegative_ && second.isNegative_)) {
		returnValue.isNegative_ = false;
	}
	else {
		returnValue.isNegative_ = true;
	}
	return returnValue;
}

Number Number::operator/(int second) const {
	return operator/(Number{ second });
}

Number& Number::operator+=(const Number& second) {
	return *this = operator+(second);
}

Number& Number::operator+=(int second) {
	return *this = operator+(Number{ second });
}

Number& Number::operator-=(const Number& second) {
	return *this = operator-(second);
}

Number& Number::operator-=(int second) {
	return *this = operator-(Number{ second });
}

Number& Number::operator*=(const Number& second) {
	return *this = operator*(second);
}

Number& Number::operator*=(int second) {
	return *this = operator*(Number{ second });
}

Number& Number::operator/=(const Number& second) {
	return *this = operator/(second);
}

Number& Number::operator/=(int second) {
	return *this = operator/(Number{ second });
}

bool Number::operator==(const Number& second) const {
	if (isNegative_ != second.isNegative_) {
		return false;
	}
	if (digits_.size() != second.digits_.size()) {
		return false;
	}
	DoubleLinkedList<int>::Iterator it1 = digits_.begin();
	DoubleLinkedList<int>::Iterator it2 = second.digits_.begin();
	DoubleLinkedList<int>::Iterator nullIt{ nullptr };
	while (it1 != nullIt) {
		if (*it1 != *it2) {
			return false;
		}
		++it1;
		++it2;
	}
	return true;
}

bool Number::operator==(int second) const {
	return operator==(Number{ second });
}

bool Number::operator!=(const Number& second) const {
	return !(this->operator==(second));
}

bool Number::operator!=(int second) const {
	return operator!=(Number{ second });
}

bool Number::operator>(const Number& second) const {
	if (!isNegative_ && second.isNegative_) {
		return true;
	}
	if (isNegative_ && !second.isNegative_) {
		return false;
	}
	if (!isNegative_ && !second.isNegative_) {
		if (digits_.size() > second.digits_.size()) {
			return true;
		}
		if (digits_.size() == second.digits_.size()) {
			DoubleLinkedList<int>::Iterator it1 = digits_.begin();
			DoubleLinkedList<int>::Iterator it2 = second.digits_.begin();
			DoubleLinkedList<int>::Iterator nullIt{ nullptr };
			while (it1 != nullIt) {
				if (*it1 > *it2) {
					return true;
				}
				if (*it1 < *it2) {
					return false;
				}
				++it1;
				++it2;
			}
		}
		return false;
	}
	if (digits_.size() < second.digits_.size()) {
		return true;
	}
	if (digits_.size() == second.digits_.size()) {
		DoubleLinkedList<int>::Iterator it1 = digits_.begin();
		DoubleLinkedList<int>::Iterator it2 = second.digits_.begin();
		DoubleLinkedList<int>::Iterator nullIt{ nullptr };
		while (it1 != nullIt) {
			if (*it1 < *it2) {
				return true;
			}
			if (*it1 > *it2) {
				return false;
			}
			++it1;
			++it2;
		}
	}
	return false;
}

bool Number::operator>(int second) const {
	return operator>(Number{ second });
}

bool Number::operator<(const Number& second) const {
	return !operator>(second);
}

bool Number::operator<(int second) const {
	return !operator>(Number{ second });
}

bool Number::operator>=(const Number& second) const {
	return (operator>(second) || operator==(second));
}

bool Number::operator>=(int second) const {
	return (operator>(Number{ second }) || operator==(Number{ second }));
}

bool Number::operator<=(const Number& second) const {
	return (!operator>(second) || operator==(second));
}

bool Number::operator<=(int second) const {
	return (!operator>(Number{ second }) || operator==(Number{ second }));
}

Number Number::operator^(const Number& second) const {
	if (second == Number{ 0 }) {
		return Number{ 1 };
	}
	Number returnValue{ *this };
	for (Number i{ 2 }; i < second; ++i) {
		returnValue *= *this;
	}
	return returnValue;
}

Number Number::operator^(int second) const {
	return operator^(Number{ second });
}

Number::operator bool() const {
	if ((digits_.size() == 1) && (*(digits_.begin()) == 0)) {
		return false;
	}
	return true;
}

bool Number::operator!() const {
	return !(operator bool());
}

Number& Number::operator++() {
	return *this = operator+(Number{ 1 });
}

Number Number::operator++(int) {
	Number returnValue{ *this };
	operator++();
	return returnValue;
}

Number& Number::operator--() {
	return *this = operator-(Number{ 1 });
}

Number Number::operator--(int) {
	Number returnValue{ *this };
	operator--();
	return returnValue;
}

Number Number::operator%(const Number& second) const {
	return reminder(*this, second);
}

Number Number::abs() const {
	Number returnValue{ *this };
	returnValue.isNegative_ = false;
	return returnValue;
}

bool Number::isOdd() const {
	if (*this % Number{ 2 } != Number{ 0 }) {
		return true;
	}
	return false;
}

bool Number::isEven() const {
	if (*this % Number{ 2 } == Number{ 0 }) {
		return true;
	}
	return false;
}

std::istream& operator>>(std::istream& inputStream, Number& number) {
	std::string inputString;
	inputStream >> inputString;
	number = Number{ inputString };
	return inputStream;
}

std::ostream& operator<<(std::ostream& outputStream, const Number& number) {
	if (number.isNegative_) {
		outputStream << "-";
	}
	for (const int digit : number.digits_) {
		outputStream << digit;
	}
	return outputStream;
}