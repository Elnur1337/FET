#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../SortedSingleLinkedList.hpp"

TEST_CASE("SortedSingleLinkedList move assignment operator") {
  SortedSingleLinkedList<int> original;
  original.add(1);
  original.add(2);
  original.add(3);
  SortedSingleLinkedList<int> copy;
  copy.add(4);
  copy.add(5);
  copy.add(6);
  const auto* tmpHead = original.head();
  const auto* tmpTail = original.tail();
  copy = std::move(original);

  SUBCASE("Size of the original list is 0 after moving") {
    CHECK(original.size() == 0);
  }

  SUBCASE("Size of the copy is the same as the original list before moving") {
    CHECK(copy.size() == 3);
  }

  SUBCASE("Head and tail pointers of the copy are equal to those of the "
          "original list before moving") {
    CHECK(copy.head() == tmpHead);
    CHECK(copy.tail() == tmpTail);
  }

  SUBCASE("Head and tail pointers of moved object are nullptr") {
    CHECK(original.head() == nullptr);
    CHECK(original.tail() == nullptr);
  }
}
