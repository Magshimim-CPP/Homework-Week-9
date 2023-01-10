#include "testClass.h"

testClass::testClass(int num)
{
	_num = num;
}

testClass::~testClass() {}

bool testClass::operator==(const testClass& other)
{
	return (this->_num == other._num);
}

bool testClass::operator<(const testClass& other)
{
	return (this->_num < other._num);
}

bool testClass::operator>(const testClass& other)
{
	return (this->_num > other._num);
}

bool testClass::operator>=(const testClass& other)
{
	return (this->_num >= other._num);
}

std::ostream& operator<<(std::ostream& OutStream, const testClass& testObj)
{
	OutStream << testObj._num;
	return OutStream;
}