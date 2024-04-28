#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../SingleLinkedList.hpp"
#include "doctest.h"

TEST_CASE("SingleLinkedList push_front method") {
  SingleLinkedList<int> list;

  SUBCASE("Add one element to an empty list") {
    list.push_front(1);
    CHECK(list.size() == 1);
    CHECK(!list.empty());
    CHECK(list.head()->data == 1);
    CHECK(list.tail()->data == 1);
  }

  SUBCASE("Add multiple elements to a non-empty list") {
    list.push_front(3);
    list.push_front(2);
    list.push_front(1);
    CHECK(list.size() == 3);
    CHECK(!list.empty());
    CHECK(list.head()->data == 1);
    CHECK(list.head()->next->data == 2);
    CHECK(list.tail()->data == 3);
  }
}
