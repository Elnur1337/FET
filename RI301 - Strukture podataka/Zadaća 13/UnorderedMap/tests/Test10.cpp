#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../UnorderedMap.hpp"
#include "doctest.h"

TEST_CASE("at test") {
  // Create a new map and add some key-value pairs to it
  UnorderedMap<std::string, int> my_map;
  my_map.insert("one", 1);
  my_map.insert("two", 2);
  my_map.insert("three", 3);

  // Access a value using the at() method
  int value = my_map.at("one");

  // Check that the value is correct
  CHECK(value == 1);

  // Try to access a non-existent key using the at() method
  // This should throw an exception because the key does not exist
  CHECK_THROWS_AS(my_map.at("four"), std::out_of_range);
}
