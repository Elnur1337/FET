#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../LongNumber.hpp"

TEST_CASE("Testing the LongNumber class") {
  LongNumber num1, num2(5), num3(num2), num4(std::move(num3));

  SUBCASE("Testing the utility methods") {
    CHECK(num1.abs().value() == 0);
    CHECK(!num1.isOdd());
    CHECK(num1.isEven());
    CHECK(!num1.isPositive());
    CHECK(!num1.isNegative());
    CHECK(num1.num() == 0);
  }
}

