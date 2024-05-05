#include <iostream>
#include "SortedSingleLinkedList.hpp"

int main() {
	SortedSingleLinkedList<int> lista;
	lista.add(4).add(-4).add(0).add(1000).add(50).add(-5);
	std::cout << lista << std::endl;
	return 0;
}