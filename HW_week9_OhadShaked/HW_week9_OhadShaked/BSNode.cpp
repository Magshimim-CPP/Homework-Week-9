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

bool BSNode::isLeaf() const
{
	return !(this->getLeft() || this->getRight());
}

BSNode* BSNode::getLeft() const
{
	return this->_left;
}

BSNode* BSNode::getRight() const
{
	return this->_right;
}

std::string BSNode::getData() const
{
	return this->_data;
}

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