#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../SingleLinkedList.hpp"

TEST_CASE("SingleLinkedList copy constructor") {
  SingleLinkedList<int> original;
  original.push_back(1);
  original.push_back(2);
  original.push_back(3);
  SingleLinkedList<int> copy(original);

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
