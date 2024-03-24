#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "../Matrix.hpp"

TEST_CASE(
    "Equality operator returns true when two matrices have the same "
    "dimensions and elements, and false otherwise")
{
    Matrix<int> mat1(2, 3);
    mat1.at(0, 0) = 1;
    mat1.at(0, 1) = 2;
    mat1.at(0, 2) = 3;
    mat1.at(1, 0) = 4;
    mat1.at(1, 1) = 5;
    mat1.at(1, 2) = 6;

    Matrix<int> mat2(2, 3);
    mat2.at(0, 0) = 1;
    mat2.at(0, 1) = 2;
    mat2.at(0, 2) = 3;
    mat2.at(1, 0) = 4;
    mat2.at(1, 1) = 5;
    mat2.at(1, 2) = 6;

    Matrix<int> mat3(3, 2);
    mat3.at(0, 0) = 1;
    mat3.at(0, 1) = 2;
    mat3.at(1, 0) = 4;
    mat3.at(1, 1) = 5;
    mat3.at(2, 0) = 7;
    mat3.at(2, 1) = 8;

    CHECK(mat1 == mat2);
    CHECK(mat1 != mat3);
}

