#include <iostream>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../UnorderedMap.hpp"
#include "doctest.h"

TEST_CASE("size and capacity test") {
  // Create a new empty map
  UnorderedMap<std::string, int> my_map;

  // Check that the size and capacity of the map are both 0
  CHECK(my_map.size() == 0);
  CHECK(my_map.capacity() > 0); // Max size should be greater than 0

  // Add some key-value pairs to the map
  my_map.insert("one", 1);
  my_map.insert("two", 2);
  my_map.insert("three", 3);

  // Check that the size and capacity of the map are correct
  CHECK(my_map.size() == 3);
  CHECK(my_map.capacity() > 0);

  // Clear the map and check that its size is now 0
  my_map.clear();
  CHECK(my_map.size() == 0);
}
