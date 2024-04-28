#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../SingleLinkedList.hpp"

TEST_CASE("SingleLinkedList size method") {
  SingleLinkedList<int> list;

  SUBCASE("Empty list") { CHECK(list.size() == 0); }

  SUBCASE("Non-empty list") {
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    CHECK(list.size() == 3);
  }
}
