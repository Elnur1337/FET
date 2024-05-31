#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../CircularBuffer.hpp"
#include "doctest.h"

TEST_CASE("CircularBuffer(CircularBuffer&&)") {
  // Create a source buffer with some elements
  CircularBuffer<int> source;
  for (int i = 1; i <= 5; ++i) {
    source.push(i);
  }
  // Move construct a copy buffer
  CircularBuffer<int> copy{std::move(source)};
  // Check that the copy has the same capacity as the source
  SUBCASE("Same capacity as source") { CHECK(copy.capacity() == 10); }
  // Check that the copy has the same size as the source
  SUBCASE("Same size as source") { CHECK(copy.size() == 5); }
  // Check that the elements in the copy are the same as in the source
  SUBCASE("Same elements as source") {
    while (!source.empty()) {
      CHECK(copy.pop() == source.pop());
    }
  }
}

