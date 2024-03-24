#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "../Matrix.hpp"

TEST_CASE("expand method with std::vector")
{
    Matrix<int> mat;
    mat.push_back(std::vector<int>{1, 2, 3});
    mat.push_back(std::vector<int>{4, 5, 6});
    mat.push_back(std::vector<int>{7, 8, 9});
    mat.expand({std::vector<int>{10, 11, 12}});
    CHECK(mat[0] == std::vector<int>{1, 2, 3, 10});
    CHECK(mat[1] == std::vector<int>{4, 5, 6, 11});
    CHECK(mat[2] == std::vector<int>{7, 8, 9, 12});
}

TEST_CASE("expand method with std::vector and invalid_size")
{
    Matrix<int> mat;
    mat.push_back(std::vector<int>{1, 2, 3});
    mat.push_back(std::vector<int>{4, 5, 6});
    mat.push_back(std::vector<int>{7, 8, 9});
    CHECK_THROWS_AS(mat.expand({std::vector<int>{10, 11, 12, 13}}), std::invalid_argument);
}
