#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../SortedSingleLinkedList.hpp"

TEST_CASE("cend returns an iterator to the end of the list") {
  SortedSingleLinkedList<int> list;
  list.add(1);
  list.add(2);
  list.add(3);

  // Get a const iterator to the end of the list.
  auto it = list.cend();

  // Check that the iterator is equal to the end iterator.
  CHECK(it == SortedSingleLinkedList<int>::Iterator(nullptr));
}
