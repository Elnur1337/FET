#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <iostream>
#include "doctest.h"
#include "../Point.hpp"

TEST_CASE("Test operator-") {
  Point p1(1.0, 2.0);
  Point p2(3.0, 4.0);

  Point p3 = p2 - p1;

  CHECK(p3.x() == 2.0);
  CHECK(p3.y() == 2.0);
}
