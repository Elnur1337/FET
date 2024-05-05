#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../SortedSingleLinkedList.hpp"

TEST_CASE("SortedSingleLinkedList::remove_if") {
  SortedSingleLinkedList<int> lst;

  // Add some elements to the list
  lst.add(1);
  lst.add(2);
  lst.add(3);
  lst.add(4);
  lst.add(5);

  // Remove even numbers
  lst.remove_if([](const int& x) { return x % 2 == 0; });

  CHECK_FALSE(lst.empty());
  CHECK_EQ(lst.size(), 3);

  // Check remaining elements
  auto it = lst.begin();
  CHECK_EQ(*it, 1);
  ++it;
  CHECK_EQ(*it, 3);
  ++it;
  CHECK_EQ(*it, 5);
}

