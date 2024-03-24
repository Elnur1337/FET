#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "../Matrix.hpp"

TEST_CASE(
    "Size method returns a pair containing the number of rows and "
    "columns in the matrix")
{
    Matrix<int> mat(2, 3);
    CHECK(mat.size() == std::pair<size_t, size_t>(2, 3));
}
