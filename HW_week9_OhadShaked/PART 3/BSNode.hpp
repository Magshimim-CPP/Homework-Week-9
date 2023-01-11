#pragma once

#include <iostream>
#include <string>

using std::cout;

template <typename T>
class BSNode
{
public:
	BSNode(T data);
	BSNode(const BSNode& other);

	~BSNode();

	void insert(T value);
	BSNode& operator=(const BSNode& other);

	bool isLeaf() const;
	T getData() const;
	int getCount() const;
	BSNode* getLeft() const;
	BSNode* getRight() const;


	bool search(T val) const;

	int getHeight() const;
	int getDepth(const BSNode& root) const;

	void printNodes() const; //for question 1 part C

private:
	T _data;
	BSNode* _left;
	BSNode* _right;

	int _count; //for question 1 part B
	int getCurrNodeDistFromInputNode(const BSNode* node) const; //auxiliary function for getDepth
};


/*
Constructor function for a BSNode object.
Input: T data
Output: none
*/
template <typename T>
BSNode<T>::BSNode(T data)
{
	this->_data = data;
	this->_left = nullptr;
	this->_right = nullptr;
	this->_count = 1;
}

/*
Copy constructor function for a BSNode object.
Input: const BSNode<T>& other
Output: none
*/
template <typename T>
BSNode<T>::BSNode(const BSNode<T>& other)
{
	this->_data = other._data;
	this->_count = other._count;
	if (other._right) //checking if the currently copied node has a son to the right. if it does, creating a new object for the '_right' field of the current node, using *other._right.
	{
		this->_right = new BSNode(*other._right);
	}
	if (other._left) //checking if the currently copied node has a son to the left. if it does, creating a new object for the '_left' field of the current node, using *other._left.
	{
		this->_left = new BSNode(*other._left);
	}
}

/*
Function for operator overloading on '=' to copy 'other's' BSNode values to 'this' BSNode (BSNode<T>&).
Input: const BSNode<T>& other
Output: *this (BSNode<T>&)
*/
template <typename T>
BSNode<T>& BSNode<T>::operator=(const BSNode<T>& other)
{
	this->_data = other._data;
	this->_count = other._count;
	if (other._right) //checking if the currently copied node has a son to the right. if it does, creating a new object for the '_right' field of the current node, using *other._right.
	{
		this->_right = new BSNode(*other._right);
	}
	if (other._left) //checking if the currently copied node has a son to the left. if it does, creating a new object for the '_left' field of the current node, using *other._left.
	{
		this->_left = new BSNode(*other._left);
	}
	return *this;
}

/*
Destructor function for a BSNode object.
Input: none
Output: none
*/
template <typename T>
BSNode<T>::~BSNode()
{
	if (this->_right)
	{
		delete this->_right;
	}
	if (this->_left)
	{
		delete this->_left;
	}
}

/*
Function to insert a given value into the BS tree (or increase it's _count field, if an object with the same value already exsist's).
Input: const T value
Output: none
*/
template <typename T>
void BSNode<T>::insert(const T value)
{
	if (value == this->_data) //checking if the requested value already exist in the current node, if it does, adding 1 to this BSNode object value's _count field.
	{
		this->_count++;
	}

	else if (value > this->_data) //if the requested value is larger then the current BSNode object's value, going to the right.
	{
		if (this->_right == nullptr) //if there is no son to the right, adding the value (in the right spot).
		{
			this->_right = new BSNode(value);
		}
		else //if there is already a son to the right, calling the function again, with the right son's node as 'this'.
		{
			this->_right->insert(value);
		}
	}

	else if (value < this->_data) //if the requested value is smaller then the current BSNode object's value, going to the left.
	{
		if (this->_left == nullptr) //if there is no son to the left, adding the value (in the left spot).
		{
			this->_left = new BSNode(value);
		}
		else //if there is already a son to the left, calling the function again, with the left son's node as 'this'.
		{
			this->_left->insert(value);
		}
	}

}

/*
Const function, that checks if the current BSNode object is a leaf (no sons) (bool).
Input: none
Output: true/false (bool).
*/
template <typename T>
bool BSNode<T>::isLeaf() const
{
	return !(this->_left || this->_right);
}

/*
Const 'get' function that returns the '_left' field of an BSNode object (BSNode<T>*).
Input: none
Output: this->_left (BSNode<T>*).
*/
template <typename T>
BSNode<T>* BSNode<T>::getLeft() const
{
	return this->_left;
}

/*
Const 'get' function that returns the '_right' field of an BSNode object (BSNode<T>*).
Input: none
Output: this->_right (BSNode<T>*).
*/
template <typename T>
BSNode<T>* BSNode<T>::getRight() const
{
	return this->_right;
}

/*
Const 'get' function that returns the '_data' field of an BSNode object (T).
Input: none
Output: this->_data (T).
*/
template <typename T>
T BSNode<T>::getData() const
{
	return this->_data;
}

/*
Const 'get' function that returns the '_count' field of an BSNode object (int).
Input: none
Output: this->_count (int).
*/
template <typename T>
int BSNode<T>::getCount() const
{
	return this->_count;
}

/*
Function to search whether or not a given value already exists in one of the tree nodes (bool).
Input: T val
Output: true/false (bool)
*/
template <typename T>
bool BSNode<T>::search(T val) const
{
	bool exists = false; //setting to false at the start of the function (not found).

	if (this->_data == val) //if the current node's data matches the requested data, a node with this value exist, returning true.
	{
		return true;
	}

	if (this->_left) //if the current BSNode has a son to the left, calling the function again with the left son as 'this'.
	{
		exists = this->_left->search(val);
	}

	if (this->_right && !exists) //if the current BSNode has a son to the right, and a BSNode with the same value wasn't already found, calling the function again with the right son as 'this'.
	{
		exists = this->_right->search(val);
	}

	return exists; //returning the result.
}

/*
Const 'get' function that returns the hight of a tree from the given BSNode (longest route below) (int).
Input: none
Output: the hight of a tree from the given BSNode (int).
*/
template <typename T>
int BSNode<T>::getHeight() const
{
	//setting 2 count variable (for each route option, left/right). setting their starting value to 1 because we are starting from the head.
	int LeftCount = 1;
	int RightCount = 1;

	if (!this->isLeaf()) //checking if the current node is a leaf or not.
	{
		if (this->_right) //if the current node has a son to the right, calling the function again on the right son, and adding the return value to RightCount.
		{
			RightCount += this->_right->getHeight();

		}

		if (this->_left) //if the current node has a son to the left, calling the function again on the left son, and adding the return value to LeftCount.
		{
			LeftCount += this->_left->getHeight();

		}
	}

	return ((LeftCount > RightCount) ? LeftCount : RightCount); //returning the larger count (hight = longest route below the given root)
}

/*
Const 'get' function that returns the depth of a node from the tree's root (int).
Input: const BSNode<T>& root
Output: the depth of a node from the tree's root (int).
*/
template <typename T>
int BSNode<T>::getDepth(const BSNode<T>& root) const
{
	return (root.getCurrNodeDistFromInputNode(this) - 1);
}

/*
Const 'get' function that returns the current node's distanse from the input node (int).
Input: const BSNode<T>* node
Output: the current node's distanse from the input node (int).
*/
template <typename T>
int BSNode<T>::getCurrNodeDistFromInputNode(const BSNode<T>* node) const
{
	int count = 1; //setting int 'count' variable for the depth.

	if (this->_data != node->_data) //checking if the current node matches with the requested node.
	{
		if (this->_right && node->_data > this->_data) //checking if the current BSNode has a son on the right.
		{

			count += this->_right->getCurrNodeDistFromInputNode(node);

		}

		if (this->_left && node->_data < this->_data) //checking if the current BSNode has a son on the left.
		{
			count += this->_left->getCurrNodeDistFromInputNode(node);
		}
	}
	return count; //returning the result.
}

/*
Const function that print's the values of the tree.
Input: none
Output: none
*/
template <typename T>
void BSNode<T>::printNodes() const
{
	if (this->_right) //if the current node has a child to the right, calling the function again with the right child as 'this'.
	{
		this->_right->printNodes();
	}

	cout << this->_data << "  "; //printing the data of the node.

	if (this->_left) //if the current node has a child to the left, calling the function again with the left child as 'this'.
	{
		this->_left->printNodes();
	}
}