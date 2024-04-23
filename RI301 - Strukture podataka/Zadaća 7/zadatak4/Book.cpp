#include "Book.h"

Book::Book(const std::string& title, const std::string& author, const std::string& publisher, int year, unsigned int numberOfCopies) {
	setTitle(title);
	setAuthor(author);
	setPublisher(publisher);
	year_ = year;
	numberOfCopies_ = numberOfCopies;
	return;
}

Book::Book(Book&& second) : title_{ std::move(second.title_) }, author_{ std::move(second.author_) }, publisher_{ std::move(second.publisher_) }, year_{ second.year_ }, numberOfCopies_{ second.numberOfCopies_ } {
	second.year_ = 0;
	second.numberOfCopies_ = 0;
	return;
}

Book& Book::operator=(const Book& second) {
	title_ = second.title_;
	author_ = second.author_;
	publisher_ = second.publisher_;
	year_ = second.year_;
	numberOfCopies_ = second.numberOfCopies_;
	return *this;
}

Book& Book::operator=(Book&& second) {
	title_ = std::move(second.title_);
	author_ = std::move(second.author_);
	publisher_ = std::move(second.publisher_);
	year_ = second.year_;
	numberOfCopies_ = second.numberOfCopies_;
	second.year_ = 0;
	second.numberOfCopies_ = 0;
	return *this;
}

void Book::setTitle(const std::string& title) {
	if (title.length() < 2) {
		throw std::invalid_argument("Title must be at least 2 characters long!");
	}
	bool areAllSpace = true;
	size_t spaceCounter = 0;
	for (const char c : title) {
		if (c != ' ') {
			areAllSpace = false;
			break;
		}
		++spaceCounter;
	}
	if (areAllSpace) {
		throw std::invalid_argument("Title can't be empty string!");
	}
	std::string newTitle;
	if (spaceCounter == 0) {
		title_ = title;
		return;
	}
	else {
		newTitle = title.substr(spaceCounter, title.length());
	}
	if (newTitle.length() < 2) {
		throw std::invalid_argument("Title must be at least 2 characters long!");
	}
	title_ = std::move(newTitle);
	return;
}

void Book::setTitle(std::string&& title) {
	if (title.length() < 2) {
		throw std::invalid_argument("Title must be at least 2 characters long!");
	}
	bool areAllSpace = true;
	size_t spaceCounter = 0;
	for (const char c : title) {
		if (c != ' ') {
			areAllSpace = false;
			break;
		}
		++spaceCounter;
	}
	if (areAllSpace) {
		throw std::invalid_argument("Title can't be empty string!");
	}
	std::string newTitle;
	if (spaceCounter == 0) {
		title_ = std::move(title);
		return;
	}
	else {
		newTitle = title.substr(spaceCounter, title.length());
	}
	if (newTitle.length() < 2) {
		throw std::invalid_argument("Title must be at least 2 characters long!");
	}
	title_ = std::move(newTitle);
	return;
}

void Book::setAuthor(const std::string& author) {
	if (author.length() < 2) {
		throw std::invalid_argument("Author must be at least 2 characters long!");
	}
	bool areAllSpace = true;
	size_t spaceCounter = 0;
	for (const char c : author) {
		if (c != ' ') {
			areAllSpace = false;
			break;
		}
		++spaceCounter;
	}
	if (areAllSpace) {
		throw std::invalid_argument("Author can't be empty string!");
	}
	std::string newAuthor;
	if (spaceCounter == 0) {
		author_ = author;
		return;
	}
	else {
		newAuthor = author.substr(spaceCounter, author.length());
	}
	if (newAuthor.length() < 2) {
		throw std::invalid_argument("Author must be at least 2 characters long!");
	}
	author_ = std::move(newAuthor);
	return;
}

void Book::setAuthor(std::string&& author) {
	if (author.length() < 2) {
		throw std::invalid_argument("Author must be at least 2 characters long!");
	}
	bool areAllSpace = true;
	size_t spaceCounter = 0;
	for (const char c : author) {
		if (c != ' ') {
			areAllSpace = false;
			break;
		}
		++spaceCounter;
	}
	if (areAllSpace) {
		throw std::invalid_argument("Author can't be empty string!");
	}
	std::string newAuthor;
	if (spaceCounter == 0) {
		author_ = std::move(author);
		return;
	}
	else {
		newAuthor = author.substr(spaceCounter, author.length());
	}
	if (newAuthor.length() < 2) {
		throw std::invalid_argument("Author must be at least 2 characters long!");
	}
	author_ = std::move(newAuthor);
	return;
}

void Book::setPublisher(const std::string& publisher) {
	if (publisher.length() < 2) {
		throw std::invalid_argument("Publisher must be at least 2 characters long!");
	}
	bool areAllSpace = true;
	size_t spaceCounter = 0;
	for (const char c : publisher) {
		if (c != ' ') {
			areAllSpace = false;
			break;
		}
		++spaceCounter;
	}
	if (areAllSpace) {
		throw std::invalid_argument("Publisher can't be empty string!");
	}
	std::string newPublisher;
	if (spaceCounter == 0) {
		publisher_ = publisher;
		return;
	}
	else {
		newPublisher = publisher.substr(spaceCounter, publisher.length());
	}
	if (newPublisher.length() < 2) {
		throw std::invalid_argument("Publisher must be at least 2 characters long!");
	}
	publisher_ = std::move(newPublisher);
	return;
}

void Book::setPublisher(std::string&& publisher) {
	if (publisher.length() < 2) {
		throw std::invalid_argument("Publisher must be at least 2 characters long!");
	}
	bool areAllSpace = true;
	size_t spaceCounter = 0;
	for (const char c : publisher) {
		if (c != ' ') {
			areAllSpace = false;
			break;
		}
		++spaceCounter;
	}
	if (areAllSpace) {
		throw std::invalid_argument("Publisher can't be empty string!");
	}
	std::string newPublisher;
	if (spaceCounter == 0) {
		publisher_ = std::move(publisher);
		return;
	}
	else {
		newPublisher = publisher.substr(spaceCounter, publisher.length());
	}
	if (newPublisher.length() < 2) {
		throw std::invalid_argument("Publisher must be at least 2 characters long!");
	}
	publisher_ = std::move(newPublisher);
	return;
}

std::istream& operator>>(std::istream& inputStream, Book& book) {
	std::string inputString;
	int inputInt;
	std::cout << "Enter book title: ";
	inputStream >> inputString;
	book.setTitle(inputString);
	std::cout << "Enter book author: ";
	inputStream >> inputString;
	book.setAuthor(inputString);
	std::cout << "Enter book publisher: ";
	inputStream >> inputString;
	book.setPublisher(inputString);
	std::cout << "Enter year of publication: ";
	inputStream >> inputInt;
	book.setYear(inputInt);
	std::cout << "Enter number of copies available: ";
	inputStream >> inputInt;
	book.setNumberOfCopies(inputInt);
	return inputStream;
}

std::ostream& operator<<(std::ostream& outputStream, const Book& book) {
	outputStream << "Title: " << book.title_ << std::endl;
	outputStream << "Author: " << book.author_ << std::endl;
	outputStream << "Publisher: " << book.publisher_ << std::endl;
	outputStream << "Year of publication: " << book.year_ << std::endl;
	outputStream << "Available copies: " << book.numberOfCopies_ << std::endl;
	return outputStream;
}