#include <iostream>
#include <vector>
#include <string>
#include "Book.h"
#include "getValidNumberInput.h"
#include "inputBooks.h"
#include "getAvgRating.h"

using namespace std;
int main() {
	vector<Book> v;
	short option;

	do {
		cout << "Menu:\n";
		cout << "1. Unos knjiga\n";
		cout << "2. Prosjecna ocjena unesenih knjiga\n";
		cout << "3. Prikazi sve knjige\n";
		cout << "4. Prikazi knjige koje imaju ocjenu iznad n\n";
		cout << "5. Pretrazi knjigu po autoru\n";
		cout << "6. Izlaz\n";
		option = getValidNumberInput<short>();


		switch (option) {
		case 1:
			inputBooks(v);
			break;
		case 2:
			getAvgRating(v);
			break;
		case 3:
			if (v.size() == 0) {
				cout << "Nema unesenih knjiga!\n";
			}
			else {
				for (const Book& b : v) {
					b.getBook();
				}
			}
			break;
		case 4:
			short ratingN;
			cout << "Unesite ocjenu:\n";
			ratingN = getValidNumberInput<short>();
			if (v.size() == 0) {
				cout << "Nema unesenih knjiga!\n";
			}
			else {
				for (const Book& b : v) {
					if (b.getRating() > ratingN) {
						b.getBook();
					}
				}
			}
			break;
		case 5:
			if (v.size() == 0) {
				cout << "Nema unesenih knjiga!\n";
			}
			else {
				string author;
				cout << "Unesite ime autora za pretrazivanje: ";
				getline(cin, author);
				for (const Book& b : v) {
					if (b.getAuthor().find(author) != string::npos) {
						b.getBook();
					}
				}
			}
			break;
		default:
			break;
		}
	} while (option != 6);
	
	return 0;
}
