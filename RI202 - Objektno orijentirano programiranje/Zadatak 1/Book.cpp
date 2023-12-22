#include "Book.h"
#include <iostream>

using namespace std;

void Book::setTitle()
{
	std::string input;
	cout << "Unesite naziv knjige: ";
	cin >> input;
	title = input;
	return;
}

void Book::setAuthor()
{
	std::string input;
	cout << "Unesite autora knjige: ";
	cin >> input;
	author = input;
	return;
}

void Book::setNumberOfPages() {
	int input;
	cout << "Unesite broj stranica: ";
	cin >> input;
	numberOfPages = input;
	return;
}

void Book::setRating() {
	unsigned short input;
	do {
		cout << "Unesite ocjenu(1 - 5): ";
		cin >> input;
		if (input < 1 || input > 5) {
			cout << "Ocjena moze biti samo od 1 do 5!\n";
			cout << "Molimo unesite ocjenu ponovo!\n\n";
		}
	} while (input < 1 || input > 5);
	rating = input;
	return;
}