#include <iostream>
#include "BST.hpp"

int main() {
	BST<int> bst;
	bst.add(5).add(2).add(1).add(6).add(10).add(8).add(50);
	bst.inorder([](int& e) {
			std::cout << e << std::endl;
			return;
		}
	);
	std::cout << std::endl;

	bst.remove(10);

	bst.inorder([](int& e) {
			std::cout << e << std::endl;
			return;
		}
	);
	std::cout << std::endl;
}
