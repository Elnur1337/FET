#pragma once
#include <algorithm>
#include <stdexcept>

template <typename T>
class Stack {
private:
	size_t capacity_;
	size_t size_;
	T* arr_;

	void realoc() {
		capacity_ *= 2;
		T* tempArr = arr_;
		arr_ = new T[capacity_];
		std::copy(tempArr, tempArr + size_, arr_);
		delete[] tempArr;
		return;
	}
public:
	Stack() : capacity_{ 10 }, size_{ 0 }, arr_{ new T[capacity_] } {};

	Stack(const Stack& second) : capacity_{ second.capacity_ }, size_{ second.size_ }, arr_{ new T[capacity_] } {
		std::copy(second.arr_, second.arr_ + second.size_, arr_);
		return;
	}

	Stack(Stack&& second) : capacity_{ second.capacity_ }, size_{ second.size_ }, arr_{ std::move(second.arr_) } {
		second.capacity_ = second.size_ = 0;
		second.arr_ = nullptr;
		return;
	}

	~Stack() {
		delete[] arr_;
		capacity_ = size_ = 0;
		return;
	}

	Stack& operator=(const Stack& second) {
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

	Stack& operator=(Stack&& second) {
		if (*this == second) {
			return *this;
		}
		delete[] arr_;
		capacity_ = second.capacity_;
		size_ = second.size_;
		arr_ = std::move(second.arr_);
		second.capacity_ = second.size_ = 0;
		second.arr_ = nullptr;
		return *this;
	}

	template <typename U>
	Stack<T>& push(U&& e) {
		if (arr_ == nullptr) {
			capacity_ = 10;
			size_ = 0;
			arr_ = new T[capacity_];
		}
		if (size_ >= capacity_) {
			realoc();
		}
		arr_[size_++] = std::forward<U>(e);
		return *this;
	}

	T pop() {
		if (!size_) {
			throw std::out_of_range("Stack is empty!");
		}
		return arr_[--size_];
	}

	T& top() const {
		if (!size_) {
			throw std::out_of_range("Stack is empty!");
		}
		return arr_[size_ - 1];
	}

	inline size_t size() const { return size_; };

	inline size_t capacity() const { return capacity_; };

	inline bool empty() const { return size_ == 0; };

	inline bool full() const { return size_ == capacity_; };

	inline void clear() {
		size_ = 0;
		return;
	}

	void resize(size_t newSize, const T& defaultValue = 0) {
		if (newSize == size_) {
			return;
		}
		if (newSize < size_) {
			size_ = newSize;
			return;
		}
		capacity_ = newSize;
		T* tempArr = arr_;
		arr_ = new T[capacity_];
		std::copy(tempArr, tempArr + size_, arr_);
		delete[] tempArr;
		for (size_t i = size_; i < newSize; ++i) {
			arr_[i] = defaultValue;
		}
		size_ = newSize;
		return;
	}

	bool operator==(const Stack& second) const {
		if (size_ != second.size_) {
			return false;
		}
		for (size_t i = 0; i < size_; ++i) {
			if (arr_[i] != second.arr_[i]) {
				return false;
			}
		}
		return true;
	}

	bool operator!=(const Stack& second) const {
		return !(operator==(second));
	}
};