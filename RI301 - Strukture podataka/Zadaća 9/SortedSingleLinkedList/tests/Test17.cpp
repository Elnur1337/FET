#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "../SortedSingleLinkedList.hpp"
#include "doctest.h"

TEST_CASE("Test extend method") {
  // Create two lists to extend
  SortedSingleLinkedList<int> list1;
  list1.add(1);
  list1.add(2);
  SortedSingleLinkedList<int> list2;
  list2.add(3);
  list2.add(4);

  // Extend the first list with the second list
  list1.extend(list2);
  CHECK_EQ(list1.size(), 4);
  const auto* head_ = list1.head();
  CHECK_EQ(head_->data, 1);
  head_ = head_->next;
  CHECK_EQ(head_->data, 2);
  head_ = head_->next;
  CHECK_EQ(head_->data, 3);
  head_ = head_->next;
  CHECK_EQ(head_->data, 4);
}

