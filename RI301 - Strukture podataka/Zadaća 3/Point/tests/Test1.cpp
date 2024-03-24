#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <iostream>
#include "doctest.h"
#include "../Point.hpp"

TEST_CASE("Testing the default constructor of Point") {
  Point p;
  CHECK(p.x() == 0.0);
  CHECK(p.y() == 0.0);
}
