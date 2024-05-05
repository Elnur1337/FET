#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../SortedSingleLinkedList.hpp"

TEST_CASE("erase removes elements from the list specified by the range "
          "[beginIt, endIt)") {
  // Create a list with three elements.
  SortedSingleLinkedList<int> list;
  list.add(1);
  list.add(2);
  list.add(3);

  // Erase a range of elements that includes the first element.
  auto endIt = list.begin();
  ++endIt;
  ++endIt;
  auto it1 = list.erase(list.begin(), endIt);
  CHECK(list.size() == 1);
  CHECK(*list.begin() == 3);
  CHECK(it1 == list.begin());

  // Erase a range of elements that includes the last element.
  auto it2 = list.erase(list.begin(), list.end());
  CHECK(list.size() == 0);
  CHECK(it2 == list.end());

  // Create a new list with three elements.
  SortedSingleLinkedList<int> list2;
  list2.add(4);
  list2.add(5);
  list2.add(6);

  auto beginIt = list2.begin();
  ++beginIt;
  // Erase a range of elements that includes the middle element.
  auto it3 =
      list2.erase(beginIt, SortedSingleLinkedList<int>::Iterator{list2.tail()});
  CHECK(list2.size() == 2);
  CHECK(*list2.begin() == 4);
  CHECK(*it3 == 6);
}
