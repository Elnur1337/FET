#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../UnorderedMap.hpp"
#include "doctest.h"

TEST_CASE("find iterator test") {
  // Create a new map and add some key-value pairs to it
  UnorderedMap<int, std::string> my_map;
  my_map.insert(1, "one");
  my_map.insert(2, "two");
  my_map.insert(3, "three");

  // Find one of the key-value pairs in the map
  UnorderedMap<int, std::string>::Iterator it = my_map.find(2);

  // Check that the iterator points to the correct pair
  std::pair<int, std::string>& p = *it;
  CHECK(p.first == 2);
  CHECK(p.second == "two");

  // Find a key that is not in the map
  it = my_map.find(4);

  // Check that the iterator is equal to the end iterator
  CHECK(it == my_map.end());
}
