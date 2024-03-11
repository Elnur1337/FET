#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../LongNumber.hpp"

TEST_CASE("Testing the LongNumber class") {
  LongNumber num1, num2(5), num3(num2), num4(std::move(num3));

  SUBCASE("Testing the comparison operators") {
    LongNumber num1{5}, num2{5};
    CHECK(num1 == num2);
    num2 = LongNumber{3};
    CHECK(num1 != num2);
    CHECK(num1 > num2);
    num1 = LongNumber{1};
    CHECK(num1 < num2);
    num1 = LongNumber{3};
    CHECK(num1 >= num2);
    CHECK(num1 <= num2);
  }
}
