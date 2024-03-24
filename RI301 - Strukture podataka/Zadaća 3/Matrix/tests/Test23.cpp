#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "../Matrix.hpp"

TEST_CASE("expand method with element")
{
    Matrix<int> mat;
    mat.push_back(std::vector<int>{1, 2, 3});
    mat.push_back(std::vector<int>{4, 5, 6});
    mat.push_back(std::vector<int>{7, 8, 9});
    mat.expand({10, 10, 10});
    CHECK(mat[0] == std::vector<int>{1, 2, 3, 10});
    CHECK(mat[1] == std::vector<int>{4, 5, 6, 10});
    CHECK(mat[2] == std::vector<int>{7, 8, 9, 10});
}
