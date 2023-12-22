#pragma once
#include <iostream>
#include <string>

using namespace std;

template <typename T>
T getValidNumberInput() {
	string input;
	do {
		cout << "Unos: ";
		cin >> input;
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		try {
			T option = stoi(input);
			return option;
		}
		catch (const invalid_argument& err) {
			cout << "Niste unijeli broj, molimo pokusajte ponovo!\n";
		}
	} while (true);
}