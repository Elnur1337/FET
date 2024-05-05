#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../SortedSingleLinkedList.hpp"

TEST_CASE("SortedSingleLinkedList extend method") {
  SortedSingleLinkedList<int> list1;
  SortedSingleLinkedList<int> list2;

  SUBCASE("Extend an empty list with an empty list") {
    list1.extend(list2);
    CHECK(list1.size() == 0);
  }

  SUBCASE("Extend a non-empty list with an empty list") {
    list1.add(1);
    list1.add(2);
    list1.extend(list2);
    CHECK(list1.size() == 2);
  }

  SUBCASE("Extend an empty list with a non-empty list") {
    list2.add(1);
    list2.add(2);
    list1.extend(list2);
    CHECK(list1.size() == 2);
    CHECK(list1.head()->data == 1);
    CHECK(list1.tail()->data == 2);
  }

  SUBCASE("Extend a non-empty list with a non-empty list") {
    list1.add(1);
    list1.add(2);
    list2.add(3);
    list2.add(4);
    list1.extend(list2);
    CHECK(list1.size() == 4);
    CHECK(list1.head()->data == 1);
    CHECK(list1.head()->next->data == 2);
    CHECK(list1.tail()->data == 4);
  }
}
