#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../UnorderedMap.hpp"
#include "doctest.h"

TEST_CASE("insert range iterator test") {
  // Create a new map and insert a key-value pair
  UnorderedMap<int, std::string> my_map;
  my_map.insert(1, "one");

  // Create a new pair to insert
  std::pair<int, std::string> new_pair(2, "two");

  // Create an initializer list of pairs to insert
  std::initializer_list<std::pair<int, std::string>> init_list = {{3, "three"},
                                                                  {4, "four"}};

  // Insert the new pairs into the map and get the iterator to the last inserted
  // pair
  UnorderedMap<int, std::string>::Iterator it = my_map.insert_range(init_list);

  // Check that the iterator points to the last inserted pair
  std::pair<int, std::string>& p = *it;
  CHECK(p.first == 3);
  CHECK(p.second == "three");
}
