#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "../Matrix.hpp"

TEST_CASE(
    "Getting the secondary diagonal returns a vector with the secondary "
    "diagonal elements")
{
    Matrix<int> mat(3, 3);
    mat.at(0, 0) = 1;
    mat.at(0, 1) = 2;
    mat.at(0, 2) = 3;
    mat.at(1, 0) = 4;
    mat.at(1, 1) = 5;
    mat.at(1, 2) = 6;
    mat.at(2, 0) = 7;
    mat.at(2, 1) = 8;
    mat.at(2, 2) = 9;

    std::vector<int> diagonal = mat.secondaryDiagonal();
    CHECK(diagonal.size() == 3);
    CHECK(diagonal[0] == 3);
    CHECK(diagonal[1] == 5);
    CHECK(diagonal[2] == 7);
}

