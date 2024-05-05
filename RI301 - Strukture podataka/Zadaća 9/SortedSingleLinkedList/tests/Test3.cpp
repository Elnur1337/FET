#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../SortedSingleLinkedList.hpp"

TEST_CASE("SortedSingleLinkedList copy constructor") {
  SortedSingleLinkedList<int> original;
  original.add(1);
  original.add(-2);
  original.add(5);
  original.add(0);
  original.add(-3);
  SortedSingleLinkedList<int> copy(original);

  SUBCASE("Size of the original list is equal to the copy") {
    CHECK(original.size() == copy.size());
  }

  SUBCASE("Head and tail pointers of list are not equal") {
    CHECK(original.head() != copy.head());
    CHECK(original.tail() != copy.tail());
  }

  SUBCASE(
      "Data of the nodes in the original list are equal to those in the copy") {
    const auto* originalNode = original.head();
    const auto* copyNode = copy.head();
    while (originalNode != nullptr) {
      CHECK(originalNode->data == copyNode->data);
      originalNode = originalNode->next;
      copyNode = copyNode->next;
    }
  } 
}
