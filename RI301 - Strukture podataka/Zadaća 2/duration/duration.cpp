#include "duration.hpp"

Duration::Duration(const int& s) {
	if (s < 0) {
		throw std::out_of_range("Broj ne moze biti manji od 0!");
	}
	this->setDurationFromSeconds(s);
	return;
}

Duration::Duration(const int& h, const int& m, const int& s) {
	if (s > 59 || s < 0) {
		throw std::out_of_range("Unesene sekunde izvan dozvoljenog opsega!");
	}
	else if (m > 59 || m < 0) {
		throw std::out_of_range("Unesene minute izvan dozvoljenog opsega!");
	}
	else if (h < 0) {
		throw std::out_of_range("Uneseni sati izvan dozvoljenog opsega!");
	}
	hours = h;
	minutes = m;
	seconds = s;
	return;
}

Duration::Duration(const std::string& inputText) {
	std::string tempString = inputText;
	this->setDurationFromString(tempString);
	return;
}

Duration& Duration::set_s(const int& s) {
	if (s > 59 || s < 0) {
		throw std::out_of_range("Unesene sekunde izvan dozvoljenog opsega!");
	}
	seconds = s;
	return *this;
}

Duration& Duration::set_m(const int& m) {
	if (m > 59 || m < 0) {
		throw std::out_of_range("Unesene minute izvan dozvoljenog opsega!");
	}
	minutes = m;
	return *this;
}

Duration& Duration::set_h(const int& h) {
	if (h < 0) {
		throw std::out_of_range("Uneseni sati izvan dozvoljenog opsega!");
	}
	hours = h;
	return *this;
}

const int Duration::toSeconds() const {
	return seconds + minutes * 60 + hours * 60 * 60;
}

void Duration::setDurationFromSeconds(const int& s) {
	if (s < 60) {
		seconds = s;
		minutes = 0;
		hours = 0;
	}
	else {
		seconds = s % 60;
		unsigned int tempMinutes = s / 60;
		if (tempMinutes < 60) {
			minutes = tempMinutes;
			hours = 0;
		}
		else {
			minutes = tempMinutes % 60;
			hours = tempMinutes / 60;
		}
	}
	return;
}

void Duration::setDurationFromString(std::string& input) {
	std::regex timeRegex("^(?:[01]?[0-9]|2[0-3]):[0-5]?[0-9]""(?::[0-5]?[0-9])?$");
	if (!std::regex_match(input, timeRegex)) {
		throw std::invalid_argument("Neispravan format vremena!");
	}
	size_t cPos = input.find(':');
	this->set_h(stoi(input.substr(0, cPos)));
	input.erase(0, cPos + 1);
	cPos = input.find(':');
	this->set_m(stoi(input.substr(0, cPos)));
	input.erase(0, cPos + 1);
	this->set_s(stoi(input.substr(0, cPos)));
	return;
}

const bool Duration::operator==(const Duration& second) const {
	if (seconds != second.seconds || minutes != second.minutes || hours != second.hours) {
		return false;
	}
	return true;
}

const bool Duration::operator!=(const Duration& second) const {
	if (seconds == second.seconds && minutes == second.minutes && hours == second.hours) {
		return false;
	}
	return true;
}

const bool Duration::operator<(const Duration& second) const {
	if (this->toSeconds() < second.toSeconds()) {
		return true;
	}
	return false;
}

const bool Duration::operator>(const Duration& second) const {
	if (this->toSeconds() > second.toSeconds()) {
		return true;
	}
	return false;
}

const bool Duration::operator<=(const Duration& second) const {
	if (this->toSeconds() <= second.toSeconds()) {
		return true;
	}
	return false;
}

const bool Duration::operator>=(const Duration& second) const {
	if (this->toSeconds() >= second.toSeconds()) {
		return true;
	}
	return false;
}

Duration::operator bool() const {
	if (seconds == 0 && minutes == 0 && hours == 0) {
		return false;
	}
	return true;
}

bool Duration::operator!() const {
	if (seconds == 0 && minutes == 0 && hours == 0) {
		return true;
	}
	return false;
}

Duration Duration::operator+(const Duration& second) const {
	return Duration(this->toSeconds() + second.toSeconds());
}

Duration& Duration::operator+=(const Duration& second) {
	const int resultSeconds = this->toSeconds() + second.toSeconds();
	this->setDurationFromSeconds(resultSeconds);
	return *this;
}

Duration Duration::operator-(const Duration& second) const {
	if ((*this) < second) {
		throw std::out_of_range("Ne mozete oduzimati vece vrijeme od manjeg!");
	}
	return Duration(this->toSeconds() - second.toSeconds());
}

Duration& Duration::operator-=(const Duration& second) {
	if ((*this) < second) {
		throw std::out_of_range("Ne mozete oduzimati vece vrijeme od manjrg!");
	}
	const int resultSeconds = this->toSeconds() - second.toSeconds();
	this->setDurationFromSeconds(resultSeconds);
	return *this;
}

Duration Duration::operator*(const int& n) const {
	if (n < 0) {
		throw std::out_of_range("Broj ne moze biti manji od 0!");
	}
	return Duration((this->toSeconds()) * n);
}

Duration& Duration::operator*=(const int& n) {
	if (n < 0) {
		throw std::out_of_range("Broj ne moze biti manji od 0!");
	}
	const int resultSeconds = (this->toSeconds() * n);
	this->setDurationFromSeconds(resultSeconds);
	return *this;
}

Duration Duration::operator/(const int& n) const {
	if (n < 1) {
		throw std::out_of_range("Broj ne moze biti manji od 1!");
	}
	return Duration(this->toSeconds() / n);
}

Duration& Duration::operator/=(const int& n) {
	if (n < 1) {
		throw std::out_of_range("Broj ne moze biti manji od 1!");
	}
	const int resultSeconds = (this->toSeconds() / n);
	this->setDurationFromSeconds(resultSeconds);
	return *this;
}

std::ostream& operator<<(std::ostream& outputStream, const Duration& time) {
	outputStream << (time.get_h() < 10 ? "0" : "") << time.get_h() << ":" << (time.get_m() < 10 ? "0" : "") << time.get_m() << ":" << (time.get_s() < 10 ? "0" : "") << time.get_s();
	return outputStream;
}

std::istream& operator>>(std::istream& inputStream, Duration& time) {
	std::string inputLine;
	inputStream >> inputLine;
	time.setDurationFromString(inputLine);
	return inputStream;
}