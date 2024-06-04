#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../UnorderedMap.hpp"
#include "doctest.h"

TEST_CASE("operator[] test") {
  UnorderedMap<std::string, int> my_map;

  // Add a new key-value pair to the map using the subscript operator
  my_map["one"] = 1;
  // Check that the size of the map is 1
  CHECK(my_map.size() == 1);

  // Add another key-value pair to the map
  my_map["two"] = 2;
  // Check that the size of the map is 2
  CHECK(my_map.size() == 2);

  // Update the value associated with the "one" key
  my_map["one"] = 3;
  // Check that the size of the map is still 2
  CHECK(my_map.size() == 2);

  // Access the value associated with the "one" key using the subscript operator
  int value = my_map["one"];
  // Check that the value is correct
  CHECK(value == 3);

  // Access a non-existent key using the subscript operator
  // This should create a new key-value pair with the default value of 0
  value = my_map["three"];
  // Check that the size of the map is now 3
  CHECK(my_map.size() == 3);
  // Check that the value is correct
  CHECK(value == 0);
}
