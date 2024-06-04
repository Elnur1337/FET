#pragma once
#include <list>
#include <string>
#include<functional>
#include<stdexcept>
template <typename K, typename V>

class UnorderedMap {
  public:
  class Iterator;
  UnorderedMap();
  UnorderedMap(const UnorderedMap&);
  UnorderedMap(std::initializer_list<std::pair<K, V>> ranges);
  UnorderedMap(UnorderedMap&&);
  UnorderedMap& operator=(const UnorderedMap&);
  UnorderedMap& operator=(UnorderedMap&&);
  V& operator[](const K& key);
  ~UnorderedMap();
  Iterator begin() const;
  Iterator end() const;
  bool empty() const;
  // Broj elemenata
  size_t size() const;
  // Maksimalan broj bucket-a
  size_t capacity() const;
  void clear();
  Iterator insert(const K& key, const V& value);
  Iterator insert_range(std::initializer_list<std::pair<K, V>> ranges);
  Iterator erase(const K& key);
  V& at(const K& key);
  Iterator find(const K& key) const;
  bool contains(const K& key) const;
  double load_factor() const;
  bool operator==(const UnorderedMap&) const;
  bool operator!=(const UnorderedMap&) const;
  Iterator erase_if(std::function<bool(const std::pair<K, V>&)>&& p);

  private:
  size_t hasher(const K& key) const;
  void rehash_if_needed();
  void copy_map(const UnorderedMap&);

  // Broj bucket-a (linkanih lista)
  size_t number_of_buckets_{0};
  // Maksimalan broj bucket-a
  size_t capacity_{0};
  // Broj elemenata (cvorova)
  size_t number_of_elements_{0};
  // Ako je broj bucket-a 90% od maksimalnog broja bucket-a radimo rehasing kako
  // bismo povecali kapacitet mape i samim tim povecali ukupan broj slobodnih
  // mjesta za nove bucket-e
  const double max_load_{90};
  std::list<std::pair<K, V>>* buckets_{nullptr};
};

template <typename K, typename V>
class UnorderedMap<K, V>::Iterator {
  public:
  Iterator() = default;
  Iterator(typename std::list<std::pair<K, V>>::iterator it,
           std::list<std::pair<K, V>>* arr, size_t capacity, size_t bucket);
  Iterator(const Iterator&);
  Iterator(Iterator&&);
  Iterator& operator=(const Iterator&);
  Iterator& operator=(Iterator&&);
  Iterator& operator++();
  Iterator operator++(int);
  bool operator==(const Iterator& other) const;
  bool operator!=(const Iterator& other) const;
  std::pair<K, V>& operator*();
  std::pair<K, V>* operator->();
  ~Iterator();

  private:
  typename std::list<std::pair<K, V>>::iterator it_;
  std::list<std::pair<K, V>>* buckets_;
  size_t capacity_;
  size_t bucket_{0};
};

template <typename K, typename V>
void UnorderedMap<K, V>::rehash_if_needed() {
  if ((static_cast<double>(number_of_buckets_) / capacity_) * 100 >=
      max_load_) {
    auto* tmp = buckets_;
    capacity_ *= 2;
    buckets_ = new std::list<std::pair<K, V>>[capacity_];
    std::copy(tmp, tmp + capacity_, buckets_);
    delete[] tmp;
  }
}

template <typename K, typename V>
UnorderedMap<K, V>::UnorderedMap(std::initializer_list<std::pair<K, V>> ranges)
    : UnorderedMap() {
  for (const auto& pair : ranges) {
    insert(pair.first, pair.second);
  }
}

template <typename K, typename V>
size_t UnorderedMap<K, V>::hasher(const K& key) const {
  std::hash<K> generator;
  return generator(key) % capacity_;
}

template <typename K, typename V>
UnorderedMap<K, V>::UnorderedMap()
    : capacity_{10}, buckets_{new std::list<std::pair<K, V>>[capacity_]} {}

template <typename K, typename V>
V& UnorderedMap<K, V>::operator[](const K& key) {
  rehash_if_needed();
  const size_t index = hasher(key);
  auto& list = buckets_[index];
  // Dodajemo prvi element u novi bucket
  if (list.empty()) ++number_of_buckets_;
  auto it =
      std::find_if(list.begin(), list.end(),
                   [&key](const std::pair<K, V>& p) { return p.first == key; });
  // Element ne postoji kreiraj ga sa default vrijednoscu
  if (it == list.end()) {
    list.push_back(std::make_pair(key, V{}));
    ++number_of_elements_;
    return buckets_[index].back().second;
  } else {
    return it->second;
  }
}

template <typename K, typename V>
void UnorderedMap<K, V>::copy_map(const UnorderedMap& m) {
  number_of_buckets_ = m.number_of_buckets_;
  capacity_ = m.capacity_;
  number_of_elements_ = m.number_of_elements_;
  buckets_ = new std::list<std::pair<K, V>>[capacity_];
  std::copy(m.buckets_, m.buckets_ + capacity_, buckets_);
}
template <typename K, typename V>
UnorderedMap<K, V>::UnorderedMap(const UnorderedMap& m) {
  *this = m;
}
template <typename K, typename V>
UnorderedMap<K, V>::UnorderedMap(UnorderedMap&& m)
    : number_of_buckets_{m.number_of_buckets_}, capacity_{m.capacity_},
      number_of_elements_{m.number_of_elements_}, buckets_{m.buckets_} {
  m.capacity_ = m.number_of_buckets_ = m.number_of_elements_ = 0;
  m.buckets_ = nullptr;
}
template <typename K, typename V>
UnorderedMap<K, V>& UnorderedMap<K, V>::operator=(const UnorderedMap& m) {
  if (this != &m) {
    if (buckets_) delete[] buckets_;
    copy_map(m);
  }
  return *this;
}
template <typename K, typename V>
UnorderedMap<K, V>& UnorderedMap<K, V>::operator=(UnorderedMap&& m) {
  if (buckets_) delete[] buckets_;
  capacity_ = m.capacity_;
  number_of_buckets_ = m.number_of_buckets_;
  number_of_elements_ = m.number_of_elements_;
  buckets_ = m.buckets_;
  m.capacity_ = m.number_of_buckets_ = m.number_of_elements_ = 0;
  m.buckets_ = nullptr;
  return *this;
}
template <typename K, typename V>
UnorderedMap<K, V>::~UnorderedMap() {
  if (buckets_) delete[] buckets_;
  buckets_ = nullptr;
  capacity_ = number_of_buckets_ = number_of_elements_ = 0;
}
template <typename K, typename V>
typename UnorderedMap<K, V>::Iterator UnorderedMap<K, V>::begin() const {
  for (auto index = 0u; index < capacity_; ++index) {
    // Vracamo iterator na prvi element u prvom bucket-u koji nije prazan
    if (!buckets_[index].empty())
      return Iterator(buckets_[index].begin(), buckets_, capacity_, index);
  }
  return end();
}

template <typename K, typename V>
typename UnorderedMap<K, V>::Iterator UnorderedMap<K, V>::end() const {
  // Vracamo iterator na poziciju iza zadnjeg elementa u posljednjem bucket-u
  return Iterator(buckets_[capacity_ - 1].end(), buckets_, capacity_,
                  capacity_);
}
template <typename K, typename V>
bool UnorderedMap<K, V>::empty() const {
  return number_of_elements_ == 0;
}

template <typename K, typename V>
size_t UnorderedMap<K, V>::size() const {
  return number_of_elements_;
}
template <typename K, typename V>
size_t UnorderedMap<K, V>::capacity() const {
  return capacity_;
}
template <typename K, typename V>
void UnorderedMap<K, V>::clear() {
  // Reset na default stanje
  delete[] buckets_;
  buckets_ = nullptr;
  *this = std::move(UnorderedMap{});
}
template <typename K, typename V>
typename UnorderedMap<K, V>::Iterator UnorderedMap<K, V>::insert(
    const K& key, const V& value) {
  // Operator[] radi logiku insertovanja
  (*this)[key] = value;
  const size_t index = hasher(key);
  return Iterator(std::prev(buckets_[index].end()), buckets_, capacity_, index);
}

template <typename K, typename V>
typename UnorderedMap<K, V>::Iterator UnorderedMap<K, V>::insert_range(
    std::initializer_list<std::pair<K, V>> ranges) {
  Iterator first = end(), last;
  for (auto& elem : ranges) {
    last = insert(elem.first, elem.second);
    if (first == end()) {
      first = last;
    }
  }
  return first;
}
template <typename K, typename V>
typename UnorderedMap<K, V>::Iterator UnorderedMap<K, V>::erase(const K& key) {
  // Trazimo index bucketa
  const size_t index = hasher(key) % capacity_;
  auto& bucket = buckets_[index];
  if (bucket.empty()) {
    // Element ne postoji
    return end();
  }
  // Trazimo element
  auto it = bucket.begin();
  while (it != bucket.end() && it->first != key) {
    ++it;
  }
  // Dosli smo do kraja, element ne postoji
  if (it == bucket.end()) {
    return end();
  }
  // Uklanjamo element sa pozicije it
  it = bucket.erase(it);
  --number_of_elements_;
  if (it != bucket.end()) {
    // Obrisali smo posljednji element iz bucketa
    if (bucket.empty()) --number_of_buckets_;
    return Iterator(it, buckets_, capacity_, index);
  } else {
    // Trazimo iterator na prvu poziciju u prvom narednom bucket-u koji nije
    // zauzet
    size_t i = index;
    for (; i < capacity_; ++i) {
      if (!buckets_[i].empty()) {
        return Iterator(buckets_[i].begin(), buckets_, capacity_, i);
      }
    }
    // Vracamo se od pocetka
    for (auto k = 0u; k < i; ++k) {
      if (!buckets_[k].empty()) {
        return Iterator(buckets_[k].begin(), buckets_, capacity_, k);
      }
    }
    // End of map
    return end();
  }
}

template <typename K, typename V>
V& UnorderedMap<K, V>::at(const K& key) {
  size_t index = hasher(key) % capacity_;
  auto& bucket = buckets_[index];
  if (bucket.empty()) {
    throw std::out_of_range("Key not found in UnorderedMap");
  }
  // Search the linked list
  auto it = bucket.begin();
  while (it != bucket.end() && it->first != key) {
    ++it;
  }
  if (it == bucket.end()) {
    throw std::out_of_range("Key not found in UnorderedMap");
  }
  return it->second;
}

template <typename K, typename V>
typename UnorderedMap<K, V>::Iterator UnorderedMap<K, V>::find(
    const K& key) const {
  size_t index = hasher(key) % capacity_;

  auto& bucket = buckets_[index];
  if (bucket.empty()) {
    return end();
  }
  auto it = bucket.begin();
  while (it != bucket.end() && it->first != key) {
    ++it;
  }
  if (it == bucket.end()) {
    return end();
  }

  return Iterator(it, buckets_, capacity_, index);
}

template <typename K, typename V>
bool UnorderedMap<K, V>::contains(const K& key) const {
  return find(key) != end();
}
template <typename K, typename V>
double UnorderedMap<K, V>::load_factor() const {
  return max_load_;
}

template <typename K, typename V>
bool UnorderedMap<K, V>::operator==(const UnorderedMap& other) const {
  if (size() != other.size()) {
    return false;
  }
  for (auto& elem : *this) {
    auto it = other.find(elem.first);
    if (it == other.end() || it->second != elem.second) {
      return false;
    }
  }
  return true;
}
template <typename K, typename V>
bool UnorderedMap<K, V>::operator!=(const UnorderedMap& other) const {
  return !(*this == other);
}

template <typename K, typename V>
typename UnorderedMap<K, V>::Iterator UnorderedMap<K, V>::erase_if(
    std::function<bool(const std::pair<K, V>&)>&& predicate) {
  Iterator ret = end();
  for (auto it = begin(); it != end();) {
    // Ako je zadovoljen uslov brisemo element
    if (predicate(*it)) {
      it = erase(it->first);
      // Vracamo iterator na element iza zadnjeg uklonjenog elementa
      if (it != end()) {
        ret = it;
      }
    } else {
      ++it;
    }
  }

  return ret;
}
template <typename K, typename V>
UnorderedMap<K, V>::Iterator::Iterator(
    typename std::list<std::pair<K, V>>::iterator it,
    std::list<std::pair<K, V>>* arr, size_t capacity, size_t bucket)
    : it_(it), buckets_(arr), capacity_(capacity), bucket_{bucket} {}

template <typename K, typename V>
typename UnorderedMap<K, V>::Iterator& UnorderedMap<K,
                                                    V>::Iterator::operator++() {
  ++it_;
  // Trazimo novi bucket
  if (it_ == buckets_[bucket_].end()) {
    ++bucket_;
    for (; bucket_ < capacity_; ++bucket_) {
      if (!buckets_[bucket_].empty()) break;
    }
    if (capacity_ == bucket_) {
      // Dosli smo do kraja, vracamo end() od posljednjeg bucket-a
      it_ = buckets_[capacity_ - 1].end();
    } else {
      // Postavljamo it na begin() od prvog narednog validnog bucket-a
      it_ = buckets_[bucket_].begin();
    }
  }
  return *this;
}

template <typename K, typename V>
bool UnorderedMap<K, V>::Iterator::operator==(const Iterator& other) const {
  return it_ == other.it_;
}
template <typename K, typename V>
bool UnorderedMap<K, V>::Iterator::operator!=(const Iterator& other) const {
  return !(*this == other);
}

template <typename K, typename V>
std::pair<K, V>& UnorderedMap<K, V>::Iterator::operator*() {
  return *it_;
}

template <typename K, typename V>
std::pair<K, V>* UnorderedMap<K, V>::Iterator::operator->() {
  return &*it_;
}

template <typename K, typename V>
typename UnorderedMap<K, V>::Iterator UnorderedMap<K, V>::Iterator::operator++(
    int) {
  auto tmp = *this;
  ++(*this);
  return tmp;
}

template <typename K, typename V>
UnorderedMap<K, V>::Iterator::Iterator(const Iterator& it) {
  *this = it;
}
template <typename K, typename V>
UnorderedMap<K, V>::Iterator::Iterator(Iterator&& it) {
  *this = std::move(it);
}
template <typename K, typename V>
typename UnorderedMap<K, V>::Iterator& UnorderedMap<K, V>::Iterator::operator=(
    const Iterator& it) {
  if (this != &it) {
    it_ = it.it_;
    buckets_ = it.buckets_;
    capacity_ = it.capacity_;
    bucket_ = it.bucket_;
  }
  return *this;
}
template <typename K, typename V>
typename UnorderedMap<K, V>::Iterator& UnorderedMap<K, V>::Iterator::operator=(
    Iterator&& it) {
  it_ = std::move(it.it_);
  buckets_ = it.buckets_;
  capacity_ = it.capacity_;
  bucket_ = it.bucket_;
  it.buckets_ = nullptr;
  it.capacity_ = 0;
  it.bucket_ = 0;
  it.it_ = buckets_[capacity_ - 1].end();
  return *this;
}
template <typename K, typename V>
UnorderedMap<K, V>::Iterator::~Iterator() {
  buckets_ = nullptr;
  capacity_ = 0;
  bucket_ = 0;
}
