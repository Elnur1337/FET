#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../SortedSingleLinkedList.hpp"

TEST_CASE("SortedSingleLinkedList erase") {
  SortedSingleLinkedList<int> list;

  // Insert elements into the list
  list.add(1).add(2).add(3);

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
