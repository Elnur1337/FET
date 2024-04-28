#include "MojVektor.hpp"
#include <algorithm>
#include <iostream>

int main(int argc, char* argv[]) {

  MojVektor<int> vec{4, 3, -2, 5, 10};
  auto it = std::find_if(vec.begin(), vec.end(),
                         [](const auto& element) { return element < -5; });

  if(it != vec.end()){
    std::cout << *it << std::endl;
  }
  else {
    std::cout << "Ne postoji" << std::endl;
  }
}

