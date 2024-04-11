#pragma once
#include <iostream>
#include <initializer_list>
#include <algorithm>
#include <iterator>

template <typename T>
class MojVektor {
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
	class Iterator;

	MojVektor() : capacity_{ 10 }, size_{ 0 }, arr_{ new T[capacity_] } {};

	MojVektor(size_t len, const T& elem) : capacity_{ len * 2 }, size_{ 0 }, arr_{ new T[capacity_] } {
		for (size_t i = 0; i < len; ++i)
		{
			this->push_back(elem);
		}
		return;
	}

	MojVektor(const std::initializer_list<T>& list) : capacity_{ list.size() }, size_{ list.size() }, arr_{ new T[capacity_] } {
		std::copy(list.begin(), list.end(), arr_);
		return;
	}

	MojVektor(const MojVektor& second) : capacity_{ second.capacity_ }, size_{ second.size_ }, arr_{ new T[capacity_] } {
		std::copy(second.arr_, second.arr_ + size_, arr_);
		return;
	}

	MojVektor& operator=(const MojVektor& second) {
		capacity_ = second.capacity_;
		size_ = second.size_;
		arr_ = new T[capacity_];
		std::copy(second.arr_, second.arr_ + size_, arr_);
		return *this;
	}

	MojVektor(MojVektor&& second) : capacity_{ std::move(second.capacity_) }, size_{ std::move(second.size_) }, arr_{ std::move(second.arr_) } {
		second.capacity_ = 0;
		second.size_ = 0;
		second.arr_ = nullptr;
		return;
	}

	MojVektor& operator=(MojVektor&& second) {
		capacity_ = std::move(second.capacity_);
		size_ = std::move(second.size_);
		arr_ = std::move(second.arr_);
		second.capacity_ = 0;
		second.size_ = 0;
		second.arr_ = nullptr;
		return *this;
	}

	~MojVektor() {
		delete[] arr_;
		size_ = 0;
		capacity_ = 0;
		return;
	}

	MojVektor& push_back(const T& e) {
		if (arr_ == nullptr) {
			capacity_ = 10;
			arr_ = new T[capacity_];
		}
		if (size_ >= capacity_) {
			realoc();
		}
		arr_[size_] = e;
		++size_;
		return *this;
	}

	MojVektor& push_front(const T& e) {
		if (arr_ == nullptr) {
			capacity_ = 10;
			arr_ = new T[capacity_];
		}
		if (size_ >= capacity_) {
			realoc();
		}
		for (T* endIndex = arr_ + size_ - 1; endIndex >= arr_; --endIndex) {
			*(endIndex + 1) = std::move(*(endIndex));
		}
		*(arr_) = e;
		++size_;
		return *this;
	}

	MojVektor& push_back(T&& e) {
		if (arr_ == nullptr) {
			capacity_ = 10;
			arr_ = new T[capacity_];
		}
		if (size_ >= capacity_) {
			realoc();
		}
		arr_[size_] = std::move(e);
		++size_;
		return *this;
	}

	MojVektor& push_front(T&& e) {
		if (arr_ == nullptr) {
			capacity_ = 10;
			arr_ = new T[capacity_];
		}
		if (size_ >= capacity_) {
			realoc();
		}
		for (T* endIndex = arr_ + size_ - 1; endIndex >= arr_; --endIndex) {
			*(endIndex + 1) = std::move(*(endIndex));
		}
		*(arr_) = std::move(e);
		++size_;
		return *this;
	}

	size_t size() const {
		return size_;
	}

	T& at(size_t index) const {
		if (index < 0 || index > size_ - 1) {
			throw std::out_of_range("Index out of range!");
		}
		return *(arr_ + index);
	}

	T& operator[](size_t index) const {
		return *(arr_ + index);
	}

	void clear() {
		capacity_ = 0;
		size_ = 0;
		delete[] arr_;
		arr_ = nullptr;
		return;
	}

	void resize(size_t newSize, const T& difference_value) {
		if (newSize < size_) {
			size_ = newSize;
		}
		else if (newSize > size_) {
			T* tempArr = arr_;
			capacity_ = newSize;
			arr_ = new T[capacity_];
			std::copy(tempArr, tempArr + size_, arr_);
			while (size_ < newSize) {
				arr_[size_] = difference_value;
				++size_;
			}
		}
		return;
	}

	MojVektor& pop_back() {
		if (size_ == 0) {
			throw std::out_of_range("Vector is empty!");
		}
		--size_;
		return *this;
	}

	MojVektor& pop_front() {
		if (size_ == 0) {
			throw std::out_of_range("Vector is empty!");
		}
		for (T* beginIndex = arr_; beginIndex < arr_ + size_; ++beginIndex) {
			*(beginIndex) = std::move(*(beginIndex + 1));
		}
		--size_;
		return *this;
	}

	T& back() const {
		if (size_ == 0) {
			throw std::out_of_range("Vector is empty!");
		}
		return arr_[size_ - 1];
	}

	T& front() const {
		if (size_ == 0) {
			throw std::out_of_range("Vector is empty!");
		}
		return *arr_;
	}

	bool empty() const {
		return size_ == 0;
	}

	size_t capacity() const {
		return capacity_;
	}

	bool operator==(const MojVektor& second) const {
		if (size_ != second.size_) {
			return false;
		}
		for (size_t i = 0; i < size_; ++i) {
			if ((this->operator[](i)) != second[i]) {
				return false;
			}
		}
		return true;
	}

	bool operator!=(const MojVektor& second) const {
		return !(this->operator==(second));
	}

	bool full() const {
		return size_ == capacity_;
	}

	MojVektor subvector(Iterator beginIt, Iterator endIt) const {
		if (beginIt < begin() || endIt > end()) {
			throw std::out_of_range("Iterators out of range!");
		}
		MojVektor v;
		while (beginIt != endIt) {
			v.push_back(*beginIt);
			++beginIt;
		}
		return v;
	}

	Iterator begin() const {
		return Iterator(arr_);
	}

	Iterator end() const {
		return Iterator(arr_ + size_);
	}

	Iterator find(const T& value) const {
		Iterator it = begin();
		while (it != end()) {
			if (*(it) == value) {
				return it;
			}
			++it;
		}
		return it;
	}

	Iterator erase(Iterator pos) {
		if (pos < begin() || pos > end()) {
			throw std::out_of_range("Iterator out of range!");
		}
		if (pos == end()) {
			return end();
		}
		Iterator it{ pos };
		while (it != end()) {
			*(it) = std::move(*(it + 1));
			++it;
		}
		--size_;
		return pos;
	}

	Iterator insert(Iterator pos, const T& e) {
		size_t index = pos - begin();
		if (index < 0 || index >= size_) {
			throw std::out_of_range("Iterator out of range!");
		}
		if (size_ >= capacity_) {
			realoc();
		}
		if (index == 0) {
			push_front(e);
		}
		else {
			for (size_t i = size_; i >= index; --i) {
				*(arr_ + i + 1) = std::move(*(arr_ + i));
			}
			arr_[index] = e;
			++size_;
		}
		return Iterator{ arr_ + index };
	}

	Iterator insert(Iterator pos, T&& e) {
		size_t index = pos - begin();
		if (index < 0 || index >= size_) {
			throw std::out_of_range("Iterator out of range!");
		}
		if (size_ >= capacity_) {
			realoc();
		}
		if (index == 0) {
			push_front(std::move(e));
		}
		else {
			for (size_t i = size_; i >= index; --i) {
				*(arr_ + i + 1) = std::move(*(arr_ + i));
			}
			arr_[index] = std::move(e);
			++size_;
		}
		return Iterator{ arr_ + index };
	}

	Iterator rbegin() const {
		return end() - 1;
	}

	Iterator rend() const {
		return begin() - 1;
	}

	Iterator erase(Iterator beginIt, Iterator endIt) {
		size_t beginIndex = beginIt - begin();
		size_t endIndex = endIt - begin();
		if (beginIndex > endIndex || beginIndex < 0 || endIndex > size_ || beginIndex > size_) {
			throw std::out_of_range("Iterators out of range!");
		}
		for (size_t i = beginIndex; i < endIndex; ++i) {
			arr_[i] = std::move(arr_[endIndex - beginIndex + i]);
		}
		size_ -= (endIndex - beginIndex);
		return Iterator{ arr_ + beginIndex };
	}

	void rotate() {
		for (size_t beginIndex = 0, endIndex = size_ - 1; beginIndex < endIndex; ++beginIndex, --endIndex) {
			std::swap(arr_[beginIndex], arr_[endIndex]);
		}
		return;
	}

	void rotate(Iterator beginIt, Iterator endIt) {
		size_t beginIndex = beginIt - Iterator(arr_);
		size_t endIndex = (endIt - Iterator(arr_)) - 1;
		if (beginIndex > endIndex || beginIndex < 0 || endIndex > size_ || beginIndex > size_) {
			throw std::out_of_range("Iterators out of range!");
		}
		while (beginIndex < endIndex) {
			std::swap(arr_[beginIndex], arr_[endIndex]);
			++beginIndex;
			--endIndex;
		}
		return;
	}

	T* data() {
		return arr_;
	}
};

template <typename T>
std::ostream& operator<<(std::ostream& outputStream, const MojVektor<T>& container) {
	const size_t size = container.size();
	outputStream << "{";
	for (size_t i = 0; i < size; ++i) {
		outputStream << container[i];
		if (i + 1 < size) {
			outputStream << ", ";
		}
	}
	outputStream << "}";
	return outputStream;
}

template <typename T>
class MojVektor<T>::Iterator : public std::iterator<std::random_access_iterator_tag, T> {
private:
	T* ptr_;

public:

	Iterator() : ptr_{ nullptr } {};

	Iterator(T* ptr) : ptr_{ ptr } {};

	Iterator(T& e) : ptr_{ &e } {};

	Iterator(const Iterator& second) : ptr_{ second.ptr_ } {};

	Iterator(Iterator&& second) : ptr_(std::move(second.ptr_)) {
		second.ptr_ = nullptr;
		return;
	}

	Iterator& operator=(const Iterator& second) {
		ptr_ = second.ptr_;
		return *this;
	}

	Iterator& operator=(Iterator&& second) {
		ptr_ = std::move(second.ptr_);
		second.ptr_ = nullptr;
		return *this;
	}

	T& operator*() {
		return *ptr_;
	}

	Iterator& operator++() {
		++ptr_;
		return *this;
	}

	Iterator operator++(int) {
		Iterator returnValue{ ptr_ };
		++ptr_;
		return returnValue;
	}

	Iterator& operator--() {
		--ptr_;
		return *this;
	}

	Iterator operator--(int) {
		Iterator returnValue{ ptr_ };
		--ptr_;
		return returnValue;
	}

	Iterator operator+(size_t n) const {
		return Iterator(ptr_ + n);
	}

	Iterator operator-(size_t n) const {
		return Iterator(ptr_ - n);
	}

	T* operator->() {
		return ptr_;
	}

	size_t operator-(const Iterator& second) const {
		return ptr_ - second.ptr_;
	}

	Iterator operator[](size_t index) const {
		return Iterator(ptr_ + index);
	}

	bool operator==(const Iterator& second) const {
		return ptr_ == second.ptr_;
	}

	bool operator!=(const Iterator& second) const {
		return !(this->operator==(second));
	}

	bool operator<(const Iterator& second) const {
		return ptr_ < second.ptr_;
	}

	bool operator>(const Iterator& second) const {
		return ptr_ > second.ptr_;
	}

	bool operator<=(const Iterator& second) const {
		return ptr_ <= second.ptr_;
	}

	bool operator>=(const Iterator& second) const {
		return ptr_ >= second.ptr_;
	}
};