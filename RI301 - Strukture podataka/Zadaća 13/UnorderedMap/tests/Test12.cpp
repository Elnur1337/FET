#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../UnorderedMap.hpp"
#include "doctest.h"

TEST_CASE("load factor test") {
  // Create a new map with a capacity of 5
  UnorderedMap<int, std::string> my_map;
  my_map.insert(1, "one");
  my_map.insert(2, "two");
  my_map.insert(3, "three");

  // Check the load factor of the map
  double load_factor1 = my_map.load_factor();
  CHECK(load_factor1 == doctest::Approx(90).epsilon(0.01));

  // Add more key-value pairs to the map
  my_map.insert(4, "four");
  my_map.insert(5, "five");

  // Check the load factor of the map again
  double load_factor2 = my_map.load_factor();
  CHECK(load_factor2 == doctest::Approx(90).epsilon(0.01));
}
