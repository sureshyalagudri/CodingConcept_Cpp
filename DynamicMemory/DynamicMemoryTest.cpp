#include "DynamicMemoryTest.h"


DynamicMemoryTest::DynamicMemoryTest()
{
}


DynamicMemoryTest::~DynamicMemoryTest()
{
}

void  DynamicMemoryTest::CreateAnDynamicArray(int ** &arr, int row, int col)
{
	rows = row;
	columns = col;
	arr = new int*[rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[columns];
	}

	// initialization with Zero value 
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			arr[i][j] = i+j;
		}
	}
}

void  DynamicMemoryTest::PrintArrayData(int ** arr)
{
	// Deletion 
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cout << "Row: " << i << " Col:" << j << " Value: " << arr[i][j] << endl;
		}
	}
}

void  DynamicMemoryTest::DeleteArrayData(int ** arr)
{
	// Deletion 
	for (int j = 0; j < rows; j++)
	{
		delete[] arr[j];
	}
}
