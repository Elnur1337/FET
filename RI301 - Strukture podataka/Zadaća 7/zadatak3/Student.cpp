#include "Student.h"

Student::Student(const std::string& FirstName, const std::string& LastName, const std::string& IndexNumber, unsigned short Year, const std::vector<unsigned short>& Grades) {
	setFirstName(FirstName);
	setLastName(LastName);
	setIndexNumber(IndexNumber);
	setYear(Year);
	setGrades(Grades);
	return;
}

Student::Student(const std::string& FirstName, const std::string& LastName, size_t IndexNumber, unsigned short Year, const std::vector<unsigned short>& Grades) : firstName_{ FirstName }, lastName_{ LastName }, indexNumber_{ std::to_string(IndexNumber) } {
	setFirstName(FirstName);
	setLastName(LastName);
	setIndexNumber(IndexNumber);
	setYear(Year);
	setGrades(Grades);
	return;
}

Student::Student(const std::string& FirstName, const std::string& LastName, const std::string& IndexNumber, unsigned short Year, const std::initializer_list<unsigned short>& Grades) : firstName_{ FirstName }, lastName_{ LastName }, indexNumber_{ IndexNumber } {
	setFirstName(FirstName);
	setLastName(LastName);
	setIndexNumber(IndexNumber);
	setYear(Year);
	setGrades(Grades);
	return;
}

Student::Student(const std::string& FirstName, const std::string& LastName, size_t IndexNumber, unsigned short Year, const std::initializer_list<unsigned short>& Grades) : firstName_{ FirstName }, lastName_{ LastName }, indexNumber_{ std::to_string(IndexNumber) } {
	setFirstName(FirstName);
	setLastName(LastName);
	setIndexNumber(IndexNumber);
	setYear(Year);
	setGrades(Grades);
	return;
}

Student::Student(const Student& student) {
	firstName_ = student.firstName_;
	lastName_ = student.lastName_;
	indexNumber_ = student.indexNumber_;
	year_ = student.year_;
	std::copy(student.grades_.begin(), student.grades_.end(), std::back_inserter(grades_));
	return;
}

Student::Student(Student&& student) {
	firstName_ = std::move(student.firstName_);
	lastName_ = std::move(student.lastName_);
	indexNumber_ = std::move(student.indexNumber_);
	year_ = std::move(student.year_);
	grades_ = std::move(student.grades_);
	student.year_ = 1;
	return;
}

Student& Student::operator=(const Student& student) {
	grades_.clear();
	firstName_ = student.firstName_;
	lastName_ = student.lastName_;
	indexNumber_ = student.indexNumber_;
	year_ = student.year_;
	std::copy(student.grades_.begin(), student.grades_.end(), std::back_inserter(grades_));
	return *this;
}

Student& Student::operator=(Student&& student) {
	firstName_ = std::move(student.firstName_);
	lastName_ = std::move(student.lastName_);
	indexNumber_ = std::move(student.indexNumber_);
	year_ = std::move(student.year_);
	grades_ = std::move(student.grades_);
	return *this;
}

void Student::setFirstName(const std::string& FirstName) {
	if (FirstName.length() < 2) {
		throw std::invalid_argument("Ime mora biti vece od 2 karaktera!");
	}
	bool areAllSpace = true;
	size_t spaceCounter = 0;
	for (const char c : FirstName) {
		if (c != ' ') {
			areAllSpace = false;
			break;
		}
		++spaceCounter;
	}
	if (areAllSpace) {
		throw std::invalid_argument("Prezime ne moze biti sacinjeno samo od space karaktera!");
	}
	std::string newFirstName;
	if (spaceCounter == 0) {
		firstName_ = FirstName;
		return;
	}
	if (spaceCounter > 0) {
		newFirstName = FirstName.substr(spaceCounter, FirstName.length());
	}
	if (newFirstName.length() < 2) {
		throw std::invalid_argument("Ime mora biti vece od 2 karaktera!");
	}
	firstName_ = std::move(newFirstName);
	return;
}

void Student::setFirstName(std::string&& FirstName) {
	if (FirstName.length() < 2) {
		throw std::invalid_argument("Prezime mora biti vece od 2 karaktera!");
	}
	bool areAllSpace = true;
	size_t spaceCounter = 0;
	for (const char c : FirstName) {
		if (c != ' ') {
			areAllSpace = false;
			break;
		}
		++spaceCounter;
	}
	if (areAllSpace) {
		throw std::invalid_argument("Ime ne moze biti sacinjeno samo od space karaktera!");
	}
	if (spaceCounter == 0) {
		firstName_ = std::move(FirstName);
		return;
	}
	std::string newFirstName;
	if (spaceCounter > 0) {
		newFirstName = FirstName.substr(spaceCounter, FirstName.length());
	}
	if (newFirstName.length() < 2) {
		throw std::invalid_argument("Ime mora biti vece od 2 karaktera!");
	}
	FirstName.clear();
	firstName_ = std::move(newFirstName);
	return;
}

void Student::setLastName(const std::string& LastName) {
	if (LastName.length() < 2) {
		throw std::invalid_argument("Prezime mora biti vece od 2 karaktera!");
	}
	bool areAllSpace = true;
	size_t spaceCounter = 0;
	for (const char c : LastName) {
		if (c != ' ') {
			areAllSpace = false;
			break;
		}
		++spaceCounter;
	}
	if (areAllSpace) {
		throw std::invalid_argument("Prezime ne moze biti sacinjeno samo od space karaktera!");
	}
	std::string newLastName;
	if (spaceCounter == 0) {
		lastName_ = LastName;
		return;
	}
	if (spaceCounter > 0) {
		newLastName = LastName.substr(spaceCounter, LastName.length());
	}
	if (newLastName.length() < 2) {
		throw std::invalid_argument("Prezime mora biti vece od 2 karaktera!");
	}
	lastName_ = std::move(newLastName);
	return;
}

void Student::setLastName(std::string&& LastName) {
	if (LastName.length() < 2) {
		throw std::invalid_argument("Prezime mora biti vece od 2 karaktera!");
	}
	bool areAllSpace = true;
	size_t spaceCounter = 0;
	for (const char c : LastName) {
		if (c != ' ') {
			areAllSpace = false;
			break;
		}
		++spaceCounter;
	}
	if (areAllSpace) {
		throw std::invalid_argument("Prezime ne moze biti sacinjeno samo od space karaktera!");
	}
	if (spaceCounter == 0) {
		lastName_ = std::move(LastName);
		return;
	}
	std::string newLastName;
	if (spaceCounter > 0) {
		newLastName = LastName.substr(spaceCounter, LastName.length());
	}
	if (newLastName.length() < 2) {
		throw std::invalid_argument("Prezime mora biti vece od 2 karaktera!");
	}
	LastName.clear();
	firstName_ = std::move(newLastName);
	return;
}

void Student::setIndexNumber(const std::string& IndexNumber) {
	bool areAllSpace = true;
	size_t spaceCounter = 0;
	for (const char c : IndexNumber) {
		if (c != ' ') {
			areAllSpace = false;
			break;
		}
		++spaceCounter;
	}
	if (areAllSpace) {
		throw std::invalid_argument("Broj indeksa ne moze biti sacinjeno samo od space karaktera!");
	}
	if (spaceCounter == 0) {
		indexNumber_ = IndexNumber;
		return;
	}
	std::string newIndexNumber = IndexNumber.substr(spaceCounter, IndexNumber.length());
	indexNumber_ = std::move(newIndexNumber);
	return;
}

void Student::setIndexNumber(std::string&& IndexNumber) {
	bool areAllSpace = true;
	size_t spaceCounter = 0;
	for (const char c : IndexNumber) {
		if (c != ' ') {
			areAllSpace = false;
			break;
		}
		++spaceCounter;
	}
	if (areAllSpace) {
		throw std::invalid_argument("Broj indeksa ne moze biti sacinjeno samo od space karaktera!");
	}
	if (spaceCounter == 0) {
		indexNumber_ = std::move(IndexNumber);
		return;
	}
	std::string newIndexNumber = IndexNumber.substr(spaceCounter, IndexNumber.length());
	indexNumber_ = std::move(newIndexNumber);
	return;
}

void Student::setIndexNumber(size_t IndexNumber) {
	setIndexNumber(std::to_string(IndexNumber));
	return;
}

void Student::setYear(unsigned short Year) {
	if (Year < 1 || Year > 4) {
		throw std::invalid_argument("Unesena godina studija nije moguca!");
	}
	year_ = Year;
	return;
}

void Student::setGrades(const std::vector<unsigned short>& Grades) {
	for (const unsigned short ocjena : Grades) {
		if (ocjena < 6 || ocjena > 10) {
			throw std::invalid_argument("Sve ocjene nisu validne!");
		}
	}
	grades_.clear();
	std::copy(Grades.begin(), Grades.end(), std::back_inserter(grades_));
	return;
}

void Student::setGrades(std::vector<unsigned short>&& Grades) {
	for (const unsigned short ocjena : Grades) {
		if (ocjena < 6 || ocjena > 10) {
			throw std::invalid_argument("Sve ocjene nisu validne!");
		}
	}
	grades_ = std::move(Grades);
	return;
}

void Student::setGrades(const std::initializer_list<unsigned short>& Grades) {
	for (const unsigned short ocjena : Grades) {
		if (ocjena < 6 || ocjena > 10) {
			throw std::invalid_argument("Sve ocjene nisu validne!");
		}
	}
	grades_.clear();
	std::copy(Grades.begin(), Grades.end(), std::back_inserter(grades_));
	return;
}

double Student::getAvgGrade() const {
	int sum = 0;
	for (const unsigned short grade : grades_) {
		sum += grade;
	}
	return (sum / grades_.size());
}

std::istream& operator>>(std::istream& inputStream, Student& student) {
	std::string inputString;
	unsigned short inputShort;
	std::cout << "Unesite ime: ";
	inputStream >> inputString;
	student.setFirstName(inputString);
	std::cout << "Unesite prezime: ";
	inputStream >> inputString;
	student.setLastName(inputString);
	std::cout << "Unesite broj indeksa: ";
	inputStream >> inputString;
	student.setIndexNumber(inputString);
	std::cout << "Unesite godinu studija: ";
	inputStream >> inputShort;
	student.setYear(inputShort);
	std::cout << "Unos ocjena (unesite EXIT) za prekid unosa!" << std::endl;
	do {
		std::cout << "Unesite ocjenu: ";
		inputStream >> inputString;
		if (inputString == "EXIT") {
			return inputStream;
		}
		try
		{
			inputShort = std::stoi(inputString);
			if (inputShort < 6 || inputShort > 10) {
				throw std::invalid_argument("Unos nije validan!");
			}
			student.grades_.push_back(inputShort);
		}
		catch (const std::invalid_argument& e1)
		{
			std::cout << "Unos nije validan!" << std::endl;
		}

	} while (inputString != "EXIT");
	return inputStream;
}

std::ostream& operator<<(std::ostream& outputStream, const Student& student) {
	std::cout << "Ime: " << student.firstName_ << std::endl;
	std::cout << "Prezime: " << student.lastName_ << std::endl;
	std::cout << "Broj indeksa: " << student.indexNumber_ << std::endl;
	std::cout << "Godina studija: " << student.year_ << std::endl;
	std::cout << "Ocjene: ";
	const size_t size = student.grades_.size();
	for (size_t i = 0; i < size; ++i) {
		outputStream << student.grades_[i];
		if (i + 1 < size) {
			outputStream << ", ";
		}
	}
	return outputStream;
}