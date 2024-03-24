#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <iostream>
#include "doctest.h"
#include "../Point.hpp"

TEST_CASE("Test move operator=") {
  Point p1(1.0, 2.0);
  Point p2(3.0, 4.0);

  p1 = std::move(p2);

  CHECK(p1.x() == 3.0);
  CHECK(p1.y() == 4.0);
  // Move operator resets state of the object
  CHECK(p2.x() == 0.0);
  CHECK(p2.y() == 0.0);
}
