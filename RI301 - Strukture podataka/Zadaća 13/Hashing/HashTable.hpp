#pragma once
#include <list>
#include <stdexcept>

namespace Types {

struct Student {
  std::string ime;
  std::string prezime;
  unsigned int index;
  unsigned int godina;
  double prosjek;
};

class HashTable {
public:
  HashTable() : studenti_{new std::list<Student>[capacity_]} {}

  // Copy constructor
  HashTable(const HashTable& other)
      : capacity_{other.capacity_}, size_{other.size_},
        studenti_{new std::list<Student>[other.capacity_]} {
    for (size_t i = 0; i < capacity_; ++i) {
      studenti_[i] = other.studenti_[i];
    }
  }

  // Copy assignment operator
  HashTable& operator=(const HashTable& other) {
    if (this != &other) {
      delete[] studenti_;
      capacity_ = other.capacity_;
      size_ = other.size_;
      studenti_ = new std::list<Student>[capacity_];
      for (size_t i = 0; i < capacity_; ++i) {
        studenti_[i] = other.studenti_[i];
      }
    }
    return *this;
  }

  // Move constructor
  HashTable(HashTable&& other) noexcept
      : capacity_{other.capacity_}, size_{other.size_},
        studenti_{other.studenti_} {
    other.studenti_ = nullptr;
    other.size_ = 0;
    other.capacity_ = 0;
  }

  // Move assignment operator
  HashTable& operator=(HashTable&& other) noexcept {
    if (this != &other) {
      delete[] studenti_;
      capacity_ = other.capacity_;
      size_ = other.size_;
      studenti_ = other.studenti_;
      other.studenti_ = nullptr;
      other.size_ = 0;
      other.capacity_ = 0;
    }
    return *this;
  }

  ~HashTable() { delete[] studenti_; }

  HashTable& add(const Student& stud) {
    size_t id = hash(stud.index);
    studenti_[id].push_back(stud);
    ++size_;
    return *this;
  }

  bool remove(const unsigned int index) {
    const auto ID = hash(index);
    if (ID >= capacity_)
      return false;
    auto& students = studenti_[ID];
    if (students.empty())
      return false;
    auto it = students.begin();
    while (it != students.end()) {
      if (it->index == index) {
        students.erase(it);
        --size_;
        return true;
      }
      ++it;
    }
    return false;
  }

  Student& find(const unsigned int index) {
    const auto ID = hash(index);
    if (ID >= capacity_)
      throw std::invalid_argument{"Student does not exist"};
    auto& students = studenti_[ID];
    if (students.empty())
      throw std::invalid_argument{"Student does not exist"};
    auto it = students.begin();
    while (it != students.end()) {
      if (it->index == index) {
        return *it;
      }
      ++it;
    }
    throw std::invalid_argument{"Student does not exist"};
  }

private:
  size_t hash(int ID) const { return ID % capacity_; }
  size_t hash2(int ID) const { return ID % capacity_; }

  size_t capacity_{107};
  size_t size_{0};
  std::list<Student>* studenti_;
};

} // namespace Types
