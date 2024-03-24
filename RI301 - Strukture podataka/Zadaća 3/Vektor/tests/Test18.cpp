#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "../MojVektor.hpp"

TEST_CASE("Compare two vectors for equality") {
  SUBCASE("Compare non-empty vectors with equal contents") {
    MojVektor v1{1, 2, 3};
    MojVektor v2{1, 2, 3};
    CHECK(v1 == v2);
  }

  SUBCASE("Compare non-empty vectors with different contents") {
    MojVektor v1{1, 2, 3};
    MojVektor v2{1, 2, 4};
    CHECK_FALSE(v1 == v2);
  }

  SUBCASE("Compare non-empty vector with empty vector") {
    MojVektor v1{1, 2, 3};
    MojVektor v2;
    CHECK_FALSE(v1 == v2);
  }

  SUBCASE("Compare empty vectors") {
    MojVektor v1;
    MojVektor v2;
    CHECK(v1 == v2);
  }
}
