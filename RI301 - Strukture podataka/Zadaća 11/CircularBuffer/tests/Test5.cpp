#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../CircularBuffer.hpp"
#include "doctest.h"

TEST_CASE("operator=(CircularBuffer&&) moves the buffer") {
  CircularBuffer<int> buffer1;
  buffer1.push(1).push(2).push(3);

  CircularBuffer<int> buffer2;
  buffer2.push(4).push(5);

  buffer2 = std::move(buffer1);

  REQUIRE(buffer2.size() == 3);
  REQUIRE(buffer2.capacity() == 10);
  REQUIRE(buffer2.pop() == 1);
  REQUIRE(buffer2.pop() == 2);
  REQUIRE(buffer2.pop() == 3);
  REQUIRE_THROWS_AS(buffer2.pop(), std::out_of_range);
}
