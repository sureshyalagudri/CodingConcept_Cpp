#include <stdio.h>
#include <memory>
#include <iostream>
#include "DynamicMemoryTest.h"
#include "Class1.h"
#include "Mystring.h"

using namespace std;

void swapwithtemp(char *a, char *b)
{
	char * temp = NULL;
	temp = a;
	a = b;
	b = temp;
}

void swap(char *a, char *b)
{
	if (a == b) // Check if the two addresses are same
		return;

	*a ^= *b;
	*b ^= *b;
	*a ^= *b;
}

int main()
{
	cout << "Main:Start------>" << endl;

#pragma region Arrayof Memory
	// Create an array.
	DynamicMemoryTest *arrMemory = new DynamicMemoryTest();
	int ** arrData;
	arrMemory->CreateAnDynamicArray(arrData, 2, 2);

	// Print Data.
	arrMemory->PrintArrayData(arrData);

	// Delete Array.
	arrMemory->DeleteArrayData(arrData);

	delete arrMemory;
#pragma endregion

	// Calculating object memory.
	Class1 cls1;
	cout << "Size of CLass1: " << sizeof(cls1) << endl;

#pragma region Mystring
	// Create string class using char.
	char * firstName = "Suresh";
	char * lastName = "Yalagudri";
	Mystring str1(firstName);
	Mystring str2(lastName);

	// Copy constructor will be called.
	// A copy constructor is used to initialize a previously 
	// uninitialized object from some other object's data.
	Mystring str3 = str1;
	cout << "string 1: " << str1.GetData() << endl;
	cout << "string 2: " << str2.GetData() << endl;


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
#pragma endregion

#pragma region SWAP
	char * a = "Suresh";
	char * b = "Yalagudri";
	swapwithtemp(a, b);
	cout << a << " " << b << endl;

	string s1 = "suresh";
	string s2 = "yalagudri";

	s1.swap(s2);
	cout << s1.c_str() << endl;
	cout << s2.c_str() << endl;

#pragma endregion

#pragma region SmartPointer
	auto_ptr<Class1> p1(new Class1);
#pragma endregion

	cout << "Main:End------>" << endl;
	return 0;
}