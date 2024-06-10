#include <iostream>
#include "Heap.h"

int main() {
	Heap<int> heap;
	heap.push(1);
	std::cout << heap.max() << std::endl;
	heap.push(7);
	std::cout << heap.max() << std::endl;
	heap.push(2);
	std::cout << heap.max() << std::endl;
	heap.push(12);
	std::cout << heap.max() << std::endl;
	std::cout << heap << std::endl;
	return 0;
}