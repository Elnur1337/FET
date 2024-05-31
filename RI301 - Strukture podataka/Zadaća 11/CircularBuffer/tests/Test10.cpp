#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "../CircularBuffer.hpp"
#include "doctest.h"

TEST_CASE("empty returns true when the buffer is empty and false otherwise") {
  CircularBuffer<int> buffer;
  REQUIRE(buffer.empty() == true);
  buffer.push(1);
  REQUIRE(buffer.empty() == false);
  buffer.pop();
  REQUIRE(buffer.empty() == true);
}

TEST_CASE("full returns true when the buffer is full and false otherwise") {
  CircularBuffer<int> buffer;
  REQUIRE(buffer.full() == false);
  buffer.push(1);
  REQUIRE(buffer.full() == false);
  buffer.push(2);
  REQUIRE(buffer.full() == false);
  buffer.push(3);
  REQUIRE(buffer.full() == false);
}
