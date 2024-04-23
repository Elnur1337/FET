#pragma once
#include <iostream>
#include <string>

class Book {
private:
	std::string title_;
	std::string author_;
	std::string publisher_;
	int year_;
	unsigned int numberOfCopies_;

	friend std::istream& operator>>(std::istream&, Book&);
	friend std::ostream& operator<<(std::ostream&, const Book&);
public:
	Book() : year_{ 0 }, numberOfCopies_{ 0 } {};
	Book(const std::string&, const std::string&, const std::string&, int, unsigned int);
	Book(const Book& second) : title_{ second.title_ }, author_{ second.author_ }, publisher_{ second.publisher_ }, year_{ second.year_ }, numberOfCopies_{ second.numberOfCopies_ } {};
	Book(Book&&);

	Book& operator=(const Book&);
	Book& operator=(Book&&);

	void setTitle(const std::string&);
	void setTitle(std::string&&);
	void setAuthor(const std::string&);
	void setAuthor(std::string&&);
	void setPublisher(const std::string&);
	void setPublisher(std::string&&);
	void setYear(int year) { year_ = year; };
	void setNumberOfCopies(unsigned int numberOfCopies) { numberOfCopies_ = numberOfCopies; };

	std::string getTitle() const { return title_; };
	std::string getAuthor() const { return author_; };
	std::string getPublisher() const { return publisher_; };
	int getYear() const { return year_; };
	unsigned int getNumberOfCopies() const { return numberOfCopies_; };
};
