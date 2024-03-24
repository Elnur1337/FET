#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "../Matrix.hpp"

TEST_CASE("Addition operator adds two matrices element-wise")
{
    Matrix<int> mat1(2, 3);
    mat1.at(0, 0) = 1;
    mat1.at(0, 1) = 2;
    mat1.at(0, 2) = 3;
    mat1.at(1, 0) = 4;
    mat1.at(1, 1) = 5;
    mat1.at(1, 2) = 6;

    Matrix<int> mat2(2, 3);
    mat2.at(0, 0) = 7;
    mat2.at(0, 1) = 8;
    mat2.at(0, 2) = 9;
    mat2.at(1, 0) = 10;
    mat2.at(1, 1) = 11;
    mat2.at(1, 2) = 12;

    Matrix<int> sum = mat1 + mat2;
    CHECK(sum.size() == std::pair<size_t, size_t>(2, 3));
    CHECK(sum.at(0, 0) == 8);
    CHECK(sum.at(0, 1) == 10);
    CHECK(sum.at(0, 2) == 12);
    CHECK(sum.at(1, 0) == 14);
    CHECK(sum.at(1, 1) == 16);
    CHECK(sum.at(1, 2) == 18);
}

