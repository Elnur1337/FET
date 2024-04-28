#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../SingleLinkedList.hpp"

TEST_CASE("Copy assignment operator assigns pointer") {
  SingleLinkedList<int> list;
  list.push_back(1).push_back(2).push_back(3);
  SingleLinkedList<int>::Iterator it1 = list.begin();
  SingleLinkedList<int>::Iterator it2;
  it2 = it1;
  REQUIRE(it1.node() == it2.node());
}
