#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../Matrix.hpp"

TEST_CASE(
    "Size method returns a pair containing the number of rows and "
    "columns in the matrix")
{
    Matrix<int> mat;
    CHECK(mat.size() == std::pair<size_t, size_t>(0, 0));
}

TEST_CASE("Default constructor creates an empty matrix")
{
    Matrix<int> mat;
    CHECK((mat.size().first == 0 && mat.size().second == 0));
}
