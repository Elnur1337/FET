#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "../UnorderedMap.hpp"
#include "doctest.h"

TEST_CASE("UnorderedMap()") {
  SUBCASE("New map is empty") {
    UnorderedMap<int, int> map;
    CHECK(map.empty());
    CHECK_EQ(map.size(), 0);
    CHECK_EQ(map.capacity(), 10);
  }

  SUBCASE("Inserting an element increases the size") {
    UnorderedMap<int, std::string> map;
    map.insert(1, "one");
    CHECK_FALSE(map.empty());
    CHECK_EQ(map.size(), 1);
    CHECK_EQ(map[1], "one");
  }

  SUBCASE("Inserting multiple elements increases the size accordingly") {
    UnorderedMap<std::string, int> map;
    map.insert_range({{"one", 1}, {"two", 2}, {"three", 3}});
    CHECK_EQ(map.size(), 3);
    CHECK_EQ(map["one"], 1);
    CHECK_EQ(map["two"], 2);
    CHECK_EQ(map["three"], 3);
  }
}
