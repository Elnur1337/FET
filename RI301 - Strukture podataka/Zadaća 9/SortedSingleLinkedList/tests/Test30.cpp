#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../SortedSingleLinkedList.hpp"

TEST_CASE("find() returns correct iterator when element is found") {
  SortedSingleLinkedList<int> lst;
  lst.add(1);
  lst.add(2);
  lst.add(3);
  lst.add(4);

  auto it = lst.find(3);

  CHECK(*it == 3);
}

TEST_CASE("find() returns end() iterator when element is not found") {
  SortedSingleLinkedList<int> lst;
  lst.add(1);
  lst.add(2);
  lst.add(3);
  lst.add(4);

  auto it = lst.find(5);

  CHECK(it == lst.end());
}
