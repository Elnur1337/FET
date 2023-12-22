#include "Book.h"
#include <iostream>
#include "getValidNumberInput.h"

using namespace std;

void Book::setTitle()
{
	std::string input;
	cout << "Unesite naziv knjige: ";
	getline(cin, input);
	title = input;
	return;
}

void Book::setAuthor()
{
	std::string input;
	cout << "Unesite autora knjige: ";
	getline(cin, input);
	author = input;
	return;
}

void Book::setNumberOfPages() {
	cout << "Unesite broj stranica:\n";
	do {
		numberOfPages = getValidNumberInput<int>();
		if (numberOfPages < 1) {
			cout << "Knjiga ne moze imati manje od 1 stranice!\n";
		}
	} while (numberOfPages < 1);
	return;
}

void Book::setRating() {
	cout << "Unesite ocjenu(1 - 5):\n";
	do {
		rating = getValidNumberInput<short>();
		if (rating < 1 || rating > 5) {
			cout << "Ocjena moze biti samo od 1 do 5!\n";
			cout << "Molimo unesite ocjenu ponovo!\n";
		}
	} while (rating < 1 || rating > 5);
	return;
}

void Book::setBook() {
	setTitle();
	setAuthor();
	setNumberOfPages();
	setRating();
	return;
}

void Book::getBook() const {
	cout << "\nNaziv: " << title << endl;
	cout << "Autor: " << author << endl;
	cout << "Broj stranica: " << numberOfPages << endl;
	cout << "Ocjena: " << rating << endl << endl;
	return;
}