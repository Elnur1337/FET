#include <stdexcept>

template <typename T>
struct Node {
	T data;
	Node* next;
	Node(const T& e) : data{ e }, next{ nullptr } {};
	Node(T&& e) : data{ std::move(e) }, next{ nullptr } {};
};

template <typename T>
class Stack {
private:
	Node<T>* head_;
	size_t size_;

	void dealoc() {
		if (!size_) {
			return;
		}
		while (head_->next != nullptr) {
			Node<T>* temp = head_;
			head_ = head_->next;
			delete temp;
		}
		delete head_;
		head_ = nullptr;
		size_ = 0;
		return;
	}

	void copyStackList(const Stack& second) {
		Node<T>* temp1 = head_;
		Node<T>* temp2 = second.head_;
		while (temp2 != nullptr) {
			if (temp1 == nullptr) {
				head_ = new Node<T>(temp2->data);
				temp1 = head_;
			}
			else {
				temp1 = temp1->next = new Node<T>(temp2->data);
			}
			temp2 = temp2->next;
		}
		size_ = second.size_;
		return;
	}
public:
	Stack() : head_{ nullptr }, size_{ 0 } {};

	Stack(const Stack& second) {
		copyStackList(second);
		return;
	}

	Stack(Stack&& second) : head_{ second.head_ }, size_{ second.size_ } {
		second.head_ = nullptr;
		second.size_ = 0;
		return;
	}

	~Stack() {
		dealoc();
		return;
	}

	Stack& operator=(const Stack& second) {
		dealoc();
		copyStackList(second);
		return *this;
	}
	
	Stack& operator=(Stack&& second) {
		dealoc();
		head_ = second.head_;
		size_ = second.size_;
		second.head_ = nullptr;
		second.size_ = 0;
		return *this;
	}
	
	template <typename U>
	Stack& push(U&& e) {
		if (head_ == nullptr) {
			head_ = new Node<T>(std::forward<U>(e));
		}
		else {
			Node<T>* temp = head_;
			head_ = new Node<T>(std::forward<U>(e));
			head_->next = temp;
		}
		++size_;
		return *this;
	}
	
	T pop() {
		if (!size_) {
			throw std::out_of_range("Stack is empty!");
		}
		T returnValue = head_->data;
		Node<T>* temp = head_;
		head_ = head_->next;
		delete temp;
		--size_;
		return returnValue;
	}

	T& top() const {
		if (!size_) {
			throw std::out_of_range("Stack is empty!");
		}
		return head_->data;
	}

	inline bool empty() const { return !size_; };

	inline size_t size() const { return size_; };

	void clear() {
		dealoc();
		return;
	}

	void resize(size_t newSize, const T& defaultValue = 0) {
		if (newSize == size_) {
			return;
		}
		if (newSize < size_) {
			while (size_ != newSize) {
				pop();
			}
			return;
		}
		while (size_ != newSize) {
			push(defaultValue);
		}
		return;
	}

	bool operator==(const Stack& second) const {
		if (size_ != second.size_) {
			return false;
		}
		if (size_ == 0 && second.size_ == 0) {
			return true;
		}
		Node<T>* temp1 = head_;
		Node<T>* temp2 = second.head_;
		while (temp1 != nullptr) {
			if (temp1->data != temp2->data) {
				return false;
			}
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
		return true;
	}

	bool operator!=(const Stack& second) const {
		return !(operator==(second));
	}
};
