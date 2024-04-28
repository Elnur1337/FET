#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../SingleLinkedList.hpp"

TEST_CASE("SingleLinkedList move assignment operator") {
  SingleLinkedList<int> original;
  original.push_back(1);
  original.push_back(2);
  original.push_back(3);
  SingleLinkedList<int> copy;
  copy.push_back(4);
  copy.push_back(5);
  copy.push_back(6);
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
