#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../UnorderedMap.hpp"
#include "doctest.h"

TEST_CASE("prefix increment operator test") {
  // Create a new map and add some key-value pairs to it
  UnorderedMap<int, std::string> my_map;
  my_map.insert(1, "one");
  my_map.insert(2, "two");
  my_map.insert(3, "three");

  // Create an iterator for the first key-value pair in the map
  UnorderedMap<int, std::string>::Iterator it = my_map.begin();

  // Increment the iterator and check that it points to the next pair
  ++it;
  CHECK((*it).first == 2);
  CHECK((*it).second == "two");

  // Increment the iterator again and check that it points to the next pair
  ++it;
  CHECK((*it).first == 3);
  CHECK((*it).second == "three");
}
