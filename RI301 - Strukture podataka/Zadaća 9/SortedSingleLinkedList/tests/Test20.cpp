#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../SortedSingleLinkedList.hpp"

TEST_CASE("Copy constructor creates new iterator with same pointer") {
  SortedSingleLinkedList<int> list;
  list.add(1).add(2).add(3);
  SortedSingleLinkedList<int>::Iterator it1 = list.begin();
  SortedSingleLinkedList<int>::Iterator it2(it1);
  REQUIRE(it1.node() == it2.node());
}
