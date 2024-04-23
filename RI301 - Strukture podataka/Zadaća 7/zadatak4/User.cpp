#include "User.h"

User::User(int id, const std::string& firstName, const std::string& lastName) {
	setFirstName(firstName);
	setLastName(lastName);
	id_ = id;
	return;
}

User::User(User&& second) : firstName_{ std::move(second.firstName_) }, lastName_{ std::move(second.lastName_) }, id_{ second.id_ } {
	second.id_ = 0;
	return;
}

User& User::operator=(const User& second) {
	id_ = second.id_;
	firstName_ = second.firstName_;
	lastName_ = second.lastName_;
	return *this;
}

User& User::operator=(User&& second) {
	id_ = second.id_;
	firstName_ = std::move(second.firstName_);
	lastName_ = std::move(second.lastName_);
	second.id_ = 0;
	return *this;
}

void User::setFirstName(const std::string& firstName) {
	if (firstName.length() < 2) {
		throw std::invalid_argument("First name must be at least 2 characters long!");
	}
	bool areAllSpace = true;
	size_t spaceCounter = 0;
	for (const char c : firstName) {
		if (c != ' ') {
			areAllSpace = false;
			break;
		}
		++spaceCounter;
	}
	if (areAllSpace) {
		throw std::invalid_argument("First name can't be empty string!");
	}
	std::string newFirstName;
	if (spaceCounter == 0) {
		firstName_ = firstName;
		return;
	}
	else {
		newFirstName = firstName.substr(spaceCounter, firstName.length());
	}
	if (newFirstName.length() < 2) {
		throw std::invalid_argument("First name must be at least 2 characters long!");
	}
	firstName_ = std::move(newFirstName);
	return;
}

void User::setFirstName(std::string&& firstName) {
	if (firstName.length() < 2) {
		throw std::invalid_argument("First name must be at least 2 characters long!");
	}
	bool areAllSpace = true;
	size_t spaceCounter = 0;
	for (const char c : firstName) {
		if (c != ' ') {
			areAllSpace = false;
			break;
		}
		++spaceCounter;
	}
	if (areAllSpace) {
		throw std::invalid_argument("First name can't be empty string!");
	}
	std::string newFirstName;
	if (spaceCounter == 0) {
		firstName_ = std::move(firstName);
		return;
	}
	else {
		newFirstName = firstName.substr(spaceCounter, firstName.length());
	}
	if (newFirstName.length() < 2) {
		throw std::invalid_argument("First name must be at least 2 characters long!");
	}
	firstName_ = std::move(newFirstName);
	return;
}

void User::setLastName(const std::string& lastName) {
	if (lastName.length() < 2) {
		throw std::invalid_argument("Last name must be at least 2 characters long!");
	}
	bool areAllSpace = true;
	size_t spaceCounter = 0;
	for (const char c : lastName) {
		if (c != ' ') {
			areAllSpace = false;
			break;
		}
		++spaceCounter;
	}
	if (areAllSpace) {
		throw std::invalid_argument("Last name can't be empty string!");
	}
	std::string newLastName;
	if (spaceCounter == 0) {
		lastName_ = lastName;
		return;
	}
	else {
		newLastName = lastName.substr(spaceCounter, lastName.length());
	}
	if (newLastName.length() < 2) {
		throw std::invalid_argument("Last name must be at least 2 characters long!");
	}
	lastName_ = std::move(newLastName);
	return;
}

void User::setLastName(std::string&& lastName) {
	if (lastName.length() < 2) {
		throw std::invalid_argument("Last name must be at least 2 characters long!");
	}
	bool areAllSpace = true;
	size_t spaceCounter = 0;
	for (const char c : lastName) {
		if (c != ' ') {
			areAllSpace = false;
			break;
		}
		++spaceCounter;
	}
	if (areAllSpace) {
		throw std::invalid_argument("Last name can't be empty string!");
	}
	std::string newLastName;
	if (spaceCounter == 0) {
		lastName_ = std::move(lastName);
		return;
	}
	else {
		newLastName = lastName.substr(spaceCounter, lastName.length());
	}
	if (newLastName.length() < 2) {
		throw std::invalid_argument("Last name must be at least 2 characters long!");
	}
	lastName_ = std::move(newLastName);
	return;
}

std::istream& operator>>(std::istream& inputStream, User& user) {
	std::string inputString;
	int inputInt;
	std::cout << "Enter user's first name: ";
	inputStream >> inputString;
	user.setFirstName(inputString);
	std::cout << "Enter user's last name: ";
	inputStream >> inputString;
	user.setLastName(inputString);
	std::cout << "Enter user's id: ";
	inputStream >> inputInt;
	user.setId(inputInt);
	return inputStream;
}

std::ostream& operator<<(std::ostream& outputStream, const User& user) {
	outputStream << "Id: " << user.id_ << std::endl;
	outputStream << "First name: " << user.firstName_ << std::endl;
	outputStream << "Last name: " << user.lastName_ << std::endl;
	return outputStream;
}