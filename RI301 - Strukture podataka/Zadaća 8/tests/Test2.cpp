#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../SingleLinkedList.hpp"

TEST_CASE("Testing SingleLinkedList default constructor") {
  SingleLinkedList<int> list;

  SUBCASE("Empty list") {
    CHECK(list.size() == 0);
    CHECK(list.empty());
  }

  SUBCASE("Head and tail are null") {
    CHECK(list.head() == nullptr);
    CHECK(list.tail() == nullptr);
  }
}
