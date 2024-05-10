#pragma once
#include <iostream>
#include <iterator>
#include <functional>

template <typename T>
struct Node {
    T data;
    Node* prev{ nullptr };
    Node* next{ nullptr };
    Node(const T& e) : data{ e }, next{ nullptr }, prev{ nullptr } {};
    Node(T&& e) : data{ e }, next{ nullptr }, prev{ nullptr } {};
};

template <typename T>
class DoubleLinkedList {
private:
    Node<T>* head_;
    Node<T>* tail_;
    size_t size_;

    void dealoc() {
        if (!size_) {
            return;
        }
        if (size_ == 1) {
            delete head_;
        }
        else {
            Node<T>* temp;
            while (head_ != tail_) {
                temp = head_;
                head_ = head_->next;
                delete temp;
            }
            delete head_;
        }
        head_ = tail_ = nullptr;
        size_ = 0;
        return;
    }

    void copyList(const DoubleLinkedList& second) {
        for (const T& e : second) {
            push_back(e);
        }
        return;
    }

    friend std::ostream& operator<<(std::ostream& outputStream, const DoubleLinkedList& list) {
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

    DoubleLinkedList() : head_{ nullptr }, tail_{ nullptr }, size_{ 0 } {};

    DoubleLinkedList(const DoubleLinkedList& second) : head_{ nullptr }, tail_{ nullptr }, size_{ 0 } {
        copyList(second);
        return;
    }

    DoubleLinkedList(DoubleLinkedList&& second) : head_{ std::move(second.head_) }, tail_{ std::move(second.tail_) }, size_{ second.size_ } {
        second.head_ = second.tail_ = nullptr;
        second.size_ = 0;
        return;
    }

    DoubleLinkedList& operator=(const DoubleLinkedList& second) {
        if (this->head_ != second.head_) {
            dealoc();
            copyList(second);
        }
        return *this;
    }

    DoubleLinkedList& operator=(DoubleLinkedList&& second) {
        if (this->head_ != second.head_) {
            dealoc();
            head_ = std::move(second.head_);
            tail_ = std::move(second.tail_);
            size_ = second.size_;
            second.head_ = second.tail_ = nullptr;
            second.size_ = 0;
        }
        return *this;
    }

    ~DoubleLinkedList() {
        dealoc();
        return;
    }

    DoubleLinkedList& push_back(const T& e) {
        if (!size_) {
            head_ = new Node<T>(e);
            tail_ = head_;
        }
        else {
            tail_->next = new Node<T>(e);
            tail_->next->prev = tail_;
            tail_ = tail_->next;
        }
        ++size_;
        return *this;
    }

    DoubleLinkedList& push_back(T&& e) {
        if (!size_) {
            head_ = new Node<T>(std::move(e));
            tail_ = head_;
        }
        else {
            tail_->next = new Node<T>(std::move(e));
            tail_->next->prev = tail_;
            tail_ = tail_->next;
        }
        ++size_;
        return *this;
    }

    DoubleLinkedList& push_front(const T& e) {
        if (!size_) {
            head_ = new Node<T>(e);
            tail_ = head_;
        }
        else {
            Node<T>* temp = head_;
            head_ = new Node<T>(e);
            head_->next = temp;
            temp->prev = head_;
        }
        ++size_;
        return *this;
    }

    DoubleLinkedList& push_front(T&& e) {
        if (!size_) {
            head_ = new Node<T>(std::move(e));
            tail_ = head_;
        }
        else {
            Node<T>* temp = head_;
            head_ = new Node<T>(std::move(e));
            head_->next = temp;
            temp->prev = head_;
        }
        ++size_;
        return *this;
    }

    DoubleLinkedList& pop_back() {
        if (!size_) {
            throw std::out_of_range("List is empty!");
        }
        if (size_ == 1) {
            delete head_;
            head_ = tail_ = nullptr;
        }
        else {
            Node<T>* temp = tail_;
            tail_ = tail_->prev;
            tail_->next = nullptr;
            delete temp;

        }
        --size_;
        return *this;
    }

    DoubleLinkedList& pop_front() {
        if (!size_) {
            throw std::out_of_range("List is empty!");
        }
        if (size_ == 1) {
            delete head_;
            head_ = tail_ = nullptr;
        }
        else {
            Node<T>* temp = head_;
            head_ = head_->next;
            head_->prev = nullptr;
            delete temp;
        }
        --size_;
        return *this;
    }

    bool empty() const { return !size_; };

    size_t size() const { return size_; };

    T& front() {
        if (!size_) {
            throw std::out_of_range("List is empty!");
        }
        return head_->data;
    }

    T& back() {
        if (!size_) {
            throw std::out_of_range("List is empty!");
        }
        return tail_->data;
    }

    Iterator begin() const { return Iterator{ head_ }; };

    Iterator end() const { return Iterator{ nullptr }; };

    const Iterator cbegin() const { return Iterator{ head_ }; };

    const Iterator cend() const { return Iterator{ nullptr }; };

    Iterator rbegin() const { return Iterator{ tail_ }; };

    Iterator rend() const { return Iterator{ nullptr }; };

    const Iterator rcbegin() const { return Iterator{ tail_ }; };

    const Iterator rcend() const { return Iterator{ nullptr }; };

    void clear() {
        dealoc();
        return;
    }

    Iterator insert(Iterator pos, const T& e) {
        if (pos == Iterator{ head_ }) {
            push_front(e);
            return Iterator{ head_ };
        }
        if (pos == Iterator{ nullptr }) {
            push_back(e);
            return Iterator{ tail_ };
        }
        Node<T>* temp = pos.node()->next;
        pos.node()->next = new Node<T>(e);
        pos.node()->next->prev = pos.node();
        pos.node()->next->next = temp;
        temp->prev = pos.node()->next;
        ++size_;
        return Iterator{ ++pos };
    }

    Iterator erase(Iterator pos) {
        if (pos == Iterator{ nullptr }) {
            throw std::out_of_range("Iterator out of range!");
        }
        if (pos == Iterator{ head_ }) {
            pop_front();
            return Iterator{ head_ };
        }
        if (pos == Iterator{ tail_ }) {
            pop_back();
            return Iterator{ nullptr };
        }
        Iterator returnIt = pos + 1;
        Node<T>* temp = pos.node();
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
        --size_;
        return returnIt;
    }

    Iterator erase(Iterator beginIt, Iterator endIt) {
        Iterator before = beginIt - 1;
        while (beginIt != endIt) {
            delete beginIt.node();
            --size_;
            ++beginIt;
        }
        before.node()->next = endIt.node();
        return endIt;
    }

    void remove_if(std::function<bool(const T&)>&& p) {
        if (!size_) {
            return;
        }
        Iterator beginIt = Iterator{ head_ };
        Iterator nullIt = Iterator{ nullptr };
        while (beginIt != nullIt) {
            if (p(beginIt.node()->data)) {
                beginIt = erase(beginIt);
            }
            else {
                ++beginIt;
            }
        }
        return;
    }

    void reverse() {
        if (size_ < 2) {
            return;
        }
        Iterator beginIt = Iterator{ head_ };
        Iterator endIt = Iterator{ tail_ };
        while (beginIt != endIt) {
            std::swap(beginIt.node()->data, endIt.node()->data);
            if (beginIt + 1 == endIt) {
                break;
            }
            ++beginIt;
            --endIt;
        }
        return;
    }

    Iterator find(const T& e) const {
        Iterator beginIt = Iterator{ head_ };
        Iterator nullIt = Iterator{ nullptr };
        while (beginIt != nullIt) {
            if (beginIt.node()->data == e) {
                return beginIt;
            }
            ++beginIt;
        }
        return beginIt;
    }

};

template <typename T>
class DoubleLinkedList<T>::Iterator : public std::iterator<std::bidirectional_iterator_tag, T> {
private:
    Node<T>* ptr_;

public:
    Iterator() : ptr_{ nullptr } {};

    Iterator(const Iterator& second) : ptr_{ second.ptr_ } {};

    Iterator(Iterator&& second) : ptr_{ std::move(second.ptr_) } {
        second.ptr_ = nullptr;
        return;
    }

    Iterator(Node<T>* ptr) : ptr_{ ptr } {};

    Iterator& operator=(const Iterator& second) {
        ptr_ = second.ptr_;
        return *this;
    }

    Iterator& operator=(Iterator&& second) {
        ptr_ = std::move(second.ptr_);
        second.ptr_ = nullptr;
        return *this;
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

    Iterator operator+(size_t n) {
        Iterator returnValue{ ptr_ };
        for (size_t i = 0; i < n; ++i) {
            ++returnValue;
        }
        return returnValue;
    }

    Iterator& operator--() {
        ptr_ = ptr_->prev;
        return *this;
    }

    Iterator operator--(int) {
        Iterator returnValue{ ptr_ };
        ptr_ = ptr_->prev;
        return returnValue;
    }

    Iterator operator-(size_t n) {
        Iterator returnValue{ ptr_ };
        for (size_t i = 0; i < n; ++i) {
            --returnValue;
        }
        return returnValue;
    }

    bool operator==(const Iterator& second) const { return ptr_ == second.ptr_; };

    bool operator!=(const Iterator& second) const { return ptr_ != second.ptr_; };

    T* operator->() const {
        return &(ptr_->data);
    }

    T& operator*() const {
        return ptr_->data;
    }

    Node<T>* node() const { return ptr_; };

};
