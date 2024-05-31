#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../CircularBuffer.hpp"
#include "doctest.h"

TEST_CASE("push() - adds element to the back of the buffer") {
  CircularBuffer<int> buffer;

  buffer.push(10);
  CHECK(buffer.size() == 1);
  CHECK(buffer.capacity() == 10);
  CHECK_FALSE(buffer.empty());
  CHECK_FALSE(buffer.full());
  CHECK(buffer.top() == 10);

  buffer.push(20);
  CHECK(buffer.size() == 2);
  CHECK(buffer.capacity() == 10);
  CHECK_FALSE(buffer.empty());
  CHECK_FALSE(buffer.full());
  CHECK(buffer.top() == 10);

  buffer.push(30);
  buffer.push(40);
  buffer.push(50);
  buffer.push(60);
  buffer.push(70);
  buffer.push(80);
  buffer.push(90);
  buffer.push(100);
  CHECK(buffer.size() == 10);
  CHECK(buffer.capacity() == 10);
  CHECK_FALSE(buffer.empty());
  CHECK(buffer.full());
  CHECK(buffer.top() == 10);

  buffer.push(100); // forces reallocation
  CHECK(buffer.size() == 11);
  CHECK(buffer.capacity() == 20);
  CHECK_FALSE(buffer.empty());
  CHECK_FALSE(buffer.full());
  CHECK(buffer.top() == 10);

  buffer.push(110);
  CHECK(buffer.size() == 12);
  CHECK(buffer.capacity() == 20);
  CHECK_FALSE(buffer.empty());
  CHECK_FALSE(buffer.full());
  CHECK(buffer.top() == 10);
}
