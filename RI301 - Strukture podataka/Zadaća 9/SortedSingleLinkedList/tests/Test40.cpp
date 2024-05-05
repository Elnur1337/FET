#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../SortedSingleLinkedList.hpp"

TEST_CASE("SortedSingleLinkedList::clear") {
  SortedSingleLinkedList<int> lst;

  // Add some elements to the list
  lst.add(1);
  lst.add(2);
  lst.add(3);

  CHECK_FALSE(lst.empty());
  CHECK_EQ(lst.size(), 3);

  // Clear the list
  lst.clear();

  CHECK(lst.empty());
  CHECK_EQ(lst.size(), 0);
}
