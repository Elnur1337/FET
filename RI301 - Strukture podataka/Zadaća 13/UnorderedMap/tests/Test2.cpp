
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../UnorderedMap.hpp"
#include "doctest.h"

TEST_CASE("Copy constructor creates a new map with the same elements") {
  UnorderedMap<int, int> m1{{1, 2}, {3, 4}, {5, 6}};
  UnorderedMap<int, int> m2{m1};
  REQUIRE(m1.size() == m2.size());
  REQUIRE(m1.capacity() == m2.capacity());
  REQUIRE(m1.empty() == m2.empty());

  // Check that all elements in m1 are in m2
  for (const auto& [key, value] : m1) {
    REQUIRE(m2.contains(key));
    REQUIRE(m2.at(key) == value);
  }

  // Check that all elements in m2 are in m1
  for (const auto& [key, value] : m2) {
    REQUIRE(m1.contains(key));
    REQUIRE(m1.at(key) == value);
  }
}
