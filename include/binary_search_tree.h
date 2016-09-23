#pragma once
#include <iostream>
#include <fstream>
#include <initializer_list>

template <typename T>
class BinarySearchTree;



template <typename T>
std::ofstream & operator << (std::ofstream & out, const BinarySearchTree<T> & tree) {
	
	tree.PreorderPrint(out, tree.GetRoot());
    return out;
};




template <typename T>
std::ostream & operator << (std::ostream & out, const BinarySearchTree<T> & tree) {

	tree.PreorderPrint(out, tree.GetRoot());
	return out;
};





template <typename T>
std::istream & operator >> (std::istream & in, BinarySearchTree<T> & tree) {
	T value;
	int size;
	std::cout << "Size: ";
	in >> size;

	for (int i = 0; i < size; i++)
	{
		in >> value;
		tree.insert(value);
	}

	return in;
};

template <typename T>
class BinarySearchTree {

private:
       struct Node;
	Node * root_;
	size_t size_;

	struct Node {
		Node(T value) : value_(value), left_(nullptr), right_(nullptr) {};
		~Node() {
			delete left_;
			delete right_;

		};
		T value_;
		Node * left_;
		Node * right_;
	};

public: 
        Node * root_;
	size_t size_;
	BinarySearchTree()
	{
		size_ = 0;
		root_ = nullptr;
	};

	BinarySearchTree(const std::initializer_list<T> & list)
	{
		size_ = 0;
		root_ = nullptr;
		for (auto it = list.begin(); it != list.end(); ++it)
		{
			insert(*it);
		}
	};


	Node* GetRoot() const
	{
		return root_;
	}

	void PreorderPrint(std::ostream & str, Node* ThisNode) const noexcept
	{
		if (ThisNode == NULL) {

			return;
		}
		str << ThisNode->value_ << " ";
		PreorderPrint(str, ThisNode->left_);
		PreorderPrint(str, ThisNode->right_);
	}

	auto size() const noexcept->size_t {

		return size_;
	};
	
	
	auto insert(const T & value) const noexcept -> bool {

		Node* thisNode = root_;
		Node* myNode = nullptr;
		if (root_ == nullptr)
		{
			root_ = new Node(value);
			size_++;
			return true;
		}
		while (thisNode)
		{
			myNode = thisNode;
			if (value == myNode->value_)
			{
				return false;
			}
			else if (value < myNode->value_)
			{
				thisNode = myNode->left_;
			}
			else if (value > myNode->value_)
			{
				thisNode = myNode->right_;
			}
		}
		if (value < myNode->value_)
		{
			myNode->left_ = new Node(value);
		}
		else
		{
			myNode->right_ = new Node(value);
		};
		size_++;
		return true;
	};


	auto find(const T & value) const noexcept -> const T *{

		Node* thisNode = root_;
	if (!root_)

	{
		return nullptr;
	};

	while (thisNode)
	 {
		if (value < thisNode->value_)
		{
			thisNode = thisNode->left_;
		}
		else if (value > thisNode->value_)
		{
			thisNode = thisNode->right_;
		}
		else if (value == thisNode->value_)
		{
			return &thisNode->value_;
		}

		return nullptr;
	 }
	}

	~BinarySearchTree() {

	    delete root_;
		size_ = 0;
	}
};

