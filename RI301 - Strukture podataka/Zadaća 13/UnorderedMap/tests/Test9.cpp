#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../UnorderedMap.hpp"
#include "doctest.h"

TEST_CASE("clear test") {
  // Create a new map and add some key-value pairs to it
  UnorderedMap<int, std::string> my_map;
  my_map.insert(1, "one");
  my_map.insert(2, "two");
  my_map.insert(3, "three");

  // Check that the size of the map is correct
  CHECK(my_map.size() == 3);

  // Clear the map and check that its size is now 0
  my_map.clear();
  CHECK(my_map.size() == 0);

  // Try to access a key-value pair in the cleared map
  // This should throw an exception because the map is empty
  CHECK_THROWS_AS(my_map.at(1), std::out_of_range);
}
