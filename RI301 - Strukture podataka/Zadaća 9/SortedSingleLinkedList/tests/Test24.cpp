#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../SortedSingleLinkedList.hpp"

TEST_CASE("Destructor sets pointer to nullptr") {
  SortedSingleLinkedList<int> list;
  list.add(1).add(2).add(3);
  SortedSingleLinkedList<int>::Iterator it = list.begin();
  {
    SortedSingleLinkedList<int>::Iterator it2(it);
    REQUIRE(it2.node() == it.node());
  }
  REQUIRE(it.node() == list.head());
  it.~Iterator();
  REQUIRE(it.node() == nullptr);
}
