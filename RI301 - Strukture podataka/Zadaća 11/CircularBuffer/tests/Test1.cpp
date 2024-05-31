#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../CircularBuffer.hpp"
#include "doctest.h"

TEST_CASE("CircularBuffer()") {
  CircularBuffer<int> buffer;
  SUBCASE("Default capacity") { CHECK(buffer.capacity() == 10); }
  SUBCASE("Default size") { CHECK(buffer.size() == 0); }
  SUBCASE("Empty buffer") { CHECK(buffer.empty()); }
}
