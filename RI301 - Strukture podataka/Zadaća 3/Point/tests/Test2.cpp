#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <iostream>

#include "doctest.h"
#include "../Point.hpp"

TEST_CASE("Test constructor Point(double x, double y)") {
  Point p1(2.0, 3.0);
  CHECK(p1.x() == 2.0);
  CHECK(p1.y() == 3.0);

  Point p2(-1.5, 4.0);
  CHECK(p2.x() == -1.5);
  CHECK(p2.y() == 4.0);

  Point p3(0.0, 0.0);
  CHECK(p3.x() == 0.0);
  CHECK(p3.y() == 0.0);
}

