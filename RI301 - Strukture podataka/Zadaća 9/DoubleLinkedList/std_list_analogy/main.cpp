#include "../DoubleLinkedList.hpp"
#include <iostream>
#include <list>

int main() {
  std::cout << "Testing std::list and DoubleLinkedList analogy..." << std::endl;

  // Create a std::list and a DoubleLinkedList with the same elements
  std::list<int> std_list = {1, 2, 3, 4, 5};
  DoubleLinkedList<int> my_list;
  for (const auto& item : std_list) {
    my_list.push_back(item);
  }

  // Test size() method
  if (std_list.size() != my_list.size()) {
    std::cout << "Error: size() method not behaving identically" << std::endl;
    return 1;
  }

  // Test front() method
  if (std_list.front() != my_list.front()) {
    std::cout << "Error: front() method not behaving identically" << std::endl;
    return 1;
  }

  // Test back() method
  if (std_list.back() != my_list.back()) {
    std::cout << "Error: back() method not behaving identically" << std::endl;
    return 1;
  }

  // Test push_back() method
  std_list.push_back(6);
  my_list.push_back(6);
  if (std_list.size() != my_list.size() || std_list.back() != my_list.back()) {
    std::cout << "Error: push_back() method not behaving identically"
              << std::endl;
    return 1;
  }

  // Test push_front() method
  std_list.push_front(0);
  my_list.push_front(0);
  if (std_list.size() != my_list.size() ||
      std_list.front() != my_list.front()) {
    std::cout << "Error: push_front() method not behaving identically"
              << std::endl;
    return 1;
  }

  // Test pop_back() method
  std_list.pop_back();
  my_list.pop_back();
  if (std_list.size() != my_list.size() || std_list.back() != my_list.back()) {
    std::cout << "Error: pop_back() method not behaving identically"
              << std::endl;
    return 1;
  }

  // Test pop_front() method
  std_list.pop_front();
  my_list.pop_front();
  if (std_list.size() != my_list.size() ||
      std_list.front() != my_list.front()) {
    std::cout << "Error: pop_front() method not behaving identically"
              << std::endl;
    return 1;
  }

  // Test iterator behavior
  auto std_it = std_list.begin();
  auto my_it = my_list.begin();
  while (std_it != std_list.end() && my_it != my_list.end()) {
    if (*std_it != *my_it) {
      std::cout << "Error: iterator not behaving identically" << std::endl;
      return 1;
    }
    ++std_it;
    ++my_it;
  }

  // All tests passed
  std::cout << "All tests passed!" << std::endl;
  return 0;
}
