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
		try {
			T option = stoi(input);
			return option;
		}
		catch (const invalid_argument& err) {
			cout << "Niste unijeli broj, molimo pokusajte ponovo!\n";
		}
	} while (true);
}