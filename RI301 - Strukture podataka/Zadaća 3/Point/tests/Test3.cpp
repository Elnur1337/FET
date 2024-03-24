#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <iostream>

#include "doctest.h"
#include "../Point.hpp"

TEST_CASE("Test copy constructor for Point") {
  Point p1(3.0, 4.0);
  Point p2(p1);

  CHECK(p2.x() == 3.0);
  CHECK(p2.y() == 4.0);
}


