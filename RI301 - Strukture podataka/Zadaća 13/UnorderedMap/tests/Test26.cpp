#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../UnorderedMap.hpp"
#include "doctest.h"

TEST_CASE("erase iterator test") {
  // Create a new map and add some key-value pairs to it
  UnorderedMap<int, std::string> my_map;
  my_map.insert(1, "one");
  my_map.insert(2, "two");
  my_map.insert(3, "three");

  // Erase one of the key-value pairs from the map
  UnorderedMap<int, std::string>::Iterator it = my_map.erase(2);

  // Check that the iterator points to the correct pair
  std::pair<int, std::string>& p = *it;
  CHECK(p.first == 3);
  CHECK(p.second == "three");
}
