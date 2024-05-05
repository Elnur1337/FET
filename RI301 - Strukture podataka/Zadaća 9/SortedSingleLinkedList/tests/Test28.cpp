#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../SortedSingleLinkedList.hpp"

TEST_CASE("Test Iterator operator== and operator!=") {
  SortedSingleLinkedList<int> list;
  for (int i = 0; i < 10; ++i) {
    list.add(i);
  }

  // Test operator== for two equal iterators
  auto it1 = list.begin();
  auto it2 = list.begin();
  CHECK(it1 == it2);

  // Test operator== for two unequal iterators
  it2 = list.begin();
  ++it2;
  CHECK_FALSE(it1 == it2);

  // Test operator!= for two unequal iterators
  CHECK(it1 != it2);

  // Test operator!= for two equal iterators
  it2 = list.begin();
  CHECK_FALSE(it1 != it2);
}

TEST_CASE("Test Iterator operator++ and operator++(int)") {
  SortedSingleLinkedList<int> list;
  for (int i = 0; i < 10; ++i) {
    list.add(i);
  }

  // Test operator++ on prefix form
  auto it = list.begin();
  ++it;
  CHECK(*it == 1);

  // Test operator++ on postfix form
  it++;
  CHECK(*it == 2);

  // Test iterating through the entire list
  it = list.begin();
  for (int i = 0; i < 10; ++i) {
    CHECK(*it == i);
    ++it;
  }
  CHECK(it == list.end());
}
