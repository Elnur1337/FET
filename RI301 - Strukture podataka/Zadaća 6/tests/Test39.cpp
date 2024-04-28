#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "../MojVektor.hpp"

TEST_CASE("MojVektor subvector testing") {
  // Create a vector with some test data.
  std::vector<int> testData = {1, 2, 3, 4, 5};

  // Create a MojVektor and copy the test data to it.
  MojVektor<int> v;
  for (int i : testData) {
    v.push_back(i);
  }

  SUBCASE("get the subvector from the beginning to the end") {
    MojVektor<int> subvec = v.subvector(v.begin(), v.end());
    REQUIRE(subvec.size() == 5);
    for (int i = 0; i < subvec.size(); ++i) {
      REQUIRE(subvec[i] == testData[i]);
    }
  }

  SUBCASE("get the subvector from the middle to the end") {
    MojVektor<int> subvec = v.subvector(v.begin() + 2, v.end());
    REQUIRE(subvec.size() == 3);
    for (int i = 0; i < subvec.size(); ++i) {
      REQUIRE(subvec[i] == testData[i + 2]);
    }
  }

  SUBCASE("get the subvector from the beginning to the middle") {
    MojVektor<int> subvec = v.subvector(v.begin(), v.begin() + 3);
    REQUIRE(subvec.size() == 3);
    for (int i = 0; i < subvec.size(); ++i) {
      REQUIRE(subvec[i] == testData[i]);
    }
  }

  SUBCASE("get the empty subvector") {
    MojVektor<int> subvec = v.subvector(v.begin(), v.begin());
    REQUIRE(subvec.size() == 0);
  }
}
