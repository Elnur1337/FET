#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "../Matrix.hpp"
TEST_CASE(
    "Accessing an element with at() returns the correct element and "
    "throws an exception for out-of-range indices")
{
    Matrix<int> mat(2, 3);
    mat.at(0, 0) = 1;
    mat.at(0, 1) = 2;
    mat.at(0, 2) = 3;
    mat.at(1, 0) = 4;
    mat.at(1, 1) = 5;
    mat.at(1, 2) = 6;
    CHECK(mat.at(0, 0) == 1);
    CHECK(mat.at(0, 1) == 2);
    CHECK(mat.at(0, 2) == 3);
    CHECK(mat.at(1, 0) == 4);
    CHECK(mat.at(1, 1) == 5);
    CHECK(mat.at(1, 2) == 6);

    CHECK_THROWS_AS(mat.at(2, 0), std::out_of_range);
    CHECK_THROWS_AS(mat.at(0, 3), std::out_of_range);
}

