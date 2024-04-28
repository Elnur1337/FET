#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../SingleLinkedList.hpp"

TEST_CASE("cend returns an iterator to the end of the list") {
  SingleLinkedList<int> list;
  list.push_back(1);
  list.push_back(2);
  list.push_back(3);

  // Get a const iterator to the end of the list.
  auto it = list.cend();

  // Check that the iterator is equal to the end iterator.
  CHECK(it == SingleLinkedList<int>::Iterator(nullptr));
}
