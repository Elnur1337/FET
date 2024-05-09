#include <iostream>
#include <vector>
#include "partition.h"
#include "stable_partition.h"

int main() {
    std::vector<int> v1{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    auto it1 = partition(v1.begin(), v1.end(), [](int elem) { return elem % 2 == 0; });
    for (int elem : v1) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
    std::cout << *it1 << std::endl << std::endl;

    std::vector<int> v2{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    auto it2 = stable_partition(v1.begin(), v1.end(), [](int elem) { return elem % 2 == 0; });
    for (int elem : v2) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
    std::cout << *it2 << std::endl;
	return 0;
}