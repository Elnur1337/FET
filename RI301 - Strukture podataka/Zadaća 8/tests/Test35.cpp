#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../SingleLinkedList.hpp"

TEST_CASE("rcbegin returns a reverse const iterator to the last element in the "
          "list") {
  SingleLinkedList<int> list;
  list.push_back(1);
  list.push_back(2);
  list.push_back(3);

  // Get a reverse const iterator to the last element in the list.
  auto it = list.rcbegin();

  // Check that the reverse iterator points to the last element in the list.
  CHECK(*it == 3);
}
