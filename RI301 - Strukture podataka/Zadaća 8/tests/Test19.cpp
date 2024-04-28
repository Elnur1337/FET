#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../SingleLinkedList.hpp"

TEST_CASE("Default constructor initializes null pointer") {
  SingleLinkedList<int>::Iterator it;
  REQUIRE(it.node() == nullptr);
}
