#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <iostream>
#include "doctest.h"
#include "../Point.hpp"

TEST_CASE("Test operator/=") {
  Point p1(1.0, 2.0);

  // Test case with non-zero scalar
  p1 /= 2.0;
  CHECK(p1.x() == 0.5);
  CHECK(p1.y() == 1.0);

  // Test case with zero scalar
  double scalar = 0.0;
  CHECK_THROWS_AS(p1 /= scalar, std::invalid_argument);
}
