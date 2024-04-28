#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../SingleLinkedList.hpp"

TEST_CASE("SingleLinkedList::remove_if") {
  SingleLinkedList<int> lst;

  // Add some elements to the list
  lst.push_back(1);
  lst.push_back(2);
  lst.push_back(3);
  lst.push_back(4);
  lst.push_back(5);

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

