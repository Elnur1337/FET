#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../SingleLinkedList.hpp"

TEST_CASE("Destructor sets pointer to nullptr") {
  SingleLinkedList<int> list;
  list.push_back(1).push_back(2).push_back(3);
  SingleLinkedList<int>::Iterator it = list.begin();
  {
    SingleLinkedList<int>::Iterator it2(it);
    REQUIRE(it2.node() == it.node());
  }
  REQUIRE(it.node() == list.head());
  it.~Iterator();
  REQUIRE(it.node() == nullptr);
}
