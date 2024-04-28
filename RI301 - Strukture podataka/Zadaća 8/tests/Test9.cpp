#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../SingleLinkedList.hpp"

TEST_CASE("SingleLinkedList head method") {
  SingleLinkedList<int> list;

  SUBCASE("Empty list") { CHECK(list.head() == nullptr); }

  SUBCASE("Non-empty list") {
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    CHECK(list.head()->data == 1);
  }
}
