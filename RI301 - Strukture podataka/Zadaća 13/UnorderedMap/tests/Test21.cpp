#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../UnorderedMap.hpp"
#include "doctest.h"

TEST_CASE("move assignment operator test") {
  // Create two maps and add some key-value pairs to them
  UnorderedMap<int, std::string> my_map1;
  my_map1.insert(1, "one");
  my_map1.insert(2, "two");
  my_map1.insert(3, "three");

  UnorderedMap<int, std::string> my_map2;
  my_map2.insert(4, "four");
  my_map2.insert(5, "five");

  // Create an iterator for the first key-value pair in the first map
  auto it1 = my_map1.begin();

  // Create an iterator for the first key-value pair in the second map
  auto it2 = my_map2.begin();

  // Use the move assignment operator to assign the second iterator to the first
  it1 = std::move(it2);

  // Check that the original iterator is now invalid
  bool is_valid2 = (it2 == my_map2.end());
  CHECK(is_valid2 == true);

  // Check that the new iterator points to the correct pair
  std::pair<int, std::string>& p = *it1;
  CHECK(p.first == 4);
  CHECK(p.second == "four");
}
