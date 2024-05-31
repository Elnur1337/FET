#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "../BST.hpp"
#include "doctest.h"

TEST_CASE("BST default constructor") {
  BST<int> bst;
  REQUIRE(bst.search(5) == nullptr);
  REQUIRE(bst.search(0) == nullptr);
  REQUIRE(bst.search(-5) == nullptr);
  REQUIRE(bst.search(10) == nullptr);
  REQUIRE(bst.search(7) == nullptr);
  REQUIRE(bst.search(15) == nullptr);
  REQUIRE(bst.search(20) == nullptr);
  REQUIRE(bst.search(1) == nullptr);
}
