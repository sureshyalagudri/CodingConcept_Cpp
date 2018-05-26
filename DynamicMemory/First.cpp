#include <stdio.h>
#include <iostream>
#include "DynamicMemoryTest.h"
#include "Class1.h"
#include "Mystring.h"

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


	// Create string class using char.
	char * firstName = "Suresh";
	char * lastName = "Yalagudri";
	Mystring str1(firstName);
	Mystring str2(lastName);
	
	// Copy constructor will be called.
	// A copy constructor is used to initialize a previously 
	// uninitialized object from some other object's data.
	Mystring str3=str1;
	cout << "string 1: " << str1.GetData() << endl;
	cout << "string 2: " << str2.GetData() <<endl;


	Mystring str4("abc");
	// Assignment operator will be called.
	// An assignment operator is used to replace the data of a 
	// previously initialized object with some other object's data
	str3 = str4;

	if (str3 < str1)
	{

	}
	
	Mystring str5 = str1 + str2;

	cout << "string 1: " << str1.GetData() << endl;
	cout << "string 2: " << str2.GetData() << endl;
	cout << "string 3: " << str3.GetData() << endl;
	cout << "string 4: " << str4.GetData() << endl;
	cout << "string 5: " << str5.GetData() << endl;

	cout << "Main:End------>" << endl;
	return 0;
}