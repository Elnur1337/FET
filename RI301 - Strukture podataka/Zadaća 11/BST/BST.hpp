#pragma once
#include <functional>

template <typename T>
class BST {
private:
	struct Node {
		T data;
		Node* left;
		Node* right;

		template <typename U>
		Node(U&& e) : data{ std::forward<U>(e) }, left{ nullptr }, right{ nullptr } {};
	};

	Node* root_;
	size_t size_;

	template <typename U>
	BST& add(Node*& root, U&& e) {
		if (root == nullptr) {
			root = new Node(std::forward<U>(e));
			++size_;
			return *this;
		}
		if (root->data == e) {
			return *this;
		}
		if (root->data < e) {
			add(root->right, std::forward<U>(e));
		}
		else {
			add(root->left, std::forward<U>(e));
		}
		return *this;
	}

	void preorder(Node*& root, const std::function<void(T&)>& f) {
		if (!root) {
			return;
		}
		f(root->data);
		preorder(root->left, f);
		preorder(root->right, f);
		return;
	}

	void inorder(Node*& root, const std::function<void(T&)>& f) {
		if (!root) {
			return;
		}
		inorder(root->left, f);
		f(root->data);
		inorder(root->right, f);
		return;
	}

	void postorder(Node*& root, const std::function<void(T&)>& f) {
		if (!root) {
			return;
		}
		postorder(root->left, f);
		postorder(root->right, f);
		f(root->data);
		return;
	}

	Node* copyBST(const Node* root) {
		if (!root) {
			return nullptr;
		}
		Node* newNode = new Node(root->data);
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

	bool search(Node* root, const T& e) const {
		if (!root) {
			return false;
		}
		if (root->data == e) {
			return true;
		}
		if (root->data < e) {
			return search(root->right, e);
		}
		return search(root->left, e);
	}

	template <typename U>
	void replace(Node* root, const T& e, U&& v) {
		if (!root) {
			return;
		}
		if (root->data == e) {
			root->data = std::forward<U>(v);
			return;
		}
		if (root->data < e) {
			return replace(root->right, e, std::forward<U>(v));
		}
		return replace(root->right, e, std::forward<U>(v));
	}

	BST& remove(Node*& root, Node* parrent, short childNumber, const T& e) {
		/*
		Child number:
		Left child = 1
		Right child = 2
		*/
		if (!root) {
			return *this;
		}
		if (root->data < e) {
			remove(root->right, root, 2, e);
		}
		else if (root->data > e) {
			remove(root->left, root, 1, e);
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
				return *this;
			}
			if (root->left && !root->right) {
				Node* temp = root->left;
				root->data = std::move(temp->data);
				root->left = temp->left;
				root->right = temp->right;
				delete temp;
				--size_;
				return *this;
			}
			if (!root->left && root->right) {
				Node* temp = root->right;
				root->data = std::move(temp->data);
				root->left = temp->left;
				root->right = temp->right;
				delete temp;
				--size_;
				return *this;
			}
			Node* minRight{ root->right };
			while (minRight->left) {
				minRight = minRight->left;
			}
			std::swap(root->data, minRight->data);
			return remove(root->right, root, 2, e);
		}
	}

public:
	BST() : root_{ nullptr }, size_{ 0 } {};

	BST(const BST& second) : root_{ copyBST(second.root_) }, size_{ second.size_ } {};

	BST(BST&& second) : root_{ second.root_ }, size_{ second.size_ } {
		second.root_ = nullptr;
		second.size_ = 0;
		return;
	}

	BST& operator=(const BST& second) {
		if (this->root_ == second.root_) {
			return *this;
		}
		deleteBST(root_);
		root_ = copyBST(second.root_);
		return *this;
	}

	BST& operator=(BST&& second) {
		if (this->root_ == second.root_) {
			return *this;
		}
		deleteBST(root_);
		root_ = second.root_;
		size_ = second.size_;
		second.root_ = nullptr;
		second.size_ = 0;
		return *this;
	}

	~BST() { deleteBST(root_); };

	template <typename U>
	BST& add(U&& e) { return add(root_, std::forward<U>(e)); };

	void preorder(const std::function<void(T&)>& f) { preorder(root_, f); };

	void inorder(const std::function<void(T&)>& f) { inorder(root_, f); };

	void postorder(const std::function<void(T&)>& f) { postorder(root_, f); };

	inline size_t size() const { return size_; };

	bool search(const T& e) const { return search(root_, e); };
	
	bool loopSearch(const T& e) const {
		Node* root{ root_ };
		while (root != nullptr) {
			if (root->data == e) {
				return true;
			}
			if (root->data < e) {
				root = root->right;
			}
			else {
				root = root->left;
			}
		}
		return false;
	}

	BST& remove(const T& e) { return remove(root_, nullptr, 0, e); };

	template <typename U>
	void replace(const T& e, U&& v) { return replace(root_, e, std::forward<U>(v)); };
};