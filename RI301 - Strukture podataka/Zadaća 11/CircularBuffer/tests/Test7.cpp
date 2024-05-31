#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "../CircularBuffer.hpp"
#include "doctest.h"

TEST_CASE("pop returns the front element of the buffer") {
  CircularBuffer<int> buffer;
  buffer.push(1);
  buffer.push(2);
  buffer.push(3);
  int front_element = buffer.pop();
  REQUIRE(front_element == 1);
  REQUIRE(buffer.top() == 2);
}
