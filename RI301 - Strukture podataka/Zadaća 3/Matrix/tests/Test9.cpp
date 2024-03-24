#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "../Matrix.hpp"

TEST_CASE("Accessing a row with operator[] returns a reference to the correct row")
{
    Matrix<int> mat(2, 3);
    mat.at(0, 0) = 1;
    mat.at(0, 1) = 2;
    mat.at(0, 2) = 3;
    mat.at(1, 0) = 4;
    mat.at(1, 1) = 5;
    mat.at(1, 2) = 6;

    CHECK(mat[0][0] == 1);
    CHECK(mat[0][1] == 2);
    CHECK(mat[0][2] == 3);
    CHECK(mat[1][0] == 4);
    CHECK(mat[1][1] == 5);
    CHECK(mat[1][2] == 6);
}

