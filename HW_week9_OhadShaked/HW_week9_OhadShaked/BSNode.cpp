#include "BSNode.h"

using std::cout;

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
Function for operator overloading on '=' to copy 'other's' BSNode values to 'this' BSNode (BSNode&).
Input: const BSNode& other
Output: *this (BSNode&)
*/
BSNode& BSNode::operator=(const BSNode& other)
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
BSNode::~BSNode()
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
	return !(this->_left || this->_right);
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

/*
Const 'get' function that returns the hight of a tree from the given BSNode (longest route below) (int).
Input: none
Output: the hight of a tree from the given BSNode (int).
*/
int BSNode::getHeight() const
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

	if (this->_data != node->_data) //checking if the current node matches with the requested node.
	{
		if (this->_left) //checking if the current BSNode has a son on the left.
		{
			count += this->_left->getCurrNodeDistFromInputNode(node);
		}

		else if (this->_right) //checking if the current BSNode has a son on the right.
		{

			count += this->_right->getCurrNodeDistFromInputNode(node);

		}
	}
	return count; //returning the result.
}

/*
Const function that print's the values of the tree.
Input: none
Output: none
*/
void BSNode::printNodes() const
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