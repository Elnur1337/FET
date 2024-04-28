#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../SingleLinkedList.hpp"

TEST_CASE("SingleLinkedList::clear") {
  SingleLinkedList<int> lst;

  // Add some elements to the list
  lst.push_back(1);
  lst.push_back(2);
  lst.push_back(3);

  CHECK_FALSE(lst.empty());
  CHECK_EQ(lst.size(), 3);

  // Clear the list
  lst.clear();

  CHECK(lst.empty());
  CHECK_EQ(lst.size(), 0);
}
