#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../UnorderedMap.hpp"
#include "doctest.h"

TEST_CASE("erase_if iterator test") {
  // Create a new map and add some key-value pairs to it
  UnorderedMap<int, std::string> my_map;
  my_map.insert(1, "one");
  my_map.insert(2, "two");
  my_map.insert(3, "three");

  // Erase all key-value pairs where the key is even
  my_map.erase_if(
      [](const std::pair<int, std::string>& p) { return p.first % 2 != 0; });

  // Check that the map only contains the odd key-value pair
  CHECK(my_map.size() == 1);
  UnorderedMap<int, std::string>::Iterator it = my_map.find(1);
  CHECK(it == my_map.end());
}
