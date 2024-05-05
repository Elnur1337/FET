#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../SortedSingleLinkedList.hpp"

TEST_CASE("SortedSingleLinkedList size method") {
  SortedSingleLinkedList<int> list;

  SUBCASE("Empty list") { CHECK(list.size() == 0); }

  SUBCASE("Non-empty list") {
    list.add(1);
    list.add(2);
    list.add(3);
    CHECK(list.size() == 3);
  }
}
