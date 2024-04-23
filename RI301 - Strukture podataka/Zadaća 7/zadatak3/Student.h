#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <initializer_list>
#include <stdexcept>
#include <iterator>

class Student
{
private:
	std::string firstName_;
	std::string lastName_;
	std::string indexNumber_;
	unsigned short year_;
	std::vector<unsigned short> grades_;

	friend std::istream& operator>>(std::istream&, Student&);
	friend std::ostream& operator<<(std::ostream&, const Student&);

public:
	Student() : year_{ 1 } {};
	Student(const std::string&, const std::string&, const std::string&, unsigned short, const std::vector<unsigned short>&);
	Student(const std::string&, const std::string&, size_t, unsigned short, const std::vector<unsigned short>&);
	Student(const std::string&, const std::string&, const std::string&, unsigned short, const std::initializer_list<unsigned short>&);
	Student(const std::string&, const std::string&, size_t, unsigned short, const std::initializer_list<unsigned short>&);
	Student(const Student&);
	Student(Student&&);

	Student& operator=(const Student&);
	Student& operator=(Student&&);

	void setFirstName(const std::string&);
	void setFirstName(std::string&&);
	void setLastName(const std::string&);
	void setLastName(std::string&&);
	void setIndexNumber(const std::string&);
	void setIndexNumber(std::string&&);
	void setIndexNumber(size_t);
	void setYear(unsigned short);
	void setGrades(const std::vector<unsigned short>&);
	void setGrades(std::vector<unsigned short>&&);
	void setGrades(const std::initializer_list<unsigned short>&);

	std::string getFirstName() const { return firstName_; };
	std::string getLastName() const { return lastName_; };
	std::string getIndexNumber() const { return indexNumber_; };
	unsigned short getYear() const { return year_; };
	std::vector<unsigned short> getGrades() const { return grades_; };
	double getAvgGrade() const;
};

