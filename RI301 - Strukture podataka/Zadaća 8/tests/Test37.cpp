#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../SingleLinkedList.hpp"

TEST_CASE("back and front return a reference to the last and first element in "
          "the list, respectively") {
  SingleLinkedList<int> list;
  list.push_back(1);
  list.push_back(2);
  list.push_back(3);

  // Test the back method.
  int& backElement = list.back();
  CHECK(backElement == 3);

  // Test the front method.
  int& frontElement = list.front();
  CHECK(frontElement == 1);
}
