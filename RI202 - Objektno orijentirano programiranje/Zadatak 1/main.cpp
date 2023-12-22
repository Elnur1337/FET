#include <iostream>
#include <vector>
#include <string>
#include "Book.h"
#include "getValidNumberInput.h"
#include "inputBooks.h"

using namespace std;
int main() {
	vector<Book> v;
	short option;

	do {
		cout << "Menu:\n";
		cout << "1. Unos knjiga\n";
		cout << "2. Prosjecna ocjena unesenih knjiga\n";
		cout << "3. Prikazi knjige koje imaju ocjenu iznad n\n";
		cout << "4. Pretrazi knjigu po autoru\n";
		cout << "5. Izlaz\n";
		option = getValidNumberInput<short>();


		switch (option) {
		case 1:
			inputBooks(v);
		}
	} while (option != 5);
	
	return 0;
}
