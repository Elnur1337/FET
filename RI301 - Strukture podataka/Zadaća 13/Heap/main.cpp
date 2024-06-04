#include "Heap.hpp"

int main(int argc, char* argv[]) {
  using Types::Heap;
  Heap<int> heap;
  heap.add(-4).add(-10).add(-50).add(0).add(1000).add(5000).add(5);
  std::cout << heap << std::endl;
  heap.remove();
  std::cout << heap << std::endl;
  return 0;
}
