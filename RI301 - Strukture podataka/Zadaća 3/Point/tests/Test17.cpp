#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <iostream>
#include "doctest.h"
#include "../Point.hpp"

TEST_CASE("Test x()") {
  Point p(1.0, 2.0);

  CHECK(p.x() == 1.0);
}
