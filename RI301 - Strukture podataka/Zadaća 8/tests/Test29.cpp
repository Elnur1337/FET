#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../SingleLinkedList.hpp"

TEST_CASE("SingleLinkedList Iterator dereferencing") {
  SingleLinkedList<int> list;
  list.push_back(1);
  list.push_back(2);
  list.push_back(3);
  list.push_back(4);
  list.push_back(5);
  auto it = list.begin();
  REQUIRE(*it == 1);
  ++it;
  REQUIRE(*it == 2);
  ++it;
  REQUIRE(*it == 3);
  ++it;
  REQUIRE(*it == 4);
  ++it;
  REQUIRE(*it == 5);
}
