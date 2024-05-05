#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../SortedSingleLinkedList.hpp"

TEST_CASE("cbegin returns a const iterator to the first element in the list") {
  SortedSingleLinkedList<int> list;
  list.add(1);
  list.add(2);
  list.add(3);

  // Get a const iterator to the first element in the list.
  auto it = list.cbegin();

  // Check that the iterator points to the first element in the list.
  CHECK(*it == 1);
}
