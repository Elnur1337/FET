#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../UnorderedMap.hpp"
#include "doctest.h"

TEST_CASE("arrow operator test") {
  // Create a new map and add some key-value pairs to it
  UnorderedMap<int, std::string> my_map;
  my_map.insert(1, "one");
  my_map.insert(2, "two");
  my_map.insert(3, "three");

  // Create an iterator for the first key-value pair in the map
  auto it = my_map.begin();

  // Use the arrow operator to access the members of the current pair
  std::pair<int, std::string>* p = it.operator->();
  CHECK(p->first == 1);
  CHECK(p->second == "one");
}
