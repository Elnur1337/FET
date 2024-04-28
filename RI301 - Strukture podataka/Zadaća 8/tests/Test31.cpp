#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../SingleLinkedList.hpp"

TEST_CASE("SingleLinkedList - insert") {
  SingleLinkedList<int> list;
  list.push_back(1);
  list.push_back(2);
  list.push_back(3);

  SUBCASE("Insert at the beginning") {
    auto it = list.insert(list.begin(), 0);
    CHECK(list.size() == 4);
    CHECK(*it == 0);
//     CHECK(*list.begin() == 0);
  }

//   SUBCASE("Insert in the middle") {
//     auto it = list.insert(++list.begin(), 10);
//     CHECK(list.size() == 4);
//     CHECK(*it == 10);
//     CHECK(*++list.begin() == 10);
//   }
// }
// 
// TEST_CASE("SingleLinkedList - insert on different positions") {
//   SingleLinkedList<int> list;
// 
//   // Insert into empty list
//   auto it = list.insert(list.begin(), 1);
//   REQUIRE(*it == 1);
//   REQUIRE(list.size() == 1);
//   REQUIRE(list.head()->data == 1);
//   REQUIRE(list.tail()->data == 1);
//   // Insert at beginning
//   it = list.insert(list.begin(), 2);
//   REQUIRE(*it == 2);
//   REQUIRE(list.size() == 2);
//   REQUIRE(list.head()->data == 2);
//   REQUIRE(list.tail()->data == 1);
// 
//   // Insert in middle
//   it = list.insert(++list.begin(), 4);
//   REQUIRE(*it == 4);
//   REQUIRE(list.size() == 3);
//   REQUIRE(list.head()->data == 2);
//   REQUIRE(list.tail()->data == 1);
}

