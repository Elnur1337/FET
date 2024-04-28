#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../SingleLinkedList.hpp"
#include <stdexcept>

TEST_CASE("SingleLinkedList pop_front method") {
  SingleLinkedList<int> list;

  SUBCASE("Empty list throws exception") {
    CHECK_THROWS_AS(list.pop_front(), std::out_of_range);
  }

  SUBCASE("Remove one element from a list with one element") {
    list.push_back(1);
    list.pop_front();
    CHECK(list.size() == 0);
    CHECK(list.empty());
    CHECK(list.head() == nullptr);
    CHECK(list.tail() == nullptr);
  }

  SUBCASE("Remove one element from a list with multiple elements") {
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.pop_front();
    CHECK(list.size() == 2);
    CHECK(!list.empty());
    CHECK(list.head()->data == 2);
    CHECK(list.tail()->data == 3);
  }
}
