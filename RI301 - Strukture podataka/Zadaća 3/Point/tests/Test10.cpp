#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "../Point.hpp"
#include "doctest.h"
#include <iostream>

TEST_CASE("Test operator/") {
  Point p1(1.0, 2.0);

  // Test case with non-zero scalar
  Point p2 = p1 / 2.0;
  CHECK(p2.x() == 0.5);
  CHECK(p2.y() == 1.0);

  // Test case with zero scalar
  double scalar = 0.0;
  CHECK_THROWS_AS(p1 / scalar, std::invalid_argument);
}
