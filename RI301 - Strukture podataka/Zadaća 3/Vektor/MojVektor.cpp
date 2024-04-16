#include "MojVektor.hpp"

MojVektor::MojVektor(const std::initializer_list<int>& list) : capacity_{ list.size() * 2 }, size_{ list.size() }, arr_{new int[capacity_]} {
	std::copy(list.begin(), list.end(), arr_);
	return;
}

MojVektor::MojVektor(const MojVektor& second) : capacity_{ second.capacity_ }, size_{ second.size_ }, arr_{ new int[capacity_] } {
	std::copy(second.arr_, second.arr_ + size_, arr_);
	return;
}

MojVektor::MojVektor(MojVektor&& second) : capacity_{ std::move(second.capacity_) }, size_{ std::move(second.size_) }, arr_{ std::move(second.arr_) } {
	second.capacity_ = 0;
	second.size_ = 0;
	second.arr_ = nullptr;
	return;
}

MojVektor::~MojVektor() {
	delete[] arr_;
	capacity_ = 0;
	size_ = 0;
	return;
}

MojVektor& MojVektor::operator=(const MojVektor& second) {
	delete[] arr_;
	capacity_ = second.capacity_;
	size_ = second.size_;
	arr_ = new int[capacity_];
	std::copy(second.arr_, second.arr_ + size_, arr_);
	return *this;
}

MojVektor& MojVektor::operator=(MojVektor&& second) {
	delete[] arr_;
	capacity_ = std::move(second.capacity_);
	size_ = std::move(second.size_);
	arr_ = std::move(second.arr_);
	second.capacity_ = 0;
	second.size_ = 0;
	second.arr_ = nullptr;
	return *this;
}

void MojVektor::realoc() {
	capacity_ *= 2;
	const int *tempPtr = arr_;
	arr_ = new int[capacity_];
	std::copy(tempPtr, tempPtr + size_, arr_);
	delete[] tempPtr;
	return;
}

MojVektor& MojVektor::push_back(int element) {
	if (this->arr_ == nullptr) {
		capacity_ = 10;
		arr_ = new int[capacity_];
	}
	if (size_ >= capacity_) {
		realoc();
	}
	*(arr_ + size_) = element;
	++size_;
	return *this;
}

MojVektor& MojVektor::push_front(int element) {
	if (this->arr_ == nullptr) {
		capacity_ = 10;
		arr_ = new int[capacity_];
	}
	if (size_ >= capacity_) {
		realoc();
	}
	const int* tempPtr = arr_;
	arr_ = new int[size_ + 1];
	*arr_ = element;
	std::copy(tempPtr, tempPtr + size_, arr_ + 1);
	++size_;
	return *this;
}

int& MojVektor::at(size_t index) const {
	if (index >= size_) {
		throw std::out_of_range("Index out of range!");
	}
	return *(arr_ + index);
}

int& MojVektor::operator[](size_t index) const {
	return *(arr_ + index);
}

void MojVektor::clear() {
	capacity_ = 10;
	size_ = 0;
	delete[] arr_;
	arr_ = nullptr;
	return;
}

void MojVektor::resize(size_t newCapacity) {
	if (newCapacity >= capacity_) {
		realoc();
		resize(newCapacity);
		return;
	}
	size_ = newCapacity;
	return;
}

MojVektor& MojVektor::pop_back() {
	if (size_ == 0) {
		throw std::out_of_range("Vector is empty!");
	}
	--size_;
	return *this;
}

MojVektor& MojVektor::pop_front() {
	if (size_ == 0) {
		throw std::out_of_range("Vector is empty!");
	}
	const int* tempPtr = arr_;
	arr_ = new int[size_ - 1];
	std::copy(tempPtr + 1, tempPtr + size_, arr_);
	delete[] tempPtr;
	--size_;
	return *this;
}

int& MojVektor::back() const {
	if (size_ == 0) {
		throw std::out_of_range("Vector is empty!");
	}
	return *(arr_ + size_ - 1);
}

int& MojVektor::front() const {
	if (size_ == 0) {
		throw std::out_of_range("Vector is empty!");
	}
	return *arr_;
}

bool MojVektor::empty() const {
	if (size_ == 0) {
		return true;
	}
	return false;
}

bool MojVektor::operator==(const MojVektor& second) const {
	if (size_ != second.size_) {
		return false;
	}
	for (unsigned int i = 0; i < size_; ++i) {
		if (*(arr_ + i) != *(second.arr_ + i)) {
			return false;
		}
	}
	return true;
}

bool MojVektor::operator!=(const MojVektor& second) const {
	return !(*this == second);
}

std::ostream& operator<<(std::ostream& outputStream, const MojVektor& container) {
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