#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../SortedSingleLinkedList.hpp"

TEST_CASE("back and front return a reference to the last and first element in "
          "the list, respectively") {
  SortedSingleLinkedList<int> list;
  list.add(1);
  list.add(2);
  list.add(3);

  // Test the back method.
  int& backElement = list.back();
  CHECK(backElement == 3);

  // Test the front method.
  int& frontElement = list.front();
  CHECK(frontElement == 1);
}
