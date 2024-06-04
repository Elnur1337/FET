#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../UnorderedMap.hpp"
#include "doctest.h"

TEST_CASE("begin iterator test") {
  // Create a new map and add some key-value pairs to it
  UnorderedMap<int, std::string> my_map;
  my_map.insert(1, "one");
  my_map.insert(2, "two");
  my_map.insert(3, "three");

  // Get the begin iterator for the map
  UnorderedMap<int, std::string>::Iterator it = my_map.begin();

  // Check that the iterator points to the correct pair
  std::pair<int, std::string>& p = *it;
  CHECK(p.first == 1);
  CHECK(p.second == "one");
}
