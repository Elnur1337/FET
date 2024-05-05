#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../SortedSingleLinkedList.hpp"

TEST_CASE("SortedSingleLinkedList tail method") {
  SortedSingleLinkedList<int> list;

  SUBCASE("Empty list") { CHECK(list.tail() == nullptr); }

  SUBCASE("Non-empty list") {
    list.add(1);
    list.add(5);
    list.add(3);
    CHECK(list.tail()->data == 5);
  }
}
