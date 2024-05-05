#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../SortedSingleLinkedList.hpp"

TEST_CASE("Default constructor initializes null pointer") {
  SortedSingleLinkedList<int>::Iterator it;
  REQUIRE(it.node() == nullptr);
}
