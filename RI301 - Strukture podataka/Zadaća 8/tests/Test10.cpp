#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../SingleLinkedList.hpp"
#include "doctest.h"

TEST_CASE("SingleLinkedList tail method") {
  SingleLinkedList<int> list;

  SUBCASE("Empty list") { CHECK(list.tail() == nullptr); }

  SUBCASE("Non-empty list") {
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    CHECK(list.tail()->data == 3);
  }
}
