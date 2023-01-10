#pragma once

#include <iostream>

using std::cout;
using std::endl;

template <typename T>
int compare(T a, T b)
{
	return (a > b) ? -1 : ((a == b) ? 0 : 1); //if a > b, returning -1. if not, checking whether a equals to b, if it is, returning 0. if not, then a < b, returning 1.
}

template <typename T>
void bubbleSort(T* a, int size)
{
	size--;
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size - i; ++j)
		{
			if (a[j] >= a[j + 1])
			{
				T temp = a[j + 1];
				a[j + 1] = a[j];
				a[j] = temp;
			}
		}
	}
}

template <typename T>
void printArray(T* a, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << a[i] << endl;
	}
	cout << "\n";
}