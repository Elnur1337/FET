#pragma once
#include <stdexcept>

template <typename K, typename V>
class Map {
private:
	struct Node {
		K key;
		V value;
		Node* left;
		Node* right;

		template <typename U, typename T>
		Node(U&& k, T&& v) : key{ std::forward<U>(k) }, value{ std::forward<T>(v) }, left{ nullptr }, right{ nullptr } {};

		template <typename U>
		Node(U&& k) : key{ std::forward<U>(k) }, left{ nullptr }, right{ nullptr } {};

		Node(const Node& second) : key{ second.key }, value{ second.value }, left{ nullptr }, right{ nullptr } {};
	};

	Node* root_;
	size_t size_;

	Node* copyBST(const Node* root) {
		if (!root) {
			return nullptr;
		}
		Node* newNode = new Node(*root);
		newNode->left = copyBST(root->left);
		newNode->right = copyBST(root->right);
		return newNode;
	}

	void deleteBST(Node*& root) {
		if (!root) {
			return;
		}
		deleteBST(root->left);
		deleteBST(root->right);
		delete root;
		root = nullptr;
		return;
	}

	template <typename U>
	V& at(Node*& root, U&& k) {
		if (!root) {
			throw std::invalid_argument("Element with that key not found!");
		}
		if (root->key == std::forward<U>(k)) {
			return root->value;
		}
		if (root->key < std::forward<U>(k)) {
			return at(root->right, std::forward<U>(k));
		}
		return at(root->left, std::forward<U>(k));
	}

	template <typename U>
	const V& at(Node*& root, U&& k) const {
		if (!root) {
			throw std::invalid_argument("Element with that key not found!");
		}
		if (root->key == std::forward<U>(k)) {
			return root->value;
		}
		if (root->key < std::forward<U>(k)) {
			return at(root->right, std::forward<U>(k));
		}
		return at(root->left, std::forward<U>(k));
	}

	template <typename U>
	V* find(Node*& root, U&& k) {
		if (!root) {
			return nullptr;
		}
		if (root->key == std::forward<U>(k)) {
			return &(root->value);
		}
		if (root->key < std::forward<U>(k)) {
			return find(root->right, std::forward<U>(k));
		}
		return find(root->left, std::forward<U>(k));
	}

	template <typename U>
	const V* find(Node*& root, U&& k) const {
		if (!root) {
			return nullptr;
		}
		if (root->key == std::forward<U>(k)) {
			return &(root->value);
		}
		if (root->key < std::forward<U>(k)) {
			return find(root->right, std::forward<U>(k));
		}
		return find(root->left, std::forward<U>(k));
	}

	template <typename U>
	V& squareBrackets(Node*& root, U&& k) {
		if (!root) {
			root = new Node(std::forward<U>(k));
			++size_;
			return root->value;
		}
		if (root->key == std::forward<U>(k)) {
			return root->value;
		}
		if (root->key < std::forward<U>(k)) {
			return squareBrackets(root->right, std::forward<U>(k));
		}
		return squareBrackets(root->left, std::forward<U>(k));
	}

	template <typename U, typename T>
	Map& insert(Node*& root, U&& k, T&& e) {
		if (!root) {
			root = new Node(std::forward<U>(k), std::forward<T>(e));
			++size_;
			return *this;
		}
		if (root->key == std::forward<U>(k)) {
			throw std::invalid_argument("Elements with that key already exists!");
		}
		if (root->key < std::forward<U>(k)) {
			return insert(root->right, std::forward<U>(k), std::forward<T>(e));
		}
		return insert(root->left, std::forward<U>(k), std::forward<T>(e));
	}

	template <typename U>
	bool erase(Node*& root, Node* parrent, short childNumber, U&& k) {
		/*
		Child number:
		Left child = 1
		Right child = 2
		*/
		if (!root) {
			return false;
		}
		if (root->key < std::forward<U>(k)) {
			erase(root->right, root, 2, std::forward<U>(k));
		}
		else if (root->key > std::forward<U>(k)) {
			erase(root->left, root, 1, std::forward<U>(k));
		}
		else {
			if (!root->left && !root->right) {
				delete root;
				if (parrent) {
					if (childNumber == 1) {
						parrent->left = nullptr;
					}
					else if (childNumber == 2) {
						parrent->right = nullptr;
					}
				}
				--size_;
				return true;
			}
			if (root->left && !root->right) {
				Node* temp = root->left;
				root->key = std::move(temp->key);
				root->value = std::move(temp->value);
				root->left = temp->left;
				root->right = temp->right;
				delete temp;
				--size_;
				return true;
			}
			if (!root->left && root->right) {
				Node* temp = root->right;
				root->key = std::move(temp->key);
				root->value = std::move(temp->value);
				root->left = temp->left;
				root->right = temp->right;
				delete temp;
				--size_;
				return true;
			}
			Node* minRight{ root->right };
			while (minRight->left) {
				minRight = minRight->left;
			}
			std::swap(root->key, minRight->key);
			std::swap(root->value, minRight->value);
			return erase(root->right, root, 2, std::forward<U>(k));
		}
	}

public:
	Map() : root_{ nullptr }, size_{ 0 } {};

	Map(const Map& second) : root_{ copyBST(second.root_) }, size_{ second.size_ } {};

	Map(Map&& second) : root_{ second.root_ }, size_{ second.size_ } {
		second.root_ = nullptr;
		second.size_ = 0;
		return;
	}

	~Map() {
		deleteBST(root_);
		return;
	}

	Map& operator=(const Map& second) {
		if (*this == second) {
			return *this;
		}
		deleteBST(root_);
		root_ = copyBST(second.root_);
		size_ = second.size_;
		return *this;
	}

	Map& operator=(Map&& second) {
		if (*this == second) {
			return *this;
		}
		deleteBST(root_);
		root_ = second.root_;
		size_ = second.size_;
		second.root_ = nullptr;
		second.size_ = 0;
		return *this;
	}

	template <typename U>
	V& at(U&& k) {
		return at(root_, std::forward<U>(k));
	}
	
	template <typename U>
	const V& at(U&& k) const {
		return at(root_, std::forward<U>(k));
	}

	template <typename U>
	V* find(U&& k) {
		return find(root_, std::forward<U>(k));
	}

	template <typename U>
	const V* find(U&& k) const {
		return find(root_, std::forward<U>(k));
	}

	template <typename U>
	V& operator[](U&& k) {
		return squareBrackets(root_, std::forward<U>(k));
	}

	template <typename U, typename T>
	Map& insert(U&& k, T&& e) {
		return insert(root_, std::forward<U>(k), std::forward<T>(e));
	}

	template <typename U>
	bool erase(U&& k) {
		return erase(root_, nullptr, 0, std::forward<U>(k));
	}

	void clear() {
		deleteBST(root_);
		size_ = 0;
		return;
	}

	inline bool empty() const { return !size_; };

	inline size_t size() const { return size_; };
};