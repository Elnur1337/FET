#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../SingleLinkedList.hpp"

TEST_CASE("SingleLinkedList::reverse") {
  SingleLinkedList<int> lst;

  // Add some elements to the list
  lst.push_back(1);
  lst.push_back(2);
  lst.push_back(3);
  lst.push_back(4);
  lst.push_back(5);

  // Reverse the list
  lst.reverse();

  CHECK_FALSE(lst.empty());
  CHECK_EQ(lst.size(), 5);

  // Check the reversed elements
  auto it = lst.begin();
  CHECK_EQ(*it, 5);
  ++it;
  CHECK_EQ(*it, 4);
  ++it;
  CHECK_EQ(*it, 3);
  ++it;
  CHECK_EQ(*it, 2);
  ++it;
  CHECK_EQ(*it, 1);
}
