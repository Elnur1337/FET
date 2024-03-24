#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <iostream>
#include "doctest.h"
#include "../Point.hpp"

TEST_CASE("Test operator<<") {
  Point p(1.0, 2.0);

  std::ostringstream oss;
  oss << p;

  CHECK(oss.str() == "Point(x=1, y=2)\n");
}

