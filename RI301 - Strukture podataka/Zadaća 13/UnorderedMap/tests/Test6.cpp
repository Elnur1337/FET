#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../UnorderedMap.hpp"
#include "doctest.h"
TEST_CASE("destructor test") {
  // Create a new map
  UnorderedMap<int, std::string> my_map;

  // Add some key-value pairs to the map
  my_map.insert(1, "one");
  my_map.insert(2, "two");
  my_map.insert(3, "three");

  // Check that the size of the map is 3
  CHECK(my_map.size() == 3);

  my_map.~UnorderedMap();
  CHECK(my_map.size() == 0);

  // Delete the map
}
