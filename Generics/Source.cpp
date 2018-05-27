#include <stdio.h>
#include <iostream>
#include "GenericTest.h"
#include "Vector3D.h"

using namespace std;

int main() 
{
	cout << "Main Start" << endl;

	// Only header file is sufficient 
	// any number of parameters can be used
	GenericTest<int> test;
	cout<<test.Add(2, 8.2)<<endl;
	cout<<test.Add(2 , 6, 8)<<endl;

	GenericTest<string> test1;
	cout << test1.Add("Suresh ", "Yalagudri").c_str() << endl;
	cout << test1.Add("Suresh", " M ", "Yalagudri").c_str() << endl;


	// Need to overload operator + or any other operations to use template class 
	// if not compile time error will be shown.
	Vector3D v1(1.2, 2.3, 2.4);
	Vector3D v2(1.8, 8.6, 2.4);
	GenericTest<Vector3D> testVector;
	Vector3D v3 = testVector.Add(v1, v2);

	cout << "Main End" << endl;
	return 0;
}
