#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../UnorderedMap.hpp"
#include "doctest.h"

TEST_CASE("contains test") {
  // Create a new map and add some key-value pairs to it
  UnorderedMap<std::string, int> my_map;
  my_map.insert("one", 1);
  my_map.insert("two", 2);
  my_map.insert("three", 3);

  // Check if an existing key is present in the map
  bool contains1 = my_map.contains("two");
  CHECK(contains1 == true);

  // Check if a non-existent key is present in the map
  bool contains2 = my_map.contains("four");
  CHECK(contains2 == false);
}
