#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "../Matrix.hpp"

TEST_CASE(
    "Copy constructor creates a new matrix with the same dimensions and "
    "elements as the original")
{
    Matrix<int> original(2, 3);
    original.at(0, 0) = 1;
    original.at(0, 1) = 2;
    original.at(0, 2) = 3;
    original.at(1, 0) = 4;
    original.at(1, 1) = 5;
    original.at(1, 2) = 6;

    Matrix<int> copy(original);
    CHECK(copy == original);
}

