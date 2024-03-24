#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <iostream>

#include "doctest.h"
#include "../Point.hpp"

TEST_CASE("Testing the Point move constructor") {
  Point p1(1.0, 2.0);
  Point p2(std::move(p1));
  // Reset state of the moved object
  CHECK(p1.x() == 0.0);
  CHECK(p1.y() == 0.0);

  CHECK(p2.x() == 1.0);
  CHECK(p2.y() == 2.0);

  Point p3;
  Point p4(std::move(p3));

  CHECK(p4.x() == 0.0);
  CHECK(p4.y() == 0.0);
  // Reset state of the moved object
  CHECK(p3.x() == 0.0);
  CHECK(p3.y() == 0.0);
}


