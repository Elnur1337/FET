#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../SingleLinkedList.hpp"

TEST_CASE("cbegin returns a const iterator to the first element in the list") {
  SingleLinkedList<int> list;
  list.push_back(1);
  list.push_back(2);
  list.push_back(3);

  // Get a const iterator to the first element in the list.
  auto it = list.cbegin();

  // Check that the iterator points to the first element in the list.
  CHECK(*it == 1);
}
