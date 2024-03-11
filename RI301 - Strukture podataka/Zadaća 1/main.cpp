#include "LongNumber.hpp"
#include <iostream>

// Nadoknada provjera 1
int main(int argc, char* argv[]) {
    LongNumber num1, num2;
    std::cout << "Enter first number: ";
    std::cin >> num1;
    std::cout << "Enter second number: ";
    std::cin >> num2;
    auto num3 = num1 + num2;
    if (num3) {
        std::cout << num1 << " + " << num2 << " = " << num3 << std::endl;
    }
    else {
        try {
            auto num4 = num1 / num2;
            std::cout << num1 << " / " << num2 << " = " << num4 << std::endl;
        }
        catch (const std::invalid_argument& arg) {
            std::cout << "Operation not permitted!" << std::endl;
        }
    }
    return 0;
}
