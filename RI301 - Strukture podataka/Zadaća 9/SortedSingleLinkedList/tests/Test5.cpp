#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../SortedSingleLinkedList.hpp"

TEST_CASE("SortedSingleLinkedList copy assignment operator") {
  SortedSingleLinkedList<int> original;
  original.add(1);
  original.add(2);
  original.add(3);
  SortedSingleLinkedList<int> copy;
  copy.add(4);
  copy.add(5);
  copy.add(6);
  copy = original;

  SUBCASE("Size of the copy is the same as the original list") {
    CHECK(copy.size() == original.size());
  }

  SUBCASE("Head and tail pointers of the copy are not equal to those of the "
          "original list") {
    CHECK(copy.head() != original.head());
    CHECK(copy.tail() != original.tail());
  }

  SUBCASE(
      "Data of the nodes in the copy are equal to those in the original list") {
    auto* originalNode = original.head();
    auto* copyNode = copy.head();
    while (originalNode != nullptr) {
      CHECK(originalNode->data == copyNode->data);
      originalNode = originalNode->next;
      copyNode = copyNode->next;
    }
  }
}
