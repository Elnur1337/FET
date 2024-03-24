#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "../Matrix.hpp"

TEST_CASE("push_back method with std::vector and invalid size")
{
    Matrix<int> mat;
    mat.push_back(std::vector<int>{2, 2, 2});
    mat.push_back(std::vector<int>{2, 2, 2});
    CHECK_THROWS_AS(mat.push_back({1, 2, 3, 4}), std::invalid_argument);
    CHECK_THROWS_AS(mat.push_back(std::vector<int>{1, 2, 3, 4}), std::invalid_argument);
}
