#pragma once
#include<iostream>
using namespace std;
class DynamicMemoryTest
{
private:
	int rows = 0;
	int columns=0;
public:
	DynamicMemoryTest();
	~DynamicMemoryTest();

	void CreateAnDynamicArray(int ** &arr, int rows, int cols);
	void PrintArrayData(int ** arr);
	void DeleteArrayData(int ** arr);
};

