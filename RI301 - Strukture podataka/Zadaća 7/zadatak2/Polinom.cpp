#include "Polinom.h"

Polinom::Polinom(const Polinom& second) {
	koef_.resize(second.koef_.size());
	std::copy(second.koef_.begin(), second.koef_.end(), koef_.begin());
	return;
}

Polinom::Polinom(Polinom&& second) {
	koef_ = std::move(second.koef_);
	return;
}

Polinom::Polinom(const std::initializer_list<Rational>& second) {
	koef_.resize(second.size());
	std::copy(second.begin(), second.end(), koef_.begin());
	return;
}

Polinom::Polinom(const MojVektor<Rational>& second) {
	koef_ = second;
	return;
}

Polinom::Polinom(MojVektor<Rational>&& second) {
	koef_ = std::move(second);
	return;
}

Polinom::Polinom(const std::vector<Rational>& second) {
	koef_.resize(second.size());
	std::copy(second.begin(), second.end(), koef_.begin());
	return;
}

Polinom& Polinom::operator=(const Polinom& second) {
	koef_ = second.koef_;
	return *this;
}

Polinom& Polinom::operator=(Polinom&& second) {
	koef_ = std::move(second.koef_);
	return *this;
}

Polinom& Polinom::push_back(const Rational& rational) {
	koef_.push_back(rational);
	return *this;
}

Polinom& Polinom::push_back(Rational&& rational) {
	koef_.push_back(std::move(rational));
	return *this;
}

Polinom Polinom::operator+(const Polinom& second) const {
	Polinom returnValue;
	if (koef_.size() == second.koef_.size()) {
		for (size_t i = 0; i < koef_.size(); ++i) {
			returnValue.push_back(koef_[i] + second.koef_[i]);
		}
	}
	else if (koef_.size() > second.koef_.size()) {
		for (size_t i = 0, j = 0; i < koef_.size(); ++i, ++j) {
			if (j >= second.koef_.size()) {
				returnValue.push_back(koef_[i]);
			}
			else {
				returnValue.push_back(koef_[i] + second.koef_[i]);
			}
		}
	}
	else {
		for (size_t i = 0, j = 0; i < second.koef_.size(); ++i, ++j) {
			if (j >= koef_.size()) {
				returnValue.push_back(second.koef_[i]);
			}
			else {
				returnValue.push_back(koef_[i] + second.koef_[i]);
			}
		}
	}
	return returnValue;
}

Polinom Polinom::operator-(const Polinom& second) const {
	Polinom returnValue;
	if (koef_.size() == second.koef_.size()) {
		for (size_t i = 0; i < koef_.size(); ++i) {
			returnValue.push_back(koef_[i] - second.koef_[i]);
		}
	}
	else if (koef_.size() > second.koef_.size()) {
		for (size_t i = 0, j = 0; i < koef_.size(); ++i, ++j) {
			if (j >= second.koef_.size()) {
				returnValue.push_back(koef_[i]);
			}
			else {
				returnValue.push_back(koef_[i] - second.koef_[i]);
			}
		}
	}
	else {
		for (size_t i = 0, j = 0; i < second.koef_.size(); ++i, ++j) {
			if (j >= koef_.size()) {
				returnValue.push_back(second.koef_[i]);
			}
			else {
				returnValue.push_back(koef_[i] - second.koef_[i]);
			}
		}
	}
	return returnValue;
}

Polinom Polinom::operator*(const Polinom& second) const {
	Polinom returnValue;
	if (koef_.size() == 0 || second.koef_.size() == 0) {
		return returnValue;
	}
	size_t resultDegree = koef_.size() + second.koef_.size() - 1;
	returnValue.resize(resultDegree);
	for (size_t i = 0; i < koef_.size(); ++i) {
		for (size_t j = 0; j < second.koef_.size(); ++j) {
			Rational product = koef_.at(i) * second.koef_.at(j);
			returnValue.koef_[i + j] = returnValue.koef_[i + j] + product;
		}
	}
	return returnValue;
}

Rational Polinom::operator()(const Rational& value) const {
	Rational returnValue;
	for (size_t i = 0; i < koef_.size(); ++i) {
		returnValue = returnValue + (koef_[i] * (value ^ i));
	}
	return returnValue;
}

Polinom Polinom::izvod() const {
	Polinom returnValue;
	returnValue.resize(koef_.size() - 1);
	for (size_t i = 1; i < koef_.size(); ++i) {
		returnValue.koef_[i - 1] = koef_[i] * (int)i;
	}
	return returnValue;
}

void Polinom::resize(size_t newSize) {
	koef_.resize(newSize);
	return;
}

std::ostream& operator<<(std::ostream& outputStream, const Polinom& polinom) {
	size_t offset = 1;
	outputStream << "P(x) = ";
	for (int i = polinom.size() - 1; i >= 0; --i) {
		if (polinom.koef_[i].numerator() == 0) {
			++offset;
			continue;
		}
		if (i == 1) {
			if (polinom.koef_[i].denominator() == 1) {
				if (polinom.koef_[i].numerator() > 0) {
					if (i == polinom.size() - offset) {
						std::cout << polinom.koef_[i] << "x ";
					}
					else {
						std::cout << "+ " << polinom.koef_[i] << "x ";
					}
				}
				else if (polinom.koef_[i].numerator() < 0) {
					std::cout << "- " << abs(polinom.koef_[i].numerator()) << "x ";
				}
			}
			else {
				if (polinom.koef_[i].numerator() > 0) {
					if (i == polinom.size() - offset) {
						std::cout << "(" << polinom.koef_[i] << ")x ";
					}
					else {
						std::cout << "+ " << "(" << polinom.koef_[i] << ")x ";
					}
				}
				else if (polinom.koef_[i].numerator() < 0) {
					std::cout << "- " << "(" << abs(polinom.koef_[i].numerator()) << "/" << polinom.koef_[i].denominator() << ")x ";
				}
			}
		}
		else if (i == 0) {
			if (polinom.koef_[i].denominator() == 1) {
				if (polinom.koef_[i].numerator() > 0) {
					if (i == polinom.size() - offset) {
						std::cout << polinom.koef_[i] << " ";
					}
					else {
						std::cout << "+ " << polinom.koef_[i] << " ";
					}
				}
				else if (polinom.koef_[i].numerator() < 0) {
					std::cout << "- " << abs(polinom.koef_[i].numerator()) << " ";
				}
			}
			else {
				if (polinom.koef_[i].numerator() > 0) {
					if (i == polinom.size() - offset) {
						std::cout << "(" << polinom.koef_[i] << ") ";
					}
					else {
						std::cout << "+ " << "(" << polinom.koef_[i] << ") ";
					}
				}
				else if (polinom.koef_[i].numerator() < 0) {
					std::cout << "- " << "(" << abs(polinom.koef_[i].numerator()) << "/" << polinom.koef_[i].denominator() << ") ";
				}
			}
		}
		else {
			if (polinom.koef_[i].denominator() == 1) {
				if (polinom.koef_[i].numerator() > 0) {
					if (i == polinom.size() - offset) {
						std::cout << polinom.koef_[i] << "x^" << i << " ";
					}
					else {
						std::cout << "+ " << polinom.koef_[i] << "x^" << i << " ";
					}
				}
				else if (polinom.koef_[i].numerator() < 0) {
					std::cout << "- " << abs(polinom.koef_[i].numerator()) << "x^" << i << " ";
				}
			}
			else {
				if (polinom.koef_[i].numerator() > 0) {
					if (i == polinom.size() - offset) {
						std::cout << "(" << polinom.koef_[i] << ")x^" << i << " ";
					}
					else {
						std::cout << "+ " << "(" << polinom.koef_[i] << ")x^" << i << " ";
					}
				}
				else if (polinom.koef_[i].numerator() < 0) {
					std::cout << "- " << "(" << abs(polinom.koef_[i].numerator()) << "/" << polinom.koef_[i].denominator() << ")x^" << i << " ";
				}
			}
		}
	}
	if (offset - 1 == polinom.koef_.size()) {
		std::cout << 0;
	}
	return outputStream;
}

std::istream& operator>>(std::istream& inputStream, Polinom& polinom) {
	std::string inputString;
	std::cout << "Enter the polynomial numbers:\n";
	std::cout << "Type EXIT to stop input!\n";
	size_t i = 0;
	do {
		std::cout << "x^" << i << ": ";
		inputStream >> inputString;
		if (inputString == "EXIT") {
			continue;
		}
		else {
			try
			{
				polinom.push_back(inputString);
			}
			catch (const std::exception& e)
			{
				double inputDouble;
				try
				{
					inputDouble = std::stod(inputString);
					polinom.push_back(inputDouble);
					++i;
					continue;
				}
				catch (const std::exception& e2)
				{
					std::cout << "Invalid format!\n";
					continue;
				}
				std::cout << e.what() << std::endl;
				continue;
			}
		}
		++i;
	} while (inputString != "EXIT");
	return inputStream;
}