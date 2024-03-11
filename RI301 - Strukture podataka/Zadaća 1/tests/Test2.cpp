#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../LongNumber.hpp"

TEST_CASE("Testing the LongNumber class") {
  LongNumber num1, num2(5), num3(num2), num4(std::move(num3));

  SUBCASE("Testing the copy and move assignment operators") {
    num1 = num2;
    CHECK(num1.value() == 5);
    num1 = std::move(num2);
    CHECK(num1.value() == 5);
  }
}
