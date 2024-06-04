#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../UnorderedMap.hpp"
#include "doctest.h"

TEST_CASE("empty test") {
  // Create a new empty map
  UnorderedMap<int, std::string> my_map;

  // Check that the map is empty
  CHECK(my_map.empty() == true);

  // Add a key-value pair to the map
  my_map.insert(1, "one");

  // Check that the map is no longer empty
  CHECK(my_map.empty() == false);
}
