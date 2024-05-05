#pragma once
#include <iostream>
#include <stdexcept>
#include <functional>

template <typename T>
struct Node {
    T data;
    Node* next;

    Node(const T& e) : data{ e }, next{ nullptr } {};

    Node(T&& e) : data{ std::move(e) }, next{ nullptr } {};
};

template <typename T>
class SortedSingleLinkedList {
private:
    Node<T>* head_;
    Node<T>* tail_;
    size_t size_;

    void push_back(const T& e) {
        if (!size_) {
            head_ = new Node<T>(e);
            tail_ = head_;
        }
        else {
            tail_->next = new Node<T>(e);
            tail_ = tail_->next;
        }
        ++size_;
        return;
    }

    void copyList(const SortedSingleLinkedList& second) {
        dealoc();
        for (const T& e : second) {
            push_back(e);
        }
        return;
    }

    void dealoc() {
        if (!size_) {
            return;
        }
        if (head_ == tail_) {
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

    friend std::ostream& operator<<(std::ostream& outputStream, const SortedSingleLinkedList& list) {
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

    SortedSingleLinkedList() : head_{ nullptr }, tail_{ nullptr }, size_{ 0 } {};

    SortedSingleLinkedList(const SortedSingleLinkedList& second) {
        copyList(second);
        return;
    }

    SortedSingleLinkedList(SortedSingleLinkedList&& second) : head_{ std::move(second.head_) }, tail_{ std::move(second.tail_) }, size_{ second.size_ } {
        second.head_ = second.tail_ = nullptr;
        second.size_ = 0;
        return;
    }

    SortedSingleLinkedList& operator=(const SortedSingleLinkedList& second) {
        dealoc();
        copyList(second);
        return *this;
    }

    SortedSingleLinkedList& operator=(SortedSingleLinkedList&& second) {
        dealoc();
        head_ = std::move(second.head_);
        tail_ = std::move(second.tail_);
        size_ = second.size_;
        second.head_ = second.tail_ = nullptr;
        second.size_ = 0;
        return *this;
    }

    ~SortedSingleLinkedList() {
        dealoc();
        return;
    }

    SortedSingleLinkedList& add(const T& e) {
        if (!size_) {
            head_ = new Node<T>(e);
            tail_ = head_;
        }
        else {
            Iterator curr{ head_ };
            Iterator prev{ nullptr };
            Iterator nullIterator{ nullptr };
            while (curr != nullIterator) {
                if (curr.node()->data > e) {
                    if (prev == nullIterator) {
                        Node<T>* temp = head_;
                        head_ = new Node<T>(e);
                        head_->next = temp;
                    }
                    else {
                        prev.node()->next = new Node<T>(e);
                        prev.node()->next->next = curr.node();
                    }
                    break;
                }
                ++curr;
                if (prev == nullIterator) {
                    prev = head_;
                }
                else {
                    ++prev;
                }
            }
            if (curr == nullIterator) {
                tail_->next = new Node<T>(e);
                tail_ = tail_->next;
            }
        }
        ++size_;
        return *this;
    }

    SortedSingleLinkedList& add(T&& e) {
        if (!size_) {
            head_ = new Node<T>(std::move(e));
            tail_ = head_;
        }
        else {
            Iterator curr{ head_ };
            Iterator prev{ nullptr };
            Iterator nullIterator{ nullptr };
            while (curr != nullIterator) {
                if (curr.node()->data > e) {
                    if (prev == nullIterator) {
                        Node<T>* temp = head_;
                        head_ = new Node<T>(std::move(e));
                        head_->next = temp;
                    }
                    else {
                        prev.node()->next = new Node<T>(std::move(e));
                        prev.node()->next->next = curr.node();
                    }
                    break;
                }
                ++curr;
                if (prev == nullIterator) {
                    prev = head_;
                }
                else {
                    ++prev;
                }
            }
            if (curr == nullIterator) {
                tail_->next = new Node<T>(std::move(e));
                tail_ = tail_->next;
            }
        }
        ++size_;
        return *this;
    }

    SortedSingleLinkedList& pop_front() {
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
            delete temp;
        }
        --size_;
        return *this;
    }

    SortedSingleLinkedList& pop_back() {
        if (!size_) {
            throw std::out_of_range("List is empty!");
        }
        if (size_ == 1) {
            delete head_;
            head_ = tail_ = nullptr;
        }
        else {
            Node<T>* temp = head_;
            while (temp->next != tail_) {
                temp = temp->next;
            }
            delete tail_;
            tail_ = temp;
            tail_->next = nullptr;
        }
        --size_;
        return *this;
    }

    bool empty() const { return size_ == 0; };

    size_t size() const { return size_; };

    SortedSingleLinkedList& extend(const SortedSingleLinkedList& second) {
        for (const T& e : second) {
            add(e);
        }
        return *this;
    }

    SortedSingleLinkedList& extend(SortedSingleLinkedList&& second) {
        for (const T& e : second) {
            add(std::move(e));
        }
        second.head_ = second.tail_ = nullptr;
        second.size_ = 0;
        return *this;
    }

    Iterator find(const T& e) const {
        Iterator it{ head_ };
        while (it != end()) {
            if (*it == e) {
                break;
            }
            ++it;
        }
        return it;
    }

    Iterator erase(Iterator pos) {
        if (!size_) {
            throw std::invalid_argument("List is empty!");
        }
        if (pos == begin()) {
            pop_front();
            return begin();
        }
        if (pos == rbegin()) {
            pop_back();
            return Iterator{ nullptr };
        }
        Iterator curr{ head_->next };
        Iterator prev{ head_ };
        while (curr != pos) {
            if (curr == Iterator{ nullptr }) {
                throw std::invalid_argument("Iterator not in list!");
            }
            ++curr;
            ++prev;
        }
        prev.node()->next = curr.node()->next;
        delete curr.node();
        return ++prev;
    }

    Iterator begin() const { return Iterator{ head_ }; };

    Iterator end() const { return Iterator{ nullptr }; };

    const Iterator cbegin() const { return Iterator{ head_ }; };

    const Iterator cend() const { return Iterator{ nullptr }; };

    Iterator rbegin() const { return Iterator{ tail_ }; };

    const Iterator rcbegin() const { return Iterator{ tail_ }; };

    Node<T>* head() const { return head_; };

    Node<T>* tail() const { return tail_; };

    T& front() { return head_->data; };

    T& back() { return tail_->data; };

    Iterator erase(Iterator beginIt, Iterator endIt) {
        if (!size_) {
            throw std::invalid_argument("List is empty!");
        }
        Iterator curr{ head_ };
        Iterator prev{ nullptr };
        Iterator nullIterator{ nullptr };
        while (curr != beginIt) {
            if (curr == end()) {
                throw std::invalid_argument("Iterator not in list!");
            }
            ++curr;
            if (prev == nullIterator) {
                prev = Iterator{ head_ };
            }
            else {
                ++prev;
            }
        }
        Iterator temp;
        while (curr != endIt) {
            if (curr == nullIterator) {
                break;
            }
            temp = curr;
            ++curr;
            delete temp.node();
            --size_;
        }
        if (prev == nullIterator) {
            head_ = curr.node();
        }
        else {
            prev.node()->next = curr.node();
        }
        if (endIt == nullIterator) {
            tail_ = prev.node();
        }
        if (prev == nullIterator) {
            return Iterator{ head_ };
        }
        return Iterator{ prev.node()->next };
    }

    void clear() {
        dealoc();
        return;
    }

    void remove_if(std::function<bool(const T&)>&& p) {
        if (!size_) {
            return;
        }
        Node<T>* curr = head_;
        Node<T>* prev = nullptr;
        while (curr != nullptr) {
            if (p(curr->data)) {
                if (prev == nullptr) {
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
        if (prev != nullptr) {
            tail_ = prev;
        }
        return;
    }
};

template <typename T>
class SortedSingleLinkedList<T>::Iterator : public std::iterator<std::forward_iterator_tag, T> {
private:
    Node<T>* ptr_;

public:
    Iterator() : ptr_{ nullptr } {};

    Iterator(const Iterator& second) : ptr_{ second.ptr_ } {};

    Iterator(Iterator&& second) : ptr_{ second.ptr_ } {
        second.ptr_ = nullptr;
        return;
    }

    Iterator(Node<T>* ptr) : ptr_{ ptr } {};

    ~Iterator() {
        ptr_ = nullptr;
        return;
    }

    Iterator& operator=(const Iterator& second) {
        ptr_ = second.ptr_;
        return *this;
    }

    Iterator& operator=(Iterator&& second) {
        ptr_ = second.ptr_;
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

    bool operator==(const Iterator& second) {
        return ptr_ == second.ptr_;
    }

    bool operator!=(const Iterator& second) {
        return ptr_ != second.ptr_;
    }

    Node<T>* node() {
        return ptr_;
    }
};