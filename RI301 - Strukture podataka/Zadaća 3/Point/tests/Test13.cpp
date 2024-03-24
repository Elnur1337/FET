#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <iostream>
#include "doctest.h"
#include "../Point.hpp"

TEST_CASE("Test operator*=") {
  Point p1(1.0, 2.0);

  p1 *= 2.0;

  CHECK(p1.x() == 2.0);
  CHECK(p1.y() == 4.0);
}
