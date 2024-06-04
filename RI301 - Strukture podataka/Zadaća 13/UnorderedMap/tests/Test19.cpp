#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../UnorderedMap.hpp"
#include "doctest.h"

TEST_CASE("copy constructor test") {
  // Create a new map and add some key-value pairs to it
  UnorderedMap<int, std::string> my_map;
  my_map.insert(1, "one");
  my_map.insert(2, "two");
  my_map.insert(3, "three");

  // Create an iterator for the first key-value pair in the map
  auto it1 = my_map.begin();

  // Use the copy constructor to create a new iterator that points to the same
  // pair
  UnorderedMap<int, std::string>::Iterator it2(it1);

  // Check that the two iterators point to the same pair
  CHECK(it1 == it2);
}
