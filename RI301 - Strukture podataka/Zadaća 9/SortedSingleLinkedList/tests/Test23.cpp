#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../SortedSingleLinkedList.hpp"

TEST_CASE("Move assignment operator moves pointer") {
  SortedSingleLinkedList<int> list;
  list.add(1).add(2).add(3);
  SortedSingleLinkedList<int>::Iterator it1 = list.begin();
  SortedSingleLinkedList<int>::Iterator it2(std::move(it1));
  REQUIRE(it2.node() == list.head());
  REQUIRE(it1.node() == nullptr);
}
