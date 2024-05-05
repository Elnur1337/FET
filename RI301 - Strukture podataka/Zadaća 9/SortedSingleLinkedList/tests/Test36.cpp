#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../SortedSingleLinkedList.hpp"

TEST_CASE("rbegin returns a reverse iterator to the last element in the list") {
  SortedSingleLinkedList<int> list;
  list.add(1);
  list.add(2);
  list.add(3);

  // Get a reverse iterator to the last element in the list.
  auto it = list.rbegin();

  // Check that the reverse iterator points to the last element in the list.
  CHECK(*it == 3);
}
