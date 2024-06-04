#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../UnorderedMap.hpp"
#include "doctest.h"

TEST_CASE("equality operator test") {
  // Create a new map and add some key-value pairs to it
  UnorderedMap<int, std::string> my_map;
  my_map.insert(1, "one");
  my_map.insert(2, "two");
  my_map.insert(3, "three");

  // Create two iterators for the first key-value pair in the map
  UnorderedMap<int, std::string>::Iterator it1 = my_map.begin();
  UnorderedMap<int, std::string>::Iterator it2 = my_map.begin();

  // Check that the two iterators are equal using the operator==() method
  bool are_equal1 = (it1 == it2);
  CHECK(are_equal1 == true);

  // Check that the two iterators are not equal using the operator!=() method
  bool are_not_equal1 = (it1 != it2);
  CHECK(are_not_equal1 == false);

  // Increment one of the iterators and check that they are not equal anymore
  ++it1;
  bool are_equal2 = (it1 == it2);
  CHECK(are_equal2 == false);

  bool are_not_equal2 = (it1 != it2);
  CHECK(are_not_equal2 == true);
}
