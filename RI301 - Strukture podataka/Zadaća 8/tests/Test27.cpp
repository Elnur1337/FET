#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../SingleLinkedList.hpp"

TEST_CASE(
    "operator++(int) increments pointer correctly and returns old value") {
  SingleLinkedList<int> list;
  list.push_back(1).push_back(2).push_back(3);
  SingleLinkedList<int>::Iterator it = list.begin();
  auto old_it = it++;
  REQUIRE(*old_it == 1);
  REQUIRE(*it == 2);
  old_it = it++;
  REQUIRE(*old_it == 2);
  REQUIRE(*it == 3);
}
