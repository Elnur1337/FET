#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "../MojVektor.hpp"

TEST_CASE("Resize vector") {
  MojVektor v{1, 2, 3};

  SUBCASE("Resizing to a smaller size") {
    v.resize(2);
    CHECK(v.size() == 2);
    CHECK(v.capacity() >= 3);  // Capacity should remain the same
    CHECK(v[0] == 1);
    CHECK(v[1] == 2);
  }

  SUBCASE("Resizing to a larger size") {
    v.resize(5);
    CHECK(v.size() == 5);
    CHECK(v.capacity() >= 5);  // Capacity should be increased if necessary
    CHECK(v[0] == 1);
    CHECK(v[1] == 2);
    CHECK(v[2] == 3);
    CHECK(v[3] == 0);  // Default-initialized values should be set to zero
    CHECK(v[4] == 0);
  }

  SUBCASE("Resizing to the same size") {
    v.resize(3);
    CHECK(v.size() == 3);
    CHECK(v.capacity() >= 3);  // Capacity should remain the same
    CHECK(v[0] == 1);
    CHECK(v[1] == 2);
    CHECK(v[2] == 3);
  }
}

