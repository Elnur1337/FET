#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "../MojVektor.hpp"

TEST_CASE("MojVektor Iterator operators test") {
  MojVektor<int> v{1, 2, 3, 4, 5};
  MojVektor<int>::Iterator it = v.begin() + 2;

  SUBCASE("operator-") {
    CHECK((it - (v.begin() + 1)) == 1);
    CHECK((it - v.begin()) == 2);
    CHECK(((v.end() - 1) - it) == 2);
  }

  SUBCASE("operator<") {
    CHECK((it < v.end()));
    CHECK((v.begin() < it));
    CHECK(!(it < it));
  }

  SUBCASE("operator>") {
    CHECK((v.end() > it));
    CHECK((it > v.begin()));
    CHECK(!(it > it));
  }

  SUBCASE("operator<=") {
    CHECK((it <= v.end()));
    CHECK((v.begin() <= it));
    CHECK((it <= it));
  }

  SUBCASE("operator>=") {
    CHECK((v.end() >= it));
    CHECK((it >= v.begin()));
    CHECK((it >= it));
  }
}
