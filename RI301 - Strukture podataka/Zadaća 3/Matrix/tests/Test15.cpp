#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "../Matrix.hpp"

TEST_CASE(
    "Multiplication operator throws an exception when matrices have "
    "incompatible dimensions")
{
    Matrix<int> mat1(2, 3);
    Matrix<int> mat2(4, 2);
    CHECK_THROWS_AS(mat1 * mat2, std::invalid_argument);
}

