#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../CircularBuffer.hpp"
#include "doctest.h"

TEST_CASE("CircularBuffer& operator=(const CircularBuffer&)") {
  // Create a source buffer with some elements
  CircularBuffer<int> source;
  for (int i = 1; i <= 5; ++i) {
    source.push(i);
  }
  // Create a target buffer
  CircularBuffer<int> target;
  // Copy assign the source buffer to the target buffer
  target = source;
  // Check that the target has the same capacity as the source
  SUBCASE("Same capacity as source") { CHECK(target.capacity() == 10); }
  // Check that the target has the same size as the source
  SUBCASE("Same size as source") { CHECK(target.size() == 5); }
  // Check that the elements in the target are the same as in the source
  SUBCASE("Same elements as source") {
    while (!source.empty()) {
      CHECK(target.pop() == source.pop());
    }
  }
}
