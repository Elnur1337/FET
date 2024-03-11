#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../LongNumber.hpp"

TEST_CASE("Testing the LongNumber class") {
  LongNumber num1, num2(5), num3(num2), num4(std::move(num3));

  SUBCASE("Testing the constructors") {
    CHECK(num1.value() == 0);
    CHECK(num2.value() == 5);
    CHECK(num3.value() == 5);
    CHECK(num4.value() == 5);
  }
}

