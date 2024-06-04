#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../UnorderedMap.hpp"
#include "doctest.h"

TEST_CASE("insert iterator test") {
  // Create a new map and insert a key-value pair
  UnorderedMap<int, std::string> my_map;
  my_map.insert(1, "one");

  // Create a new pair to insert
  std::pair<int, std::string> new_pair(2, "two");

  // Insert the new pair into the map and get the iterator to the inserted pair
  UnorderedMap<int, std::string>::Iterator it =
      my_map.insert(new_pair.first, new_pair.second);

  // Check that the iterator points to the correct pair
  std::pair<int, std::string>& p = *it;
  CHECK(p.first == 2);
  CHECK(p.second == "two");
}
