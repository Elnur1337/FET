#include <iterator>
#include "StudentService.h"

StudentService::StudentService(const StudentService& second) {
	students_ = second.students_;
	return;
}

StudentService::StudentService(StudentService&& second) {
	students_ = std::move(second.students_);
	return;
}

StudentService& StudentService::operator=(const StudentService& second) {
	students_.clear();
	students_.resize(second.students_.size());
	std::copy(second.students_.begin(), second.students_.end(), students_.begin());
	return *this;
}

StudentService& StudentService::operator=(StudentService&& second) {
	students_ = std::move(second.students_);
	return *this;
}

StudentService& StudentService::addStudent(const Student& student) {
	std::vector<Student>::iterator it = std::find_if(students_.begin(), students_.end(), [student](const Student& s) {
		return student.getIndexNumber() == s.getIndexNumber();
		}
	);
	if (it != students_.end()) {
		throw std::invalid_argument("Student with that index number already exists!");
	}
	students_.push_back(student);
	return *this;
}

StudentService& StudentService::addStudent(Student&& student) {
	std::vector<Student>::iterator it = std::find_if(students_.begin(), students_.end(), [student](const Student& s) {
		return student.getIndexNumber() == s.getIndexNumber();
		}
	);
	if (it != students_.end()) {
		throw std::invalid_argument("Student with that index number already exists!");
	}
	students_.push_back(std::move(student));
	return *this;
}

Student StudentService::removeStudent(const std::string& indexNumber) {
	std::vector<Student>::iterator it = std::find_if(students_.begin(), students_.end(), [indexNumber](const Student& s) {
		return indexNumber == s.getIndexNumber();
		}
	);
	Student returnValue = *it;
	students_.erase(it);
	return returnValue;
}

Student StudentService::removeStudent(size_t indexNumber) {
	return removeStudent(std::to_string(indexNumber));
}

void StudentService::editStudent(const std::string& indexNumber) {
	std::vector<Student>::iterator it = std::find_if(students_.begin(), students_.end(), [indexNumber](const Student& s) {
		return indexNumber == s.getIndexNumber();
		}
	);
	std::cout << *it << std::endl << std::endl;
	Student newStudent;
	std::cout << "Unesite nove podatke" << std::endl;
	std::cin >> newStudent;
	*it = newStudent;
	return;
}

void StudentService::editStudent(size_t indexNumber) {
	editStudent(std::to_string(indexNumber));
	return;
}

void StudentService::printAll() {
	for (const Student& student : students_) {
		std::cout << student << std::endl << std::endl;
	}
}

void StudentService::printAllSortedByFirstName() {
	std::sort(students_.begin(), students_.end(), [](const Student& s1, const Student& s2) {
		return s1.getFirstName() < s2.getFirstName();
		}
	);
	printAll();
	return;
}

void StudentService::printAllSortedByLastName() {
	std::sort(students_.begin(), students_.end(), [](const Student& s1, const Student& s2) {
		return s1.getLastName() < s2.getLastName();
		}
	);
	printAll();
	return;
}

void StudentService::printAllSortedByAvgGrade() {
	std::sort(students_.begin(), students_.end(), [](const Student& s1, const Student& s2) {
		return s2.getAvgGrade() < s1.getAvgGrade();
		}
	);
	printAll();
	return;
}

void StudentService::printAllByYear(unsigned short year) const {
	if (year < 1 || year > 4) {
		throw std::invalid_argument("Year must be within range [1, 4]");
	}
	for (const Student& student : students_) {
		if (student.getYear() == year)
			std::cout << student << std::endl << std::endl;
	}
	return;
}

void StudentService::printAllWithAvgGradeHigherThen(double grade) const {
	for (const Student& student : students_) {
		if (student.getAvgGrade() > grade)
			std::cout << student << std::endl << std::endl;
	}
	return;
}

void StudentService::printReportByYear(unsigned short year) const {
	if (year < 1 || year > 4) {
		throw std::invalid_argument("Year must be within range [1, 4]");
	}
	size_t numberOfStudents = 0;
	size_t numberOfGrades = 0;
	std::vector<int> numberOfGradesSpecific;
	size_t sumGrade = 0;
	numberOfGradesSpecific.resize(5, 0);
	std::vector<unsigned short> grades;
	for (const Student& student : students_) {
		if (student.getYear() != year) {
			continue;
		}
		++numberOfStudents;
		grades = student.getGrades();
		numberOfGrades += grades.size();
		for (const unsigned short grade : grades) {
			++numberOfGradesSpecific[grade - 6];
		}
	}
	std::cout << "Broj studenata na " << year << ". godini: " << numberOfStudents << std::endl;
	std::cout << "Ukupan broj ocjena na " << year << ". godini: " << numberOfGrades << std::endl;
	for (unsigned int i = 0; i < numberOfGradesSpecific.size(); ++i) {
		sumGrade += numberOfGradesSpecific[i] * (i + 6);
		std::cout << "Ukupan broj ocjene " << i + 6 << " na " << year << ". godini: " << numberOfGradesSpecific[i] << std::endl;

	}
	std::cout << "Prosjecna ocjena na " << year << ". godini: " << (double)sumGrade / numberOfGrades << std::endl;
	return;
}

std::vector<Student> StudentService::searchByFirstName(const std::string& firstName) const {
	std::vector<Student> returnValue;
	std::copy_if(students_.begin(), students_.end(), std::back_inserter(returnValue), [firstName](const Student& student) {
		return student.getFirstName() == firstName;
		}
	);
	return returnValue;
}

std::vector<Student> StudentService::searchByLastName(const std::string& lastName) const {
	std::vector<Student> returnValue;
	std::copy_if(students_.begin(), students_.end(), std::back_inserter(returnValue), [lastName](const Student& student) {
		return student.getLastName() == lastName;
		}
	);
	return returnValue;
}

std::vector<Student> StudentService::searchByIndexNumber(const std::string& indexNumber) const {
	std::vector<Student> returnValue;
	std::copy_if(students_.begin(), students_.end(), std::back_inserter(returnValue), [indexNumber](const Student& student) {
		return student.getIndexNumber() == indexNumber;
		}
	);
	return returnValue;
}

std::vector<Student> StudentService::searchByIndexNumber(size_t indexNumber) const {
	return searchByIndexNumber(std::to_string(indexNumber));
}