#pragma once
#include <algorithm>
#include <iostream>

namespace Types {

template <typename T> class Heap {
public:
  Heap() : capacity_{10}, size_{0}, array_{new T[capacity_]} {}

  // Copy constructor
  Heap(const Heap& heap)
      : capacity_{heap.capacity_}, size_{heap.size_},
        array_{new T[heap.capacity_]} {
    std::copy(heap.array_, heap.array_ + heap.size_, array_);
  }

  // Move constructor
  Heap(Heap&& heap) noexcept
      : capacity_{heap.capacity_}, size_{heap.size_}, array_{heap.array_} {
    heap.array_ = nullptr;
    heap.size_ = 0;
    heap.capacity_ = 0;
  }

  // Copy assignment operator
  Heap& operator=(const Heap& heap) {
    if (this != &heap) {
      delete[] array_;
      capacity_ = heap.capacity_;
      size_ = heap.size_;
      array_ = new T[capacity_];
      std::copy(heap.array_, heap.array_ + heap.size_, array_);
    }
    return *this;
  }

  // Move assignment operator
  Heap& operator=(Heap&& heap) noexcept {
    if (this != &heap) {
      delete[] array_;
      capacity_ = heap.capacity_;
      size_ = heap.size_;
      array_ = heap.array_;
      heap.array_ = nullptr;
      heap.size_ = 0;
      heap.capacity_ = 0;
    }
    return *this;
  }

  template <typename U> Heap& add(U&& element) {
    if (full())
      realoc();
    array_[size_++] = std::forward<U>(element);
    if (size_ > 1)
      balanceUp(size_ - 1);
    return *this;
  }

  void remove() {
    if (empty())
      return;
    std::swap(array_[0], array_[size_ - 1]);
    --size_;
    balanceDown(0);
  }

  bool empty() const { return size_ == 0; }
  bool full() const { return size_ == capacity_; }

  ~Heap() { delete[] array_; }

  friend std::ostream& operator<<(std::ostream& os, const Heap& heap) {
    os << "[";
    for (int i = 0; i < heap.size_; i++) {
      if (i < heap.size_ - 1)
        os << heap.array_[i] << ",";
      else
        os << heap.array_[i] << "]" << std::endl;
    }
    return os;
  }

private:
  void balanceDown(size_t index) {
    if (index < size_) {
      size_t left = (index * 2) + 1;
      size_t right = (index * 2) + 2;
      if (left < size_ && right < size_ &&
          (array_[index] < array_[left] || array_[index] < array_[right])) {
        size_t maxIdx = array_[left] < array_[right] ? right : left;
        std::swap(array_[index], array_[maxIdx]);
        balanceDown(maxIdx);
      } else if (left < size_ && right >= size_ &&
                 array_[index] < array_[left]) {
        std::swap(array_[index], array_[left]);
        balanceDown(left);
      } else if (left >= size_ && right < size_ &&
                 array_[index] < array_[right]) {
        std::swap(array_[index], array_[right]);
        balanceDown(right);
      }
    }
  }

  void balanceUp(size_t index) {
    while (index > 0 && array_[(index - 1) / 2] < array_[index]) {
      std::swap(array_[(index - 1) / 2], array_[index]);
      index = (index - 1) / 2;
    }
  }

  void realoc() {
    capacity_ *= 2;
    T* tmp = array_;
    array_ = new T[capacity_];
    std::copy(tmp, tmp + size_, array_);
    delete[] tmp;
  }

  size_t capacity_;
  size_t size_;
  T* array_;
};
} // namespace Types

