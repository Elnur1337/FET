#pragma once
#include <algorithm>
#include "Student.h"

class StudentService
{
private:
	std::vector<Student> students_;

public:
	StudentService() = default;
	StudentService(const StudentService&);
	StudentService(StudentService&&);

	StudentService& operator=(const StudentService&);
	StudentService& operator=(StudentService&&);

	StudentService& addStudent(const Student&);
	StudentService& addStudent(Student&&);

	Student removeStudent(const std::string&);
	Student removeStudent(size_t);

	void editStudent(const std::string&);
	void editStudent(size_t);

	void printAll();
	void printAllSortedByFirstName();
	void printAllSortedByLastName();
	void printAllSortedByAvgGrade();
	void printAllByYear(unsigned short) const;
	void printAllWithAvgGradeHigherThen(double) const;
	void printReportByYear(unsigned short) const;

	std::vector<Student> searchByFirstName(const std::string&) const;
	std::vector<Student> searchByLastName(const std::string&) const;
	std::vector<Student> searchByIndexNumber(const std::string&) const;
	std::vector<Student> searchByIndexNumber(size_t) const;
};