#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../SortedSingleLinkedList.hpp"

TEST_CASE("head and tail return a pointer to the head and tail nodes in the "
          "list, respectively") {
  SortedSingleLinkedList<int> list;
  list.add(1);
  list.add(2);
  list.add(3);

  // Test the head method.
  Node<int>* headNode = list.head();
  CHECK(headNode->data == 1);

  // Test the tail method.
  Node<int>* tailNode = list.tail();
  CHECK(tailNode->data == 3);
}
