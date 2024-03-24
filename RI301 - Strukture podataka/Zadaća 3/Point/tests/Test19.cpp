#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <iostream>
#include "doctest.h"
#include "../Point.hpp"

TEST_CASE("Test setX()") {
  Point p(1.0, 2.0);

  p.setX(3.0);

  CHECK(p.x() == 3.0);
}
