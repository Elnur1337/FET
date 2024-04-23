#include <iostream>
#include "StudentService.h"
#include "showMenu.h"

int main() {
	StudentService studentska;
	unsigned short optionInput;
	do {
		showMenu();
		std::cout << "Unesite broj opcije: ";
		std::cin >> optionInput;
		Student inputStudent;
		std::string inputString;
		std::vector<Student> searchResult;
		switch (optionInput)
		{
		case 1:
			std::cin >> inputStudent;
			studentska.addStudent(std::move(inputStudent));
			break;
		case 2:
			std::cout << "Unesite broj indeksa: ";
			std::cin >> inputString;
			studentska.removeStudent(inputString);
			break;
		case 3:
			std::cout << "Unesite broj indeksa: ";
			std::cin >> inputString;
			studentska.editStudent(inputString);
			break;
		case 4:
			studentska.printAll();
			std::cout << std::endl;
			break;
		case 5:
			studentska.printAllSortedByFirstName();
			std::cout << std::endl;
			break;
		case 6:
			studentska.printAllSortedByLastName();
			std::cout << std::endl;
			break;
		case 7:
			studentska.printAllSortedByAvgGrade();
			std::cout << std::endl;
			break;
		case 8:
			std::cout << "Unesite godinu studija: ";
			std::cin >> inputString;
			studentska.printAllByYear(std::stoi(inputString));
			std::cout << std::endl;
			break;
		case 9:
			std::cout << "Unesite prosjek: ";
			std::cin >> inputString;
			studentska.printAllWithAvgGradeHigherThen(std::stod(inputString));
			std::cout << std::endl;
			break;
		case 10:
			std::cout << "Unesite godinu studija: ";
			std::cin >> inputString;
			studentska.printReportByYear(std::stoi(inputString));
			std::cout << std::endl;
			break;
		case 11:
			std::cout << "Unesite ime: ";
			std::cin >> inputString;
			searchResult = studentska.searchByFirstName(inputString);
			for (const Student& student : searchResult) {
				std::cout << student << std::endl << std::endl;
			}
			break;
		case 12:
			std::cout << "Unesite prezime: ";
			std::cin >> inputString;
			searchResult = studentska.searchByLastName(inputString);
			for (const Student& student : searchResult) {
				std::cout << student << std::endl << std::endl;
			}
			break;
		case 13:
			std::cout << "Unesite broj indeksa: ";
			std::cin >> inputString;
			searchResult = studentska.searchByIndexNumber(inputString);
			for (const Student& student : searchResult) {
				std::cout << student << std::endl << std::endl;
			}
			break;
		default:
			if (optionInput != 14) {
				std::cout << "Unesena opcija ne postoji!\n";
			}
			break;
		}
	} while (optionInput != 14);
	return 0;
}