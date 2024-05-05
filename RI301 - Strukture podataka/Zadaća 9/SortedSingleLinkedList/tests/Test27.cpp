#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../SortedSingleLinkedList.hpp"

TEST_CASE(
    "operator++(int) increments pointer correctly and returns old value") {
  SortedSingleLinkedList<int> list;
  list.add(1).add(2).add(3);
  SortedSingleLinkedList<int>::Iterator it = list.begin();
  auto old_it = it++;
  REQUIRE(*old_it == 1);
  REQUIRE(*it == 2);
  old_it = it++;
  REQUIRE(*old_it == 2);
  REQUIRE(*it == 3);
}
