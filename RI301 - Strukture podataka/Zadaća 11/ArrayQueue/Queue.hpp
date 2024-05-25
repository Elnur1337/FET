#pragma once
#include <algorithm>
#include <stdexcept>

template <typename T>
class Queue {
private:
	size_t capacity_;
	size_t size_;
	size_t front_;
	T* arr_;

	void copyQueue(const Queue& second) {
		delete[] arr_;
		capacity_ = second.capacity_;
		size_ = second.size_ - second.front_;
		front_ = 0;
		arr_ = new T[capacity_];
		std::copy(second.arr_ + second.front_, second.arr_ + second.size_, arr_);
		return;
	}
public:
	Queue() : capacity_{ 10 }, size_{ 0 }, front_{ 0 }, arr_{ new T[capacity_] } {};

	Queue(const Queue& second) : capacity_{ second.capacity_ }, size_{ second.size_ - second.front_ }, front_{ 0 }, arr_{ new T[capacity_] } {
		std::copy(second.arr_ + second.front_, second.arr_ + second.size_, arr_);
		return;
	}

	Queue(Queue&& second) : capacity_{ second.capacity_ }, size_{ second.size_ }, front_{ second.front_ }, arr_{ std::move(second.arr_) } {
		second.capacity_ = second.size_ = second.front_ = 0;
		second.arr_ = nullptr;
		return;
	}

	Queue& operator=(const Queue& second) {
		if (*this == second) {
			return *this;
		}
		copyQueue(second);
		return *this;
	}

	Queue& operator=(Queue&& second) {
		if (*this == second) {
			return *this;
		}
		delete[] arr_;
		capacity_ = second.capacity_;
		size_ = second.size_;
		front_ = second.front_;
		arr_ = std::move(second.arr_);
		second.capacity_ = second.size_ = second.front_ = 0;
		second.arr_ = nullptr;
		return *this;
	}

	~Queue() {
		delete[] arr_;
		//capacity_ = size_ = front_ = 0;
		return;
	}

	template <typename U>
	Queue& push(U&& e) {
		if (arr_ == nullptr) {
			capacity_ = 10;
			size_ = front_ = 0;
			arr_ = new T[capacity_];
		}
		if (size_ >= capacity_) {
			capacity_ *= 2;
			T* tempArr = arr_;
			arr_ = new T[capacity_];
			std::copy(tempArr + front_, tempArr + size_, arr_);
			size_ -= front_;
			front_ = 0;
			delete[] tempArr;
		}
		arr_[size_++] = std::forward<U>(e);
		return *this;
	}

	T pop() {
		if (size_ - front_ == 0) {
			throw std::out_of_range("Queue is empty!");
		}
		return arr_[front_++];
	}

	T& front() {
		if (size_ - front_ == 0) {
			throw std::out_of_range("Queue is empty!");
		}
		return arr_[front_];
	}

	inline size_t size() const { return size_ - front_; };

	inline size_t capacity() const { return capacity_; };

	inline bool empty() const { return size_ - front_ == 0; };

	inline bool full() const { return size_ == capacity_; };

	inline void clear() {
		size_ = front_ = 0;
		return;
	}
};