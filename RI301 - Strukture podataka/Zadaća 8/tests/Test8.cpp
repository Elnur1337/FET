#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../SingleLinkedList.hpp"

TEST_CASE("SingleLinkedList push_back method") {
  SingleLinkedList<int> list;

  SUBCASE("Add one element to an empty list") {
    list.push_back(1);
    CHECK(list.size() == 1);
    CHECK(!list.empty());
    CHECK(list.head()->data == 1);
    CHECK(list.tail()->data == 1);
  }

  SUBCASE("Add multiple elements to a non-empty list") {
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    CHECK(list.size() == 3);
    CHECK(!list.empty());
    CHECK(list.head()->data == 1);
    CHECK(list.head()->next->data == 2);
    CHECK(list.tail()->data == 3);
  }
}
