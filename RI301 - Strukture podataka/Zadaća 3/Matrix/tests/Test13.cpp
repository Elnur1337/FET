#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "../Matrix.hpp"

TEST_CASE(
    "Addition operator throws an exception when matrices have different "
    "dimensions")
{
    Matrix<int> mat1(2, 3);
    Matrix<int> mat2(3, 2);
    CHECK_THROWS_AS(mat1 + mat2, std::invalid_argument);
}

