#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <iostream>

#include "doctest.h"
#include "../Point.hpp"

TEST_CASE("Test distance()") {
  Point p1(1.0, 1.0);
  Point p2(4.0, 5.0);

  double dist = p1.distance(p2);

  CHECK(dist == doctest::Approx(5.0));
}
