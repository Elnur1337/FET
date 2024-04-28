#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../SingleLinkedList.hpp"

TEST_CASE("SingleLinkedList erase") {
  SingleLinkedList<int> list;

  // Insert elements into the list
  list.push_back(1).push_back(2).push_back(3);

  // Test erasing first element
  auto it = list.erase(list.begin());
  REQUIRE(list.size() == 2);
  REQUIRE(*it == 2);
  REQUIRE(*list.begin() == 2);

  // Test erasing middle element
  it = list.erase(list.begin());
  REQUIRE(list.size() == 1);
  REQUIRE(*list.begin() == 3);
  REQUIRE(it == list.begin());
}
