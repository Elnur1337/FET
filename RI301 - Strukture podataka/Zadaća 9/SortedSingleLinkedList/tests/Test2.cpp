#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../SortedSingleLinkedList.hpp"

TEST_CASE("Testing SortedSingleLinkedList default constructor") {
  SortedSingleLinkedList<int> list;

  SUBCASE("Empty list") {
    CHECK(list.size() == 0);
    CHECK(list.empty());
  }

  SUBCASE("Head and tail are null") {
    CHECK(list.head() == nullptr);
    CHECK(list.tail() == nullptr);
  }
}
