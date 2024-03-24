#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "../Matrix.hpp"

TEST_CASE("Multiplication operator multiplies two matrices")
{
    Matrix<int> mat1(2, 3);
    mat1.at(0, 0) = 1;
    mat1.at(0, 1) = 2;
    mat1.at(0, 2) = 3;
    mat1.at(1, 0) = 4;
    mat1.at(1, 1) = 5;
    mat1.at(1, 2) = 6;

    Matrix<int> mat2(3, 2);
    mat2.at(0, 0) = 7;
    mat2.at(0, 1) = 8;
    mat2.at(1, 0) = 9;
    mat2.at(1, 1) = 10;
    mat2.at(2, 0) = 11;
    mat2.at(2, 1) = 12;

    Matrix<int> product = mat1 * mat2;
    CHECK(product.size() == std::pair<size_t, size_t>(2, 2));
    CHECK(product.at(0, 0) == 58);
    CHECK(product.at(0, 1) == 64);
    CHECK(product.at(1, 0) == 139);
    CHECK(product.at(1, 1) == 154);
}

