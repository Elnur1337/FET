#include <iostream>
#include <algorithm>
#include "DoubleLinkedList.hpp"

int main() {
    DoubleLinkedList<int> lista;
    lista.push_back(1).push_back(2).push_back(3).push_back(4);
    auto it = std::find_if(lista.begin(), lista.end(),
        [](const auto& el) { return el == 4; });
    if (it == lista.end()) {
        std::cout << "Ne postoji!" << std::endl;
    }
    else {
        std::cout << "Postoji!" << std::endl;
    }
    return 0;
}
