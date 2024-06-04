#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../UnorderedMap.hpp"
#include "doctest.h"

TEST_CASE("equality test") {
  // Create two identical maps
  UnorderedMap<std::string, int> my_map1;
  my_map1.insert("one", 1);
  my_map1.insert("two", 2);
  my_map1.insert("three", 3);

  UnorderedMap<std::string, int> my_map2;
  my_map2.insert("one", 1);
  my_map2.insert("two", 2);
  my_map2.insert("three", 3);

  // Check that the maps are equal using the operator==() method
  bool are_equal1 = (my_map1 == my_map2);
  CHECK(are_equal1 == true);

  // Check that the maps are not equal using the operator!=() method
  bool are_not_equal1 = (my_map1 != my_map2);
  CHECK(are_not_equal1 == false);

  // Add a new key-value pair to one of the maps
  my_map1.insert("four", 4);

  // Check that the maps are not equal anymore using the operator==() method
  bool are_equal2 = (my_map1 == my_map2);
  CHECK(are_equal2 == false);

  // Check that the maps are equal using the operator!=() method
  bool are_not_equal2 = (my_map1 != my_map2);
  CHECK(are_not_equal2 == true);
}
