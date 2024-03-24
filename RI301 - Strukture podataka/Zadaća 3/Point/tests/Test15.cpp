#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <iostream>
#include "doctest.h"
#include "../Point.hpp"

TEST_CASE("Test operator==") {
  Point p1(1.0, 2.0);
  Point p2(1.0, 2.0);
  Point p3(2.0, 3.0);

  CHECK(p1 == p2);
  CHECK_FALSE(p1 == p3);
}

