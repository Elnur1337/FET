#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../SingleLinkedList.hpp"

TEST_CASE("SingleLinkedList empty method") {
  SingleLinkedList<int> list;

  SUBCASE("Empty list") { CHECK(list.empty()); }

  SUBCASE("Non-empty list") {
    list.push_back(1);
    CHECK(!list.empty());
  }
}
