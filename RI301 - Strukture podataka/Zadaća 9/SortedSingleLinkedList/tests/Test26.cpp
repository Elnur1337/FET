#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../SortedSingleLinkedList.hpp"

TEST_CASE("operator++() increments pointer correctly") {
  SortedSingleLinkedList<int> list;
  list.add(1).add(2).add(3);
  SortedSingleLinkedList<int>::Iterator it = list.begin();
  ++it;
  REQUIRE(*it == 2);
  ++it;
  REQUIRE(*it == 3);
}
