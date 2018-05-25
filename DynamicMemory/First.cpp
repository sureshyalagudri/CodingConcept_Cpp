#include <stdio.h>
#include <iostream>
#include "DynamicMemoryTest.h"
#include "Class1.h"

using namespace std;

int main()
{
	cout << "Main:Start------>" << endl;
	
	// Create an array.
	DynamicMemoryTest *arrMemory = new DynamicMemoryTest();
	int ** arrData;
	arrMemory->CreateAnDynamicArray(arrData, 2, 2);

	// Print Data.
	arrMemory->PrintArrayData(arrData);

	// Delete Array.
	arrMemory->DeleteArrayData(arrData);
	
	delete arrMemory;

	// Calculating object memory.
	Class1 cls1;
	cout << "Size of CLass1: "<<sizeof(cls1) << endl;


	cout << "Main:End------>" << endl;
	return 0;
}