#pragma once
#include <iostream>

class testClass
{
public:
	int _num;
	testClass(int num);
	~testClass();
	bool operator==(const testClass& other);
	bool operator<(const testClass& other);
	bool operator>(const testClass& other);
	bool operator>=(const testClass& other);
	friend std::ostream& operator<<(std::ostream& os, const testClass& p);
};