#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../SingleLinkedList.hpp"

TEST_CASE("head and tail return a pointer to the head and tail nodes in the "
          "list, respectively") {
  SingleLinkedList<int> list;
  list.push_back(1);
  list.push_back(2);
  list.push_back(3);

  // Test the head method.
  Node<int>* headNode = list.head();
  CHECK(headNode->data == 1);

  // Test the tail method.
  Node<int>* tailNode = list.tail();
  CHECK(tailNode->data == 3);
}
