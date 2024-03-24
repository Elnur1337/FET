#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "../Matrix.hpp"

TEST_CASE(
    "Copy assignment operator copies the values of another matrix to "
    "this matrix")
{
    Matrix<int> original(2, 3);
    original.at(0, 0) = 1;
    original.at(0, 1) = 2;
    original.at(0, 2) = 3;
    original.at(1, 0) = 4;
    original.at(1, 1) = 5;
    original.at(1, 2) = 6;

    Matrix<int> copy;
    copy = original;
    CHECK(copy == original);
}

