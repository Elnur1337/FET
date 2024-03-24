#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "../Matrix.hpp"

TEST_CASE(
    "Getting the main diagonal returns a vector with the main diagonal "
    "elements")
{
    Matrix<int> mat(3, 4);
    mat.at(0, 0) = 1;
    mat.at(0, 1) = 2;
    mat.at(0, 2) = 3;
    mat.at(0, 3) = 4;
    mat.at(1, 0) = 5;
    mat.at(1, 1) = 6;
    mat.at(1, 2) = 7;
    mat.at(1, 3) = 8;
    mat.at(2, 0) = 9;
    mat.at(2, 1) = 10;
    mat.at(2, 2) = 11;
    mat.at(2, 3) = 12;

    std::vector<int> diagonal = mat.mainDiagonal();
    CHECK(diagonal.size() == 3);
    CHECK(diagonal[0] == 1);
    CHECK(diagonal[1] == 6);
    CHECK(diagonal[2] == 11);
}

