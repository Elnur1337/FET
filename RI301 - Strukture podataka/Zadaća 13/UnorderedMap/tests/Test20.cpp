#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../UnorderedMap.hpp"
#include "doctest.h"

TEST_CASE("move constructor test") {
  // Create a new map and add some key-value pairs to it
  UnorderedMap<int, std::string> my_map;
  my_map.insert(1, "one");
  my_map.insert(2, "two");
  my_map.insert(3, "three");

  // Create an iterator for the first key-value pair in the map
  auto it1 = my_map.begin();

  // Use the move constructor to create a new iterator that points to the same
  // pair
  UnorderedMap<int, std::string>::Iterator it2(std::move(it1));

  // Check that the original iterator is now invalid
  bool is_valid1 = (it1 == my_map.end());
  CHECK(is_valid1 == true);

  // Check that the new iterator points to the correct pair
  std::pair<int, std::string>& p = *it2;
  CHECK(p.first == 1);
  CHECK(p.second == "one");
}
