#pragma once
#include <string>

class Book {
private:
	std::string title;
	std::string author;
	int numberOfPages = 0;
	unsigned short rating = 0;

public:
	void setTitle();
	void setAuthor();
	void setNumberOfPages();
	void setRating();

	std::string getTitle() const { return title; }
	std::string getAuthor() const { return author; }
	int getNumberOfPages() const { return numberOfPages; }
	unsigned short getRating() const { return rating; }

	void getBook();
};