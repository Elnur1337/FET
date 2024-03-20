#include <iostream>
#include "duration.hpp"

int main() {
	// ovdje možete samostalno testirati neke funkcionalnosti. 
	// Napomena: main.cpp se ne pregleda, sva implementacija 
	// ide u duration .cpp i .hpp fileove.
	/*Duraiton d1{1, 2, 3};
	std::cout << (d1 + Duration{3, 2, 1}) << std::endl;*/

	Duration d;
	std::cout << d.get_s() << std::endl;
	std::cout << d.get_m() << std::endl;
	std::cout << d.get_h() << std::endl;
}
