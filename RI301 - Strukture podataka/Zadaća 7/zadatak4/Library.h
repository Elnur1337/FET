#pragma once
#include <vector>
#include <algorithm>
#include <iterator>
#include "Book.h"
#include "User.h"

class Library {
private:
	struct LendedBook {
		Book book_;
		User user_;

		LendedBook() = default;
		LendedBook(const Book& book, const User& user) : book_{ book }, user_{ user } {};
	};
	std::vector<Book> books_;
	std::vector<User> users_;
	std::vector<LendedBook> lendedBooks_;

	std::vector<User> searchUsersByFirstName(const std::string&);
	std::vector<User> searchUsersByLastName(const std::string&);
public:
	Library() = default;
	Library(const Library&);
	Library(Library&& second) : books_{ std::move(second.books_) }, users_{ std::move(second.users_) }, lendedBooks_{ std::move(second.lendedBooks_) } {};

	Library& operator=(const Library&);
	Library& operator=(Library&&);

	void addBook();
	void addUser();
	void lendBook();
	void returnBook();

	std::vector<Book> searchBooksByTitle(const std::string&);
	std::vector<Book> searchBooksByAuthor(const std::string&);
	std::vector<Book> searchBooksByPublisher(const std::string&);
	std::vector<Book> searchBooksByYear(int);
};

