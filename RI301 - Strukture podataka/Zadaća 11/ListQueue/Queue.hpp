#pragma once
#include <algorithm>
#include <stdexcept>
#include "SingleLinkedList.h"

template <typename T>
class Queue {
private:
	SingleLinkedList<T> elements_;

	void copyQueue(const Queue& second) {
		elements_ = second.elements_;
		return;
	}
public:
	Queue() = default;

	Queue(const Queue& second) : elements_{ second.elements_ } {};

	Queue(Queue&& second) : elements_{ std::move(second.elements_) } {};

	Queue& operator=(const Queue& second) {
		elements_ = second.elements_;
		return *this;
	}

	Queue& operator=(Queue&& second) {
		elements_ = std::move(second.elements_);
		return *this;
	}

	~Queue() = default;

	template <typename U>
	Queue& push(U&& e) {
		elements_.push_back(std::forward<U>(e));
		return *this;
	}

	T pop() {
		if (elements_.empty()) {
			throw std::out_of_range("Queue is empty!");
		}
		T returnValue = elements_.front();
		elements_.pop_front();
		return returnValue;
	}

	T& front() const {
		if (elements_.empty()) {
			throw std::out_of_range("Queue is empty!");
		}
		return elements_.front();
	}

	inline size_t size() const { return elements_.size(); };

	inline bool empty() const { return elements_.empty(); };

	void clear() {
		elements_.clear();
		return;
	}
};