#pragma once
#include <iostream>	
#include <algorithm>
#include <stdexcept>

class MojVektor {
private:
	size_t capacity_;
	size_t size_;
	int* arr_;
	void realoc();

public:
	MojVektor() : capacity_{ 10 }, size_{ 0 }, arr_{ new int[capacity_] } {};
	MojVektor(const std::initializer_list<int>&);
	MojVektor(const MojVektor&);
	MojVektor(MojVektor&&);

	~MojVektor();

	MojVektor& operator=(const MojVektor&);
	MojVektor& operator=(MojVektor&&);

	MojVektor& push_back(int);
	MojVektor& push_front(int);

	size_t size() const { return size_; };

	int& at(size_t) const;
	int& operator[](size_t) const;

	void clear();

	void resize(size_t);

	MojVektor& pop_back();

	MojVektor& pop_front();

	int& back() const;

	int& front() const;

	bool empty() const;

	size_t capacity() const { return capacity_; };

	bool operator==(const MojVektor&) const;
	bool operator!=(const MojVektor&) const;
	int* data() { return arr_; };

};

std::ostream& operator<<(std::ostream&, const MojVektor&);
