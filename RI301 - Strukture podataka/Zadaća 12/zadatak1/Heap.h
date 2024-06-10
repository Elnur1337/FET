#pragma once
#include <iostream>
#include <algorithm>
#include <functional>

template <typename T>
class Heap {
private:
	size_t capacity_;
	size_t size_;
	T* arr_;

	void resize() {
		capacity_ *= 2;
		T* tempArr = arr_;
		arr_ = new T[capacity_];
		std::copy(tempArr, tempArr + size_, arr_);
		delete[] tempArr;
		return;
	}

	void fixUp(size_t index) {
		while (arr_[index] > arr_[(index - 1) / 2] && (((double)index - 1) / 2) >= 0) {
			std::swap(arr_[index], arr_[(index - 1) / 2]);
			index = (index - 1) / 2;
		}
		return;
	}

	void fixDown(size_t index = 0) {
		if ((2 * index + 1) < size_ && arr_[index] < arr_[2 * index + 1]) {
			std::swap(arr_[index], arr_[2 * index + 1]);
			fixDown(2 * index + 1);
			return;
		}
		if ((2 * index + 2) < size_ && arr_[index] < arr_[2 * index + 2]) {
			std::swap(arr_[index], arr_[2 * index + 2]);
			fixDown(2 * index + 2);
		}
		return;
	}

	void preorder(const std::function<void(T&)>& f, size_t index = 0) {
		if (index >= size_) {
			return;
		}
		f(arr_[index]);
		preorder(f, 2 * index + 1);
		preorder(f, 2 * index + 2);
		return;
	}

	void preorder(const std::function<void(T&)>& f, size_t index = 0) const {
		if (index >= size_) {
			return;
		}
		f(arr_[index]);
		preorder(f, 2 * index + 1);
		preorder(f, 2 * index + 2);
		return;
	}

	friend std::ostream& operator<<(std::ostream& outputStream, const Heap& heap) {
		heap.preorder([&outputStream](T& e) {
				outputStream << e << " ";
				return;
			}
		);
		return outputStream;
	}
public:
	Heap() : capacity_{ 10 }, size_{ 0 }, arr_{ new T[capacity_] } {};
	
	Heap(size_t capacity) : capacity_{ capacity }, size_{ 0 }, arr_{ new T[capacity_] } {};

	Heap(const Heap& second) : capacity_{ second.capacity_ }, size_{ second.size_ }, arr_{ new T[capacity_] } {
		std::copy(second.arr_, second.arr_ + size_, arr_);
		return;
	}

	Heap(Heap&& second) : capacity_{ second.capacity_ }, size_{ second.size_ }, arr_{ second.arr_ } {
		second.capacity_ = second.size_ = 0;
		second.arr_ = nullptr;
		return;
	}

	~Heap() {
		delete[] arr_;
		return;
	}

	Heap& operator=(const Heap& second) {
		if (*this == second) {
			return *this;
		}
		delete[] arr_;
		capacity_ = second.capacity_;
		size_ = second.size_;
		arr_ = new T[capacity_];
		std::copy(second.arr_, second.arr_ + second.size_, arr_);
		return *this;
	}

	Heap& operator=(Heap&& second) {
		if (*this == second) {
			return *this;
		}
		delete[] arr_;
		capacity_ = second.capacity_;
		size_ = second.size_;
		arr_ = second.arr_;
		second.capacity_ = second.size_ = 0;
		second.arr_ = nullptr;
		return *this;
	}

	template <typename U>
	Heap& push(U&& e) {
		if (arr_ == nullptr) {
			capacity_ = 10;
			size_ = 0;
			arr_ = new T[capacity_];
		}
		if (size_ >= capacity_) {
			resize();
		}
		arr_[size_++] = std::forward<U>(e);
		fixUp(size_ - 1);
		return *this;
	}

	T& max() {
		if (!size_) {
			throw std::out_of_range("Heap is empty!");
		}
		return arr_[0];
	}

	const T& max() const {
		if (!size_) {
			throw std::out_of_range("Heap is empty!");
		}
		return arr_[0];
	}

	T removeMax() {
		if (!size_) {
			throw std::out_of_range("Heap is empty!");
		}
		T returnValue = arr_[0];
		if (size_ != 1) {
			arr_[0] = arr_[size_ - 1];
			fixDown();
		}
		--size_;
		return returnValue;
	}

	inline size_t size() const { return size_; };
};