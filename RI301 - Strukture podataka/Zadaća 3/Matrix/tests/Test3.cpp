#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "../Matrix.hpp"

TEST_CASE("Constructor creates a matrix with the specified dimensions")
{
    size_t rows = 3;
    size_t cols = 2;
    Matrix<int> mat(rows, cols);
    CHECK(mat.size() == std::pair<size_t, size_t>(rows, cols));
    CHECK(mat[0].size() == cols);
    CHECK(mat[1].size() == cols);
    CHECK(mat[2].size() == cols);
}

