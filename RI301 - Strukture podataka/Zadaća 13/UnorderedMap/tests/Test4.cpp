#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../UnorderedMap.hpp"
#include "doctest.h"

TEST_CASE("Move constructor") {
  UnorderedMap<int, std::string> m1{{1, "one"}, {2, "two"}, {3, "three"}};
  size_t size1 = m1.size();
  size_t capacity1 = m1.capacity();
  double load_factor1 = m1.load_factor();
  UnorderedMap<int, std::string> m2{std::move(m1)};
  REQUIRE(m1.size() == 0);
  REQUIRE(m1.capacity() == 0);
  REQUIRE(m1.load_factor() == load_factor1);
  REQUIRE(m2.size() == size1);
  REQUIRE(m2.capacity() == capacity1);
  REQUIRE(m2.load_factor() == load_factor1);
  REQUIRE(m2[1] == "one");
  REQUIRE(m2[2] == "two");
  REQUIRE(m2[3] == "three");
}
