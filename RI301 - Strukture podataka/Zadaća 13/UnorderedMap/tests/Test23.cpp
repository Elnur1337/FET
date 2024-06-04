#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../UnorderedMap.hpp"
#include "doctest.h"

TEST_CASE("end iterator test") {
  // Create a new map and add some key-value pairs to it
  UnorderedMap<int, std::string> my_map;
  my_map.insert(1, "one");
  my_map.insert(2, "two");
  my_map.insert(3, "three");

  // Get the end iterator for the map
  UnorderedMap<int, std::string>::Iterator it = my_map.end();

  // Check that the iterator points to the correct position
  bool is_valid = (it == my_map.end());
  CHECK(is_valid == true);
}
