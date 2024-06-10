#include <iostream>
#include <string>
#include "Map.h"

int main() {
	Map<int, std::string> map;
	map.insert(3, "papir").insert(5, "olovka").insert(10, "tinta").insert(1, "sveska");
	std::cout << *map.find(5) << std::endl;
	map.erase(5);
	std::cout << map.find(5) << std::endl;
	map.clear();
	std::cout << map.find(5) << std::endl;
	return 0;
}