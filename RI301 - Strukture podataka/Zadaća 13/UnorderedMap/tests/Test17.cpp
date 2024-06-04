#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../UnorderedMap.hpp"
#include "doctest.h"

TEST_CASE("dereference operator test") {
  // Create a new map and add some key-value pairs to it
  UnorderedMap<std::string, int> my_map;
  my_map.insert("one", 1);
  my_map.insert("two", 2);
  my_map.insert("three", 3);

  // Create an iterator for the first key-value pair in the map
  auto it = my_map.begin();

  // Dereference the iterator and check that the key and value are correct
  std::pair<std::string, int>& p = *it;
  CHECK(p.first == "one");
  CHECK(p.second == 1);
}
