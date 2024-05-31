#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "../CircularBuffer.hpp"
#include "doctest.h"

TEST_CASE("top returns a reference to the front element of the buffer") {
  CircularBuffer<int> buffer;
  buffer.push(1);
  buffer.push(2);
  buffer.push(3);
  int& front_element_ref = buffer.top();
  REQUIRE(front_element_ref == 1);
  front_element_ref = 10;
  REQUIRE(buffer.top() == 10);
}
