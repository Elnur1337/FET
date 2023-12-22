#include "inputBooks.h"
#include <iostream>
#include "getValidNumberInput.h"

using namespace std;

void inputBooks(vector<Book>& v) {
	int n;
	cout << "Koliko knjiga zelite da unesete:\n";
	do {
		n = getValidNumberInput<int>();
		if (n < 1) {
			cout << "Uneseni broj mora biti veci od 0!\n";
		}
	} while (n < 1);
	for (int i = 0; i < n; ++i) {
		Book newBook;
		newBook.setBook();
		v.push_back(newBook);
	}
	return;
}