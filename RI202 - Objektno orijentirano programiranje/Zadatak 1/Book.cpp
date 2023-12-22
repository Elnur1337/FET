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