#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "../Matrix.hpp"

TEST_CASE(
    "Move constructor creates a new matrix with the same elements as the "
    "original, and empties the original")
{
    Matrix<int> original(2, 3);
    original.at(0, 0) = 1;
    original.at(0, 1) = 2;
    original.at(0, 2) = 3;
    original.at(1, 0) = 4;
    original.at(1, 1) = 5;
    original.at(1, 2) = 6;

    Matrix<int> moved(std::move(original));
    CHECK((moved.size() == std::pair<size_t, size_t>(2, 3)));
    CHECK(original.size() == std::pair<size_t, size_t>(0, 0));
}

