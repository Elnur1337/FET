#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../SortedSingleLinkedList.hpp"

TEST_CASE("SortedSingleLinkedList add method") {
  SortedSingleLinkedList<int> list;
  list.add(1);
  list.add(-2);
  list.add(5);
  list.add(0);
  list.add(-3);

  SUBCASE("Check whether elements are sorted") {
    const auto* listNode = list.head();
    const int minEl = listNode->data;
    while (listNode != nullptr) {
      CHECK(minEl <= listNode->data);
      listNode = listNode->next;
    }
  }

  SUBCASE("Check elements ordering") {
    const auto* listNode = list.head();
    CHECK(listNode->data == -3);
    listNode = listNode->next;
    CHECK(listNode->data == -2);
    listNode = listNode->next;
    CHECK(listNode->data == 0);
    listNode = listNode->next;
    CHECK(listNode->data == 1);
    listNode = listNode->next;
    CHECK(listNode->data == 5);
  }
}
