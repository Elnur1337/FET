#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../SingleLinkedList.hpp"

TEST_CASE("find() returns correct iterator when element is found") {
  SingleLinkedList<int> lst;
  lst.push_back(1);
  lst.push_back(2);
  lst.push_back(3);
  lst.push_back(4);

  auto it = lst.find(3);

  CHECK(*it == 3);
}

TEST_CASE("find() returns end() iterator when element is not found") {
  SingleLinkedList<int> lst;
  lst.push_back(1);
  lst.push_back(2);
  lst.push_back(3);
  lst.push_back(4);

  auto it = lst.find(5);

  CHECK(it == lst.end());
}
