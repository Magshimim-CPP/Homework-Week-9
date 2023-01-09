#include "BSNode.h"

/*
Constructor function for a BSNode object.
Input: std::string data
Output: none
*/
BSNode::BSNode(std::string data)
{
	_data = data;
	_left = nullptr;
	_right = nullptr;
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
	_data = other._data;
	_left = other._left;
	_right = other._right;
	_count = other._count;
	return *this;
}

/*
Destructor function for a BSNode object.
Input: none
Output: none
*/
BSNode::~BSNode() {}

void BSNode::insert(const std::string value)
{
	
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

bool BSNode::search(std::string val) const
{
	return true;
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