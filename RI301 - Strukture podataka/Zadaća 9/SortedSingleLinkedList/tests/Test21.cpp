#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../SortedSingleLinkedList.hpp"

TEST_CASE("Move constructor moves pointer and sets source to nullptr") {
  SortedSingleLinkedList<int> list;
  list.add(1).add(2).add(3);
  SortedSingleLinkedList<int>::Iterator it1 = list.begin();
  SortedSingleLinkedList<int>::Iterator it2(std::move(it1));
  REQUIRE(it1.node() == nullptr);
  REQUIRE(it2.node() == list.head());
}
