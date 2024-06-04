#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../UnorderedMap.hpp"
#include "doctest.h"

TEST_CASE("Test UnorderedMap constructor with initializer list") {
  UnorderedMap<int, std::string> map = {{1, "one"}, {2, "two"}, {3, "three"}};

  CHECK(map.size() == 3);
  CHECK(map[1] == "one");
  CHECK(map[2] == "two");
  CHECK(map[3] == "three");
}
