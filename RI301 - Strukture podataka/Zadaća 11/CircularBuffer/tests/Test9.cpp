#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "../CircularBuffer.hpp"
#include "doctest.h"

TEST_CASE("capacity returns the capacity of the buffer") {
  CircularBuffer<int> buffer;
  REQUIRE(buffer.capacity() == 10);
}

TEST_CASE("size returns the number of elements in the buffer") {
  CircularBuffer<int> buffer;
  buffer.push(1);
  REQUIRE(buffer.size() == 1);
  buffer.push(2);
  REQUIRE(buffer.size() == 2);
  buffer.pop();
  REQUIRE(buffer.size() == 1);
}
