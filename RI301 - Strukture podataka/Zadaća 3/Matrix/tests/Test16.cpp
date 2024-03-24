#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "../Matrix.hpp"

TEST_CASE("Multiplication by scalar multiplies all elements by the scalar")
{
    Matrix<int> mat(2, 3);
    mat.at(0, 0) = 1;
    mat.at(0, 1) = 2;
    mat.at(0, 2) = 3;
    mat.at(1, 0) = 4;
    mat.at(1, 1) = 5;
    mat.at(1, 2) = 6;

    Matrix<int> result = mat * 2;
    CHECK(result.size() == std::pair<size_t, size_t>(2, 3));
    CHECK(result.at(0, 0) == 2);
    CHECK(result.at(0, 1) == 4);
    CHECK(result.at(0, 2) == 6);
    CHECK(result.at(1, 0) == 8);
    CHECK(result.at(1, 1) == 10);
    CHECK(result.at(1, 2) == 12);
}

