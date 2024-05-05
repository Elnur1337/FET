#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../SortedSingleLinkedList.hpp"

TEST_CASE("SortedSingleLinkedList destructor") {
  SUBCASE("Empty list") {
    SortedSingleLinkedList<int> list;
    list.~SortedSingleLinkedList();
    CHECK(list.size() == 0);
    CHECK(list.empty());
    CHECK(list.head() == nullptr);
    CHECK(list.tail() == nullptr);
  }

  SUBCASE("Non-empty list") {
    SortedSingleLinkedList<int> list;
    list.add(1);
    list.add(2);
    list.add(3);
    list.~SortedSingleLinkedList();
    CHECK(list.size() == 0);
    CHECK(list.empty());
    CHECK(list.head() == nullptr);
    CHECK(list.tail() == nullptr);
  }
}
