#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../SingleLinkedList.hpp"

TEST_CASE("SingleLinkedList copy assignment operator") {
  SingleLinkedList<int> original;
  original.push_back(1);
  original.push_back(2);
  original.push_back(3);
  SingleLinkedList<int> copy;
  copy.push_back(4);
  copy.push_back(5);
  copy.push_back(6);
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
