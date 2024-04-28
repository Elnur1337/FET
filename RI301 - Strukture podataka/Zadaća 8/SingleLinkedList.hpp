#pragma once
#include <iostream>
#include <stdexcept>
#include <functional>

template <typename T>
struct Node {
    T data;
    Node<T>* next;
    Node(const T& e) : data{ e }, next{ nullptr } {};
    Node(T&& e) : data{ std::move(e) }, next{ nullptr } {};
};

template <typename T>
class SingleLinkedList {
private:
    /*struct Node {
        T data;
        Node<T>* next;
        Node(const T& e) : data{ e }, next{ nullptr } {};
        Node(T&& e) : data{ std::move(e) }, next{ nullptr } {};
    };*/

    Node<T>* head_;
    Node<T>* tail_;
    size_t size_;

    void copyList(const SingleLinkedList& second) {
        if (second.size_ == 0) {
            head_ = tail_ = nullptr;
            size_ = 0;
            return;
        }
        Iterator it = second.begin();
        head_ = tail_ = new Node<T>(*it);
        ++it;
        ++size_;
        while (it != second.end()) {
            push_back(*it);
            ++it;
        }
        return;
    }

    void dealoc() {
        if (size_ == 0) {
            return;
        }
        if (size_ == 1) {
            delete head_;
        }
        else {
            Node<T>* ptr = head_->next;
            Node<T>* ptrPrev = head_;
            while (ptr != nullptr) {
                delete ptrPrev;
                ptrPrev = ptr;
                ptr = ptr->next;
            }
            delete ptrPrev;
        }
        head_ = tail_ = nullptr;
        size_ = 0;
        return;
    }

    friend std::ostream& operator<<(std::ostream& outputStream, const SingleLinkedList& list) {
        Iterator start = list.begin();
        const Iterator finish = list.cend();

        outputStream << "{";
        if (list.size_ == 1) {
            outputStream << *start;
        }
        else if (list.size_ > 1) {
            while (start != finish) {
                outputStream << *start;
                ++start;
                if (start != finish) {
                    outputStream << ", ";
                }
            }
        }
        outputStream << "}";
        return outputStream;
    }

public:
    class Iterator;

    SingleLinkedList() : head_{ nullptr }, tail_{ nullptr }, size_{ 0 } {};

    SingleLinkedList(const SingleLinkedList& second) {
        copyList(second);
        return;
    }

    SingleLinkedList(SingleLinkedList&& second) : head_{ std::move(second.head_) }, tail_{ std::move(second.tail_) }, size_{ second.size_ } {
        second.head_ = second.tail_ = nullptr;
        second.size_ = 0;
        return;
    }

    SingleLinkedList& operator=(const SingleLinkedList& second) {
        if (this != &second) {
            SingleLinkedList temp(second);
            std::swap(head_, temp.head_);
            std::swap(tail_, temp.tail_);
            std::swap(size_, temp.size_);
        }
        return *this;
    }

    SingleLinkedList& operator=(SingleLinkedList&& second) {
        dealoc();
        head_ = std::move(second.head_);
        tail_ = std::move(second.tail_);
        size_ = second.size_;
        second.head_ = second.tail_ = nullptr;
        second.size_ = 0;
        return *this;
    }

    ~SingleLinkedList() {
        dealoc();
        return;
    }

    SingleLinkedList& push_back(const T& e) {
        if (size_ == 0) {
            head_ = new Node<T>(e);
            tail_ = head_;
        }
        else {
            tail_->next = new Node<T>(e);
            tail_ = tail_->next;
        }
        ++size_;
        return *this;
    }

    SingleLinkedList& push_back(T&& e) {
        if (size_ == 0) {
            head_ = new Node<T>(std::move(e));
            tail_ = head_;
        }
        else {
            tail_->next = new Node<T>(std::move(e));
            tail_ = tail_->next;
        }
        ++size_;
        return *this;
    }

    SingleLinkedList& push_front(const T& e) {
        if (size_ == 0) {
            head_ = new Node<T>(e);
            tail_ = head_;
        }
        else {
            Node<T>* exHead = head_;
            head_ = new Node<T>(e);
            head_->next = exHead;
        }
        ++size_;
        return *this;
    }

    SingleLinkedList& push_front(T&& e) {
        if (size_ == 0) {
            head_ = new Node<T>(std::move(e));
            tail_ = head_;
        }
        else {
            Node<T>* exHead = head_;
            head_ = new Node<T>(std::move(e));
            head_->next = exHead;
        }
        ++size_;
        return *this;
    }

    SingleLinkedList& pop_front() {
        if (size_ == 0) {
            throw std::out_of_range("List is empty!");
        }
        if (size_ == 1) {
            delete head_;
            head_ = tail_ = nullptr;
        }
        else {
            Node<T>* tempHead = head_;
            head_ = head_->next;
            delete tempHead;
        }
        --size_;
        return *this;
    }

    SingleLinkedList& pop_back() {
        if (size_ == 0) {
            throw std::out_of_range("List is empty!");
        }
        if (size_ == 1) {
            delete head_;
            head_ = tail_ = nullptr;
        }
        else {
            Node<T>* ptr = head_;
            while (ptr->next != tail_) {
                ptr = ptr->next;
            }
            delete tail_;
            tail_ = ptr;
            tail_->next = nullptr;
        }
        --size_;
        return *this;
    }

    bool empty() const { return size_ == 0; };

    size_t size() const { return size_; };

    SingleLinkedList& extend(const SingleLinkedList& second) {
        if (second.size_ == 0) {
            return *this;
        }
        Node<T>* ptr = second.head_;
        while (ptr != nullptr) {
            push_back(ptr->data);
            ptr = ptr->next;
        }
        return *this;
    }

    SingleLinkedList& extend(SingleLinkedList&& second) {
        if (second.size_ == 0) {
            return *this;
        }
        if (size_ == 0) {
            head_ = std::move(second.head_);
            tail_ = std::move(second.tail_);
            size_ = second.size_;
        }
        else {
            tail_->next = second.head_;
            tail_ = second.tail_;
            size_ += second.size_;
        }
        second.head_ = second.tail_ = nullptr;
        second.size_ = 0;
        return *this;
    }

    Iterator find(const T& e) const {
        Iterator it{ head_ };
        const Iterator finish{ nullptr };
        while (it != finish) {
            if ((*it) == e) {
                break;
            }
            ++it;
        }
        return it;
    }

    Iterator insert(Iterator pos, const T& e) {
        if (pos == Iterator{ nullptr }) {
            push_back(e);
            return Iterator{ tail_ };
        }
        if (pos == Iterator{ head_ }) {
            push_front(e);
            return Iterator{ head_ };
        }
        Iterator it{ head_ };
        ++it;
        Node<T>* prev = head_;
        while (it != pos) {
            if (it == Iterator{ nullptr }) {
                throw std::out_of_range("Iterator out of range!");
            }
            ++it;
            prev = prev->next;
        }
        Node<T>* holder = new Node<T>(e);
        holder->next = prev->next;
        prev->next = holder;
        ++size_;
        return Iterator(holder);
    }

    Iterator erase(Iterator pos) {
        if (pos == Iterator{ head_ }) {
            pop_front();
            return Iterator{ head_ };
        }
        if (pos == Iterator{ tail_ }) {
            pop_back();
            return Iterator{ nullptr };
        }
        Node<T>* curr = head_->next;
        Node<T>* prev = head_;
        while (pos != Iterator{ curr }) {
            if (curr == nullptr) {
                throw std::out_of_range("Iterator out of range!");
            }
            curr = curr->next;
            prev = prev->next;
        }
        prev->next = curr->next;
        delete curr;
        --size_;
        return Iterator{ prev->next };
    }

    Iterator begin() const { return Iterator{ head_ }; };

    Iterator end() const { return Iterator{ nullptr }; };

    const Iterator cbegin() const { return Iterator{ head_ }; };

    const Iterator cend() const { return Iterator{ nullptr }; };

    Iterator rbegin() const { return Iterator{ tail_ }; };

    const Iterator rcbegin() const { return Iterator{ tail_ }; };

    Node<T>* head() const { return head_; };

    Node<T>* tail() const { return tail_; };

    T& back() const { return tail_->data; };

    T& front() const { return head_->data; };

    Iterator erase(Iterator beginIt, Iterator endIt) {
        Node<T>* first = head_;
        Node<T>* prev = nullptr;
        while (beginIt != Iterator{ first }) {
            if (first == nullptr) {
                throw std::out_of_range("Iterator out of range!");
            }
            prev = first;
            first = first->next;
        }
        size_t deleteOffset = 0;
        Node<T>* nextPtr;
        while (Iterator{ first } != endIt) {
            nextPtr = first->next;
            delete first;
            ++deleteOffset;
            first = nextPtr;
        }
        if (prev == nullptr) {
            head_ = first;
        }
        else {
            prev->next = first;
        }
        if (endIt == end()) {
            tail_ = prev;
        }
        size_ -= deleteOffset;
        return endIt;
    }

    void clear() {
        dealoc();
        return;
    }

    void remove_if(std::function<bool(const T&)>&& p) {
        Node<T>* curr = head_;
        Node<T>* prev = nullptr;

        while (curr != nullptr) {
            if (p(curr->data)) {
                if (curr == head_) {
                    head_ = curr->next;
                    delete curr;
                    curr = head_;
                }
                else {
                    prev->next = curr->next;
                    delete curr;
                    curr = prev->next;
                }
                --size_;
            }
            else {
                prev = curr;
                curr = curr->next;
            }
        }
        return;
    }

    void reverse() {
        if (head_ == nullptr || head_->next == nullptr) {
            return;
        }
        Node<T>* prev = nullptr;
        Node<T>* curr = head_;
        Node<T>* next = nullptr;
        tail_ = head_;
        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head_ = prev;
        return;
    }

};

template <typename T>
class SingleLinkedList<T>::Iterator : public std::iterator<std::forward_iterator_tag, T> {
private:
    Node<T>* ptr_;

public:
    Iterator() : ptr_{ nullptr } {};

    Iterator(Node<T>* ptr) : ptr_{ ptr } {};

    Iterator(const Iterator& second) : ptr_{ second.ptr_ } {};

    Iterator(Iterator&& second) : ptr_{ std::move(second.ptr_) } {
        second.ptr_ = nullptr;
        return;
    }

    ~Iterator() {
        ptr_ = nullptr;
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
        return ptr_->data;
    }

    Iterator& operator++() {
        ptr_ = ptr_->next;
        return *this;
    }

    Iterator operator++(int) {
        Iterator returnValue{ ptr_ };
        ptr_ = ptr_->next;
        return returnValue;
    }

    Iterator operator+(size_t n) const {
        Iterator returnValue{ ptr_ };
        for (size_t i = 0; i < n; ++i) {
            returnValue.ptr_ = returnValue.ptr_->next;
        }
        return returnValue;
    }

    T* operator->() {
        return &(ptr_->data);
    }

    bool operator==(const Iterator& second) const {
        return ptr_ == second.ptr_;
    }

    bool operator!=(const Iterator& second) const {
        return !(this->operator==(second));
    }

    Node<T>* node() { return ptr_; };
};