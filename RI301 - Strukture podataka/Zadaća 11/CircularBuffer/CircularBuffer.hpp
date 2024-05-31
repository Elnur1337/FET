#pragma once
#include <iostream>
#include <algorithm>
#include <string>

template <typename T>
class CircularBuffer {
private:
    size_t capacity_;
    size_t size_;
    size_t front_;
    size_t back_;
    T* arr_;

    friend std::ostream& operator<<(std::ostream& outputStream, const CircularBuffer& buffer) {
        size_t start = buffer.front_;
        outputStream << "{";
        for (size_t i = 0; i < buffer.size_; ++i) {
            outputStream << buffer[start];
            if (i + 1 != buffer.size_) {
                outputStream << ", ";
            }
            if (start + 1 == buffer.capacity_) {
                start = 0;
            }
            else {
                ++start;
            }
        }
        outputStream << "}";
        return outputStream;
    }
public:
    CircularBuffer() : capacity_{ 10 }, size_{ 0 }, front_{ 0 }, back_{ 0 }, arr_{ new T[capacity_] } {};

    explicit CircularBuffer(const size_t capacity) : capacity_{ capacity }, size_{ 0 }, front_{ 0 }, back_{ 0 }, arr_{ new T[capacity_] } {};

    CircularBuffer(const CircularBuffer& second) : capacity_{ second.capacity_ }, size_{ second.size_ }, front_{ second.front_ }, back_{ second.back_ }, arr_{ new T[capacity_] } {
        std::copy(second.arr_, second.arr_ + capacity_ - 1, arr_);
        return;
    }

    CircularBuffer(CircularBuffer&& second) : capacity_{ second.capacity_ }, size_{ second.size_ }, front_{ second.front_ }, back_{ second.back_ }, arr_{ second.arr_ } {
        second.capacity_ = second.size_ = second.front_ = second.back_ = 0;
        second.arr_ = nullptr;
        return;
    }

    CircularBuffer& operator=(const CircularBuffer& second) {
        if (*this == second) {
            return *this;
        }
        delete[] arr_;
        capacity_ = second.capacity_;
        size_ = second.size_;
        front_ = second.front_;
        back_ = second.back_;
        arr_ = new T[capacity_];
        std::copy(second.arr_, second.arr_ + capacity_ - 1, arr_);
        return *this;
    }

    CircularBuffer& operator=(CircularBuffer&& second) {
        if (*this == second) {
            return *this;
        }
        delete[] arr_;
        capacity_ = second.capacity_;
        size_ = second.size_;
        front_ = second.front_;
        back_ = second.back_;
        arr_ = second.arr_;
        second.capacity_ = second.size_ = second.front_ = second.back_ = 0;
        second.arr_ = nullptr;
        return *this;
    }

    template <typename U>
    CircularBuffer& push(U&& e) {
        if (arr_ == nullptr) {
            capacity_ = 10;
            arr_ = new T[capacity_];
        }
        if (front_ != 0 && size_ == 1 && back_ == 1) {
            --back_;
        }
        arr_[back_] = std::forward<U>(e);
        if (back_ + 1 == capacity_) {
            back_ = 0;
        }
        else {
            ++back_;
        }
        if (size_ != capacity_) {
            ++size_;
        }
        return *this;
    }

    T pop() {
        if (!size_) {
            throw std::out_of_range("Circular Buffer is empty!");
        }
        T returnValue = arr_[front_];
        if (front_ + 1 == capacity_) {
            if (back_ == 1) {
                --back_;
            }
            front_ = 0;
        }
        else {
            ++front_;
        }
        --size_;
        return returnValue;
    }

    inline bool empty() const { return !size_; };

    inline bool full() const { return size_ == capacity_; };

    inline size_t size() const { return size_; };

    inline size_t capacity() const { return capacity_; };

    inline operator bool() const { return size_; };

    bool operator==(const CircularBuffer& second) const {
        if (size_ != second.size_) {
            return false;
        }
        size_t fakeFront1 = front_;
        size_t fakeFront2 = second.front_;
        for (size_t i = 0; i < size_; ++i) {
            if (fakeFront1 + 1 == capacity_) {
                fakeFront1 = 0;
            }
            else {
                ++fakeFront1;
            }
            if (fakeFront2 + 1 == second.capacity_) {
                fakeFront2 = 0;
            }
            else {
                ++fakeFront2;
            }
            if (arr_[fakeFront1] != second.arr_[fakeFront2]) {
                return false;
            }
        }
        return true;
    }

    bool operator!=(const CircularBuffer& second) const {
        return !(operator==(second));
    }

    inline T& operator[](size_t pos) const { return arr_[pos]; };

    T& at(size_t pos) const {
        if ((front_ < back_ && (pos <= front_ || pos > back_)) || (back_ < front_ && (pos > back_ && pos < front_))) {
            throw std::invalid_argument("Element not found at position " + std::to_string(pos));
        }
        return arr_[pos];
    }

    T& front() const {
        if (!size_) {
            throw std::out_of_range("Circular Buffer is empty!");
        }
        return arr_[front_];
    }

    T& top() const { return front(); };

    T& back() const {
        if (!size_) {
            throw std::out_of_range("Circular Buffer is empty!");
        }
        if (back_ == 0) {
            return arr_[capacity_ - 1];
        }
        return arr_[back_ - 1];
    }

    ~CircularBuffer() {
        delete[] arr_;
        return;
    }

    void resize(size_t capacity) {
        if (capacity == capacity_) {
            return;
        }
        if (capacity < capacity_) {
            throw std::invalid_argument("Can't resize to smaller capacity!");
        }
        T* temp = arr_;
        arr_ = new T[capacity];
        for (size_t i = 0; front_ != back_; ++i) {
            arr_[i] = temp[front_];
            if (front_ + 1 == capacity_) {
                front_ = 0;
            }
            else {
                ++front_;
            }
        }
        capacity_ = capacity;
        front_ = 0;
        back_ = size_;
        return;
    }

    inline void clear() {
        front_ = back_ = size_ = 0;
        return;
    }
};
