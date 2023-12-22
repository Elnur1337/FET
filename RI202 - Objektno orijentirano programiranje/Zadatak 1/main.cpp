#include <iostream>
#include <vector>
#include "Book.h"

using namespace std;
int main() {
	vector<Book> v;
	unsigned short input;
	do {
		cout << "Menu:\n";
		cout << "1. Unos knjiga\n";
		cout << "2. Prosjecna ocjena unesenih knjiga\n";
		cout << "3. Prikazi knjige koje imaju ocjenu iznad n\n";
		cout << "4. Pretrazi knjigu po autoru\n";
		cout << "5. Izlaz\n";
		cout << "Unesite opciju: ";
		cin >> input;
	} while (input != 5);
	
	return 0;
}
