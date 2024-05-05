#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../SortedSingleLinkedList.hpp"

TEST_CASE("SortedSingleLinkedList empty method") {
  SortedSingleLinkedList<int> list;

  SUBCASE("Empty list") { CHECK(list.empty()); }

  SUBCASE("Non-empty list") {
    list.add(1);
    CHECK(!list.empty());
  }
}
