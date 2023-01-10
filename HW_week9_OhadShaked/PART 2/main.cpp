#include "Functions.h"
#include "testClass.h"
#include <iostream>

int main() {

	/*
	DOUBLE CHECK
	*/

	//check compare
	cout << "DOUBLE CHECK:\ncorrect print is: 1 , -1 , 0" << endl;
	cout << compare<double>(1.0, 2.5) << " , ";
	cout << compare<double>(4.5, 2.4) << " , ";
	cout << compare<double>(4.4, 4.4) << endl;

	//check bubbleSort
	double doubleArr[5] = { 1000.0, 2.0, 3.4, 17.0, 50.0 };
	bubbleSort<double>(doubleArr, 5);

	//check printArray
	cout << "\ncorrect print is sorted array" << endl;
	printArray<double>(doubleArr, 5);

	/*
	CHAR CHECK
	*/

	//check compare
	cout << "CHAR CHECK:\ncorrect print is: 1 , 0 , -1" << endl;
	cout << compare<char>('a', 'b') << " , "; //result is 1
	cout << compare<char>('c', 'c') << " , "; //result is 0
	cout << compare<char>('h', 'd') << endl; //result is -1

	//check bubbleSort
	char charArr[6] = { 'a', 'c', 'b', 'z', 'r', 'x' };
	bubbleSort<char>(charArr, 6);

	//check printArray
	cout << "\ncorrect print is sorted array" << endl;
	printArray<char>(charArr, 6);

	/*
	CLASS CHECK
	*/

	//creating testClass objects
	testClass Obj1 = testClass(2);
	testClass Obj2 = testClass(7);
	testClass Obj3 = testClass(5);

	//check compare
	cout << "\nCLASS CHECK:\ncorrect print is: 1 , 0 , -1" << endl;
	cout << compare<testClass>(Obj1, Obj2) << " , "; //result is 1
	cout << compare<testClass>(Obj1, Obj1) << " , "; //result is 0
	cout << compare<testClass>(Obj2, Obj3) << endl; //result is -1

	//check bubbleSort
	testClass ObjArr[3] = { Obj1 , Obj2 , Obj3 };
	bubbleSort<testClass>(ObjArr, 3);

	//check printArray
	cout << "\ncorrect print is sorted array" << endl;
	printArray<testClass>(ObjArr, 3);

	system("pause");
	return 1;
}