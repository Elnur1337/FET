#include "Library.h"

Library::Library(const Library& second) {
	books_.resize(second.books_.size());
	users_.resize(second.users_.size());
	lendedBooks_.resize(second.lendedBooks_.size());
	std::copy(second.books_.begin(), second.books_.end(), books_.begin());
	std::copy(second.users_.begin(), second.users_.end(), users_.begin());
	std::copy(second.lendedBooks_.begin(), second.lendedBooks_.end(), lendedBooks_.begin());
	return;
}

Library& Library::operator=(const Library& second) {
	books_.resize(second.books_.size());
	users_.resize(second.users_.size());
	lendedBooks_.resize(second.lendedBooks_.size());
	std::copy(second.books_.begin(), second.books_.end(), books_.begin());
	std::copy(second.users_.begin(), second.users_.end(), users_.begin());
	std::copy(second.lendedBooks_.begin(), second.lendedBooks_.end(), lendedBooks_.begin());
	return *this;
}

Library& Library::operator=(Library&& second) {
	books_ = std::move(second.books_);
	users_ = std::move(second.users_);
	lendedBooks_ = std::move(second.lendedBooks_);
	return *this;
}

void Library::addBook() {
	Book book;
	std::cin >> book;
	books_.push_back(std::move(book));
	return;
}

void Library::addUser() {
	User user;
	std::cin >> user;
	std::vector<User>::iterator it = std::find_if(users_.begin(), users_.end(), [user](const User& u) {
		return user.getId() == u.getId();
		}
	);
	if (it != users_.end()) {
		throw std::invalid_argument("User with that id already exists!");
	}
	users_.push_back(user);
	return;
}

std::vector<User> Library::searchUsersByFirstName(const std::string& firstName) {
	std::vector<User> returnValue;
	for (const User& user : users_) {
		if (user.getFirstName() == firstName) {
			returnValue.push_back(user);
		}
	}
	return returnValue;
}

std::vector<User> Library::searchUsersByLastName(const std::string& lastName) {
	std::vector<User> returnValue;
	for (const User& user : users_) {
		if (user.getLastName() == lastName) {
			returnValue.push_back(user);
		}
	}
	return returnValue;
}

void Library::lendBook() {
	std::cout << "Menu:\n";
	std::cout << "1. Search users by first name\n";
	std::cout << "2. Search users by last name\n";
	std::cout << "3. I already know user's id\n";
	short optionInput;
	std::cout << "Enter option number: ";
	std::cin >> optionInput;
	std::string inputString;
	do {
		switch (optionInput)
		{
		case 1:
			std::cout << "Enter user's first name: ";
			std::cin >> inputString;
			for (const User& user : searchUsersByFirstName(inputString)) {
				std::cout << user << std::endl;
			}
			break;
		case 2:
			std::cout << "Enter user's last name: ";
			std::cin >> inputString;
			for (const User& user : searchUsersByLastName(inputString)) {
				std::cout << user << std::endl;
			}
			break;
		case 3:
			break;
		default:
			std::cout << "That option doesn't exist, please choose again!\n";
			break;
		}
	} while (optionInput != 1 && optionInput != 2 && optionInput != 3);

	int userIdInput;
	std::cout << "Enter user's id: ";
	std::cin >> userIdInput;
	
	std::vector<LendedBook>::iterator isLending = std::find_if(lendedBooks_.begin(), lendedBooks_.end(), [userIdInput](const LendedBook& lendedBook) {
		return lendedBook.user_.getId() == userIdInput;
		}
	);

	if (isLending != lendedBooks_.end()) {
		throw std::invalid_argument("That user has already lended books!");
	}

	std::vector<User>::iterator userIt = std::find_if(users_.begin(), users_.end(), [userIdInput](const User& user) {
		return user.getId() == userIdInput;
		}
	);
	if (userIt == users_.end()) {
		throw std::invalid_argument("User with entered id doesn't exist!");
	}

	std::string bookTitleInput, bookAuthorInput;
	std::cout << "Enter book's title: ";
	std::cin >> bookTitleInput;
	std::cout << "Enter book's author: ";
	std::cin >> bookAuthorInput;

	std::vector<Book>::iterator bookIt = std::find_if(books_.begin(), books_.end(), [bookTitleInput, bookAuthorInput](const Book& book) {
		return (book.getTitle() == bookTitleInput && book.getAuthor() == bookAuthorInput);
		}
	);
	if (bookIt == books_.end()) {
		throw std::invalid_argument("Book with entered title and author doesn't exist!");
	}

	int numberInput;
	std::cout << "Enter number of books to lend: ";
	std::cin >> numberInput;
	if (numberInput > bookIt->getNumberOfCopies()) {
		throw std::invalid_argument("Library doesn't have that much copies!");
	}

	LendedBook lended;
	lended.book_ = *bookIt;
	bookIt->setNumberOfCopies(bookIt->getNumberOfCopies() - numberInput);
	lended.book_.setNumberOfCopies(numberInput);
	lended.user_ = *userIt;
	lendedBooks_.push_back(lended);
	return;
}

void Library::returnBook() {
	int userIdInput;
	std::cout << "Enter user's id: ";
	std::cin >> userIdInput;

	std::vector<LendedBook>::iterator isLending = std::find_if(lendedBooks_.begin(), lendedBooks_.end(), [userIdInput](const LendedBook& lendedBook) {
		return lendedBook.user_.getId() == userIdInput;
		}
	);

	if (isLending == lendedBooks_.end()) {
		throw std::invalid_argument("That user doesn't have lended books!");
	}
	int numberInput;
	std::cout << "Enter number of books returned: ";
	std::cin >> numberInput;

	if (numberInput > isLending->book_.getNumberOfCopies()) {
		throw std::invalid_argument("User hasn't landed that many copies!");
	}

	std::string bookTitle = isLending->book_.getTitle();
	std::string bookAuthor = isLending->book_.getAuthor();
	std::vector<Book>::iterator bookIt = std::find_if(books_.begin(), books_.end(), [bookTitle, bookAuthor](const Book& book) {
		return (book.getTitle() == bookTitle && book.getAuthor() == bookAuthor);
		}
	);

	if (numberInput < isLending->book_.getNumberOfCopies()) {
		isLending->book_.setNumberOfCopies(isLending->book_.getNumberOfCopies() - numberInput);
		bookIt->setNumberOfCopies(bookIt->getNumberOfCopies() + numberInput);
	}
	else {
		lendedBooks_.erase(isLending);
		bookIt->setNumberOfCopies(bookIt->getNumberOfCopies() + numberInput);
	}
	return;
}

std::vector<Book> Library::searchBooksByTitle(const std::string& title) {
	std::vector<Book> returnValue;
	for (const Book& book : books_) {
		if (book.getTitle() == title) {
			returnValue.push_back(book);
		}
	}
	return returnValue;
}

std::vector<Book> Library::searchBooksByAuthor(const std::string& author) {
	std::vector<Book> returnValue;
	for (const Book& book : books_) {
		if (book.getAuthor() == author) {
			returnValue.push_back(book);
		}
	}
	return returnValue;
}

std::vector<Book> Library::searchBooksByPublisher(const std::string& publisher) {
	std::vector<Book> returnValue;
	for (const Book& book : books_) {
		if (book.getPublisher() == publisher) {
			returnValue.push_back(book);
		}
	}
	return returnValue;
}

std::vector<Book> Library::searchBooksByYear(int year) {
	std::vector<Book> returnValue;
	for (const Book& book : books_) {
		if (book.getYear() == year) {
			returnValue.push_back(book);
		}
	}
	return returnValue;
}