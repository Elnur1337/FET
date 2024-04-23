#include "Library.h"
#include "showMenu.h"

int main() {
	Library biblioteka;
	unsigned short optionInput;
	std::string stringInput;
	int intInput;
	std::vector<Book> searchResult;
	do {
		showMenu();
		std::cout << "Unesite broj opcije: ";
		std::cin >> optionInput;
		switch (optionInput)
		{
		case 1:
			biblioteka.addBook();
			break;
		case 2:
			biblioteka.addUser();
			break;
		case 3:
			biblioteka.lendBook();
			break;
		case 4:
			biblioteka.returnBook();
			break;
		case 5:
			std::cout << "Unesite naslov knjige za potragu: ";
			std::cin >> stringInput;
			searchResult = biblioteka.searchBooksByTitle(stringInput);
			for (const Book& book : searchResult) {
				std::cout << book << std::endl;
			}
			break;
		case 6:
			std::cout << "Unesite autora za potragu: ";
			std::cin >> stringInput;
			searchResult = biblioteka.searchBooksByAuthor(stringInput);
			for (const Book& book : searchResult) {
				std::cout << book << std::endl;
			}
			break;
		case 7:
			std::cout << "Unesite izdavaca knjige za potragu: ";
			std::cin >> stringInput;
			searchResult = biblioteka.searchBooksByPublisher(stringInput);
			for (const Book& book : searchResult) {
				std::cout << book << std::endl;
			}
			break;
		case 8:
			std::cout << "Unesite godinu izdanja knjige za potragu: ";
			std::cin >> intInput;
			searchResult = biblioteka.searchBooksByYear(intInput);
			for (const Book& book : searchResult) {
				std::cout << book << std::endl;
			}
			break;
		default:
			if (optionInput != 14) {
				std::cout << "Unesena opcija ne postoji!\n";
			}
			break;
		}
	} while (optionInput != 9);
	return 0;
}