#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../SingleLinkedList.hpp"

TEST_CASE("operator++() increments pointer correctly") {
  SingleLinkedList<int> list;
  list.push_back(1).push_back(2).push_back(3);
  SingleLinkedList<int>::Iterator it = list.begin();
  ++it;
  REQUIRE(*it == 2);
  ++it;
  REQUIRE(*it == 3);
}
