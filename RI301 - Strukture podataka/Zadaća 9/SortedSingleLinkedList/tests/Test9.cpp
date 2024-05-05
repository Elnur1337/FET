#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../SortedSingleLinkedList.hpp"

TEST_CASE("SortedSingleLinkedList head method") {
  SortedSingleLinkedList<int> list;

  SUBCASE("Empty list") { CHECK(list.head() == nullptr); }

  SUBCASE("Non-empty list") {
    list.add(1);
    list.add(2);
    list.add(-3);
    CHECK(list.head()->data == -3);
  }
}
