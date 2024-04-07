#pragma once
#include <iostream>
#include <initializer_list>
#include <iterator>

template <typename T>
class MojVektor {
private:
	size_t capacity_;
	size_t size_;
	T *arr_;
	void realoc() {
		T *tempArr = arr_;
		capacity_ *= 2;
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

	MojVektor(const std::initializer_list<T>& list) : capacity_{ list.size() * 2 }, size_{ list.size() }, arr_{ new T[capacity_] } {
		std::copy(list.begin(), list.end(), arr_);
		return;
	}

	MojVektor(const MojVektor& second) : capacity_{ second.capacity_ }, size_{ second.size_ }, arr_{ new T[capacity_] } {
		std::copy(second.arr_, second.arr_ + second.size_, arr_);
		return;
	}

	MojVektor& operator=(const MojVektor& second) {
		capacity_ = second.capacity_;
		size_ = second.size_;
		arr_ = new T[capacity_];
		std::copy(second.arr_, second.arr_ + second.size_, arr_);
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
		capacity_ = 0;
		size_ = 0;
		return;
	}

	template<typename U>
	MojVektor& push_back(U&& element) {
		if (arr_ == nullptr) {
			capacity_ = 10;
			arr_ = new T[capacity_];
		}
		if (size_ >= capacity_) {
			realoc();
			push_back(element);
		}
		else {
			arr_[size_] = element;
			++size_;
		}
		return *this;
	}

	MojVektor& push_front(const T& element) {
		if (arr_ == nullptr) {
			capacity_ = 10;
			arr_ = new T[capacity_];
			arr_[0] = element;
			++size_;
			return *this;
		}
		if (size_ >= capacity_) {
			realoc();
			push_front(element);
		}
		else {
			T *tempArr = arr_;
			arr_ = new T[capacity_];
			arr_[0] = element;
			std::copy(tempArr, tempArr + size_, arr_ + 1);
			delete[] tempArr;
			++size_;
		}
		return *this;
	}

	MojVektor& push_front(T&& element) {
		if (size_ >= capacity_) {
			realoc();
			push_front(std::move(element));
		}
		else {
			T* tempArr = arr_;
			arr_ = new T[capacity_];
			arr_[0] = std::move(element);
			std::copy(tempArr, tempArr + size_, arr_ + 1);
			delete[] tempArr;
			++size_;
		}
		return *this;
	}
	size_t size() const { return size_; };

	T& at(size_t index) const {
		if (index < 0 || index >= size_) {
			throw std::out_of_range("Index out of range!");
		}
		return arr_[index];
	}
	T& operator[](size_t index) const {
		return *(arr_ + index);
	}

	T& operator[](size_t index) {
		return *(arr_ + index);
	}

	void clear() {
		delete[] arr_;
		size_ = 0;
		arr_ = nullptr;
		return;
	}

	void resize(size_t newSize, const T& difference_value = 0) {
		if (newSize >= capacity_) {
			realoc();
			resize(newSize, difference_value);
		}
		else {
			if (newSize < size_) {
				size_ = newSize;
			}
			else {
				while (size_ != newSize) {
					this->push_back(difference_value);
				}
			}
		}
		return;
	}

	MojVektor& pop_back() {
		if (this->empty()) {
			throw std::out_of_range("Vector is empty!");
		}
		--size_;
		return *this;
	}

	MojVektor& pop_front() {
		if (this->empty()) {
			throw std::out_of_range("Vector is empty!");
		}
		T* tempArr = arr_;
		arr_ = new T[capacity_];
		std::copy(tempArr + 1, tempArr + size_, arr_);
		delete[] tempArr;
		--size_;
		return *this;
	}

	T& back() const { 
		if (this->empty()) {
			throw std::out_of_range("Vector is empty!");
		}
		return *(arr_ + size_ - 1); 
	}

	T& front() const {
		if (this->empty()) {
			throw std::out_of_range("Vector is empty!");
		}
		return *arr_;
	}

	bool empty() const {
		if (size_ == 0) {
			return true;
		}
		return false;
	}
	size_t capacity() const { return capacity_; };

	bool operator==(const MojVektor& second) const {
		if (size_ != second.size_) {
			return false;
		}
		for (size_t i = 0; i < size_; ++i) {
			if (this->operator[](i) != second[i]) {
				return false;
			}
		}
		return true;
	}

	bool operator!=(const MojVektor& second) const {
		return !(this->operator==(second));
	}

	bool full() const {
		if (size_ == capacity_) {
			return true;
		}
		return false;
	}

	MojVektor subvector(Iterator begin, Iterator end) {
		MojVektor returnValue;
		returnValue.resize(end - begin);
		std::copy(begin, end, returnValue.arr_);
		return returnValue;
	}

	Iterator begin() const {
		return Iterator(arr_);
	}

	Iterator end() const {
		return Iterator(arr_ + size_);
	}

	Iterator find(const T& element) const {
		MojVektor::Iterator it = begin();
		while (it != end()) {
			if ((*it) == element) {
				return it;
			}
			++it;
		}
		return end();
	}

	Iterator erase(Iterator pos) {
		if (pos == begin()) {
			pop_front();
			return begin();
		}
		if (pos == end() - 1) {
			pop_back();
			return end();
		}
		if (pos == end()) {
			return pos;
		}
		Iterator it = pos;
		while (it != end()) {
			*it = *it + 1;
			++it;
		}
		--size_;
		return pos;
	}

	void erase(size_t pos) {
		if (pos >= size_) {
			throw std::out_of_range("Index out of range!");
		}
		T* tempArr = arr_;
		arr_ = new T[capacity_];
		for (size_t i = 0, j = 0; j < size_; ++i, ++j) {
			if (j != pos - 1) {
				arr_[i] = std::move(tempArr[j]);
			}
			else {
				--i;
			}
		}
		delete[] tempArr;
		--size_;
		return;
	}

	Iterator insert(Iterator pos, const T& element) {
		if (pos == begin()) {
			push_front(element);
			return begin();
		}
		if (pos == end()) {
			throw std::out_of_range("Iterator to end()!");
		}
		if (pos == end() - 1) {
			push_back(element);
			return end() - 1;
		}
		if (size_ >= capacity_) {
			realoc();
		}
		Iterator it = end();
		for (; it >= pos; --it) {
			*(it + 1) = *it;
		}
		*(it + 1) = element;
		++size_;
		return it + 1;
	}

	Iterator rbegin() const {
		return Iterator(arr_ + size_ - 1);
	}

	Iterator rend() const {
		return begin() - 1;
	}

	Iterator erase(Iterator beginIt, Iterator endIt) {
		size_t beginIndex = beginIt - Iterator(arr_);
		size_t endIndex = endIt - Iterator(arr_);

		if (beginIndex >= size_ || endIndex > size_ || beginIndex >= endIndex) {
			throw std::out_of_range("Iterators out of range!");
		}

		for (size_t i = beginIndex; i < endIndex; ++i) {
			arr_[i] = std::move(arr_[endIndex - beginIndex + i]);
		}
		size_ -= (endIndex - beginIndex);
		return Iterator(arr_ + beginIndex);
	}

	void rotate() {
		T* tempArr = arr_;
		arr_ = new T[capacity_];
		for (size_t i = 0, j = size_ - 1; i < size_; ++i, --j) {
			arr_[i] = tempArr[j];
		}
		delete[] tempArr;
		return;
	}

	void rotate(Iterator beginIt, Iterator endIt) {
		size_t beginIndex = beginIt - Iterator(arr_);
		size_t endIndex = endIt - Iterator(arr_) - 1;

		if (beginIndex >= size_ || endIndex > size_ || beginIndex >= endIndex) {
			throw std::out_of_range("Iterators out of range!");
		}

		while (beginIndex < endIndex) {
			std::swap(arr_[beginIndex], arr_[endIndex]);
			++beginIndex;
			--endIndex;
		}
		return;
	}

	T* data() { return arr_; };
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
class MojVektor<T>::Iterator
	: public std::iterator<std::random_access_iterator_tag, T> {
private:
	T* ptr_;

public:
	Iterator() :ptr_{ nullptr } {};

	Iterator(const Iterator& it) : ptr_{ it.ptr_ } {};

	Iterator(Iterator&& it) {
		ptr_ = std::move(it.ptr_);
		it.ptr_ = nullptr;
		return;
	}

	Iterator& operator=(const Iterator& it) {
		ptr_ = it.ptr_;
		return *this;
	}

	Iterator& operator=(Iterator&& it) {
		ptr_ = std::move(it.ptr_);
		it.ptr_ = nullptr;
		return *this;
	}

	Iterator(T* ptr) {
		ptr_ = ptr;
		return;
	}

	Iterator(T& element) {
		ptr_ = &element;
		return;
	}

	T& operator*() const {
		return *ptr_;
	}

	Iterator& operator++() {
		++ptr_;
		return *this;
	}

	Iterator operator++(int) {
		T* returnValue = ptr_;
		++ptr_;
		return returnValue;
	}

	Iterator& operator--() {
		--ptr_;
		return *this;;
	}

	Iterator operator--(int) {
		T* returnValue = ptr_;
		--ptr_;
		return returnValue;
	}

	Iterator operator+(size_t index) {
		return Iterator(ptr_ + index);
	}

	Iterator operator-(size_t index) {
		return Iterator(ptr_ - index);
	}

	T* operator->() const {
		return ptr_;
	}

	size_t operator-(const Iterator& second) {
		return ptr_ - second.ptr_;
	}

	Iterator operator[](size_t index) const {
		return Iterator(ptr_ + index);
	}

	bool operator==(const Iterator& it) const {
		if (ptr_ == it.ptr_) {
			return true;
		}
		return false;
	}

	bool operator!=(const Iterator& it) const {
		return !(this->operator==(it));
	}

	size_t operator-(const Iterator& rhs) const {
		return ptr_ - rhs.ptr_;
	}

	bool operator<(const Iterator& rhs) const {
		if (ptr_ < rhs.ptr_) {
			return true;
		}
		return false;
	}

	bool operator>(const Iterator& rhs) const {
		if (ptr_ > rhs.ptr_) {
			return true;
		}
		return false;
	}

	bool operator<=(const Iterator& rhs) const {
		if (ptr_ <= rhs.ptr_) {
			return true;
		}
		return false;
	}

	bool operator>=(const Iterator& rhs) const {
		if (ptr_ >= rhs.ptr_) {
			return true;
		}
		return false;
	}

	~Iterator() = default;

};
