#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <iostream>
#include "doctest.h"
#include "../Point.hpp"

TEST_CASE("Test setY()") {
  Point p(1.0, 2.0);

  p.setY(3.0);

  CHECK(p.y() == 3.0);
}

