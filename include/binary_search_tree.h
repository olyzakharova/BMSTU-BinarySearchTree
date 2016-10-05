#pragma once
#include <iostream>
#include <fstream>
#include <initializer_list>
#include <memory> //для умных указателей
using namespace std;

template <typename T>
class BinarySearchTree;


template <typename T>
std::ofstream & operator << (std::ofstream & out, const BinarySearchTree<T> & tree) {

	tree.PreorderPrint(out, tree.GetRoot());
	return out;
};

template <typename T>
std::ostream & operator << (std::ostream & out, const BinarySearchTree<T> & tree) {

	tree.InorderPrint(out, tree.GetRoot());
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
std::ifstream & operator << (std::ifstream & out, const BinarySearchTree<T> & tree)
{
	tree.PreorderPrint(out, tree.GetRoot());
	return out;
};

template <typename T>
class BinarySearchTree {

private:
	struct Node;
	//Node * root_;
	unique_ptr <Node> root_;
	size_t size_;

	struct Node {
		Node(T value) : value_(value), left_(nullptr), right_(nullptr) {};
		~Node() {
			delete left_;
			delete right_;

		};
		T value_;
		//Node * left_;
		//Node * right_;
		unique_ptr<Node> left_;
		unique_ptr<Node> right_;
	};

public:


	BinarySearchTree() : root_(nullptr), size_(0) {}

	BinarySearchTree(const std::initializer_list<T> & list) : size_(0), root_(nullptr)
	{
		for (auto it = list.begin(); it != list.end(); ++it)
		{
			insert(*it);
		}
	};


	BinarySearchTree(const BinarySearchTree& tree) : size_(tree.size_), root_(nullptr)//конструктор копирования
	{
		root_ = copy(tree.root_);
	};

	//BinarySearchTree(BinarySearchTree&& tree)= default {};// конструктор перемещения


	BinarySearchTree(BinarySearchTree&& tree) : size_(tree.size_), root_(std::move(tree.root_))// конструктор перемещения
	{
		
	};

	

	Node* GetRoot() const
	{
		return root_;
	}


	//void PreorderPrint(std::ostream & str, Node* thisNode) const noexcept // прямой
	void PreorderPrint(std::ostream & str, unique_ptr<Node> thisNode) const noexcept // прямой
	{
		if (!thisNode)
		{

			return;
		}
		str << thisNode->value_ << " ";
		PreorderPrint(str, thisNode->left_);
		PreorderPrint(str, thisNode->right_);
	}

	//void InorderPrint(std::ostream & str, Node* thisNode) const noexcept // симметричный 
	void InorderPrint(std::ostream & str, unique_ptr<Node> thisNode) const noexcept // симметричный
	
	{
		if (!thisNode) 
		{

			return;
		}

		InorderPrint(str, thisNode->left_);
		str << thisNode->value_ << " ";
		InorderPrint(str, thisNode->right_);

	}

	auto size() const noexcept->size_t
	{

		return size_;
	};


	auto insert(const T & value) noexcept -> bool {

		//Node* thisNode = root_;
		//Node* myNode = nullptr;

		unique_ptr<Node> thisNode = root_.get();
		unique_ptr<Node> myNode = nullptr;

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


	auto find(const T & value) const noexcept -> const T *
	{

		//Node* thisNode = root_;
		unique_ptr<Node> thisNode = root_.get();
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

		
		//auto comparison(const Node * firstnode_, const Node * secondnode_) const -> bool
		auto comparison(const unique_ptr<Node> firstnode_, const unique_ptr<Node> secondnode_) const -> bool
	{

		if (firstnode_ == nullptr && secondnode_ == nullptr)
		{
			return(true);

		}

		else if (firstnode_ != nullptr && secondnode_ != nullptr)
		{
			return(
				comparison(firstnode_->left_, secondnode_->left_) &&
				comparison(firstnode_->right_, secondnode_->right_)
				);
		}
		else return(false);
	}

	auto remove(const T value, unique_ptr<Node> node) noexcept-> bool   // удаление узла,в котором находится объект со значением value
	{ 

		if (!node)
			return false;
		
		else 
		{
		 
		}

	
	}



	/*bool BinarySearchTree::remove(int value) {
		if (root == NULL)
			return false;
		else {
			if (root->getValue() == value) {
				BSTNode auxRoot(0);
				auxRoot.setLeftChild(root);
				BSTNode* removedNode = root->remove(value, &auxRoot);
				root = auxRoot.getLeft();
				if (removedNode != NULL) {
					delete removedNode;
					return true;
				}
				else
					return false;
			}
			else {
				BSTNode* removedNode = root->remove(value, NULL);
				if (removedNode != NULL) {
					delete removedNode;
					return true;
				}
				else
					return false;
			}
		}
	}*/

	//static auto copy(Node * tree) -> Node*
	static auto copy(unique_ptr<Node> tree) -> unique_ptr<Node>
	{
		if (!tree)
		{
			return NULL;
		}

		//Node * newnode = new Node(tree->value);
		unique_ptr<Node> newnode =std::make_unique<Node>(tree->value);
		newnode->left_ = copy(tree->left_);
		newnode->right_ = copy(tree->right_);

		return newnode;
	}

	auto operator = (const BinarySearchTree& tree)->BinarySearchTree& //копирования
	{
		if (this == &tree)
			return *this;

		size_ = tree.size_;
		root_ = root_->copy(tree.root_);
		return *this;

	};

	auto operator = (BinarySearchTree&& tree)->BinarySearchTree& //перемещения
	{
		if (this == &tree)
			return *this;

		size_ = tree.size_;
		tree.size_ = 0;

		delete root_;
		root_ = tree.root_;
		tree.root_ = nullptr;
		return *this;
	};


	auto operator == (const BinarySearchTree& tree) const -> bool // сравнение
	{
		if (size_ != tree.size_)
		{
			return false;
		}

		else
		{
			comparison(root_, tree.root_);
		}
	};
	~BinarySearchTree() {

		delete root_;
		size_ = 0;
	}



};
