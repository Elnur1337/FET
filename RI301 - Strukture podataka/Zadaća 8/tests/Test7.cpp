#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../SingleLinkedList.hpp"

TEST_CASE("SingleLinkedList destructor") {
  SUBCASE("Empty list") {
    SingleLinkedList<int> list;
    list.~SingleLinkedList();
    CHECK(list.size() == 0);
    CHECK(list.empty());
    CHECK(list.head() == nullptr);
    CHECK(list.tail() == nullptr);
  }

  SUBCASE("Non-empty list") {
    SingleLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.~SingleLinkedList();
    CHECK(list.size() == 0);
    CHECK(list.empty());
    CHECK(list.head() == nullptr);
    CHECK(list.tail() == nullptr);
  }
}
