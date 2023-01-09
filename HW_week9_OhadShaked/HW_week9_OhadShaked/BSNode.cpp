#include "BSNode.h"

/*
Constructor function for a BSNode object.
Input: std::string data
Output: none
*/
BSNode::BSNode(std::string data)
{
	this->_data = data;
	this->_left = nullptr;
	this->_right = nullptr;
	this->_count = 1;
}

/*
Copy constructor function for a BSNode object.
Input: const BSNode& other
Output: none
*/
BSNode::BSNode(const BSNode& other)
{
	this->_data = other._data;
	this->_left = other._left;
	this->_right = other._right;
	this->_count = other._count;
}

/*
Function for operator overloading on '=' to copy 'other's' BSNode values to 'this' BSNode (BSNode&).
Input: const BSNode& other
Output: *this (BSNode&)
*/
BSNode& BSNode::operator=(const BSNode& other)
{
	this->_data = other._data;
	this->_left = other._left;
	this->_right = other._right;
	this->_count = other._count;
	return *this;
}

/*
Destructor function for a BSNode object.
Input: none
Output: none
*/
BSNode::~BSNode() {}

/*
Function to insert a given value into the BS tree (or increase it's _count field, if an object with the same value already exsist's).
Input: const std::string value
Output: none
*/
void BSNode::insert(const std::string value)
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
bool BSNode::isLeaf() const
{
	return !(this->getLeft() || this->getRight());
}

/*
Const 'get' function that returns the '_left' field of an BSNode object (BSNode*).
Input: none
Output: this->_left (BSNode*).
*/
BSNode* BSNode::getLeft() const
{
	return this->_left;
}

/*
Const 'get' function that returns the '_right' field of an BSNode object (BSNode*).
Input: none
Output: this->_right (BSNode*).
*/
BSNode* BSNode::getRight() const
{
	return this->_right;
}

/*
Const 'get' function that returns the '_data' field of an BSNode object (std::string).
Input: none
Output: this->_data (std::string).
*/
std::string BSNode::getData() const
{
	return this->_data;
}

/*
Const 'get' function that returns the '_count' field of an BSNode object (int).
Input: none
Output: this->_count (int).
*/
int BSNode::getCount() const
{
	return this->_count;
}

/*
Function to search whether or not a given value already exists in one of the tree nodes (bool).
Input: std::string val
Output: true/false (bool)
*/
bool BSNode::search(std::string val) const
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

int BSNode::getHeight() const
{
	return true;
}

/*
Const 'get' function that returns the depth of a node from the tree's root (int).
Input: const BSNode& root
Output: the depth of a node from the tree's root (int).
*/
int BSNode::getDepth(const BSNode& root) const
{
	return (root.getCurrNodeDistFromInputNode(this));
}

/*
Const 'get' function that returns the current node's distanse from the input node (int).
Input: const BSNode* node
Output: the current node's distanse from the input node (int).
*/
int BSNode::getCurrNodeDistFromInputNode(const BSNode* node) const
{
	int count = 1; //setting int 'count' variable for the depth.

	if (this->getData() != node->getData()) //checking if the current node matches with the requested node.
	{
		if (this->getLeft()) //checking if the current BSNode has a son on the left.
		{
			count += this->getLeft()->getCurrNodeDistFromInputNode(node);
		}

		else if (this->getRight()) //checking if the current BSNode has a son on the right.
		{

			count += this->getRight()->getCurrNodeDistFromInputNode(node);

		}
	}
	return count; //returning the result.
}