#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../SortedSingleLinkedList.hpp"

TEST_CASE("SortedSingleLinkedList Iterator dereferencing") {
  SortedSingleLinkedList<int> list;
  list.add(1);
  list.add(2);
  list.add(3);
  list.add(4);
  list.add(5);
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
