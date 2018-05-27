#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include "DiamondInheritance.h"
#include "AbstractClass.h"
#include "VirtulUse.h"
#include "FunctionOverload.h"

using namespace std;

int main()
{
	cout << "Main:Start" << endl;

	// Can not create object of Pure virtual function.
	// AbstractClass * abs = new AbstractClass();
	// Need to inherit it and call 
	DerivedOfAbstract * abc = new DerivedOfAbstract();
	abc->PrintData();
	abc->Add(2,5);
	delete abc;

	cout << endl;
	// Use of vertual keyword.
	VirtulUse * xyz = new VirtulUse();
	xyz->printData();
	xyz->Add(4, 5);
	delete xyz;
	cout << endl;

	// How to resolve diamond inheritance problem.
	// By inherting the class with virtual keyword diamond issue\ambigous is reolved.
	DiamondInheritance * dim = new DiamondInheritance();
	dim->PrintData();
	delete dim;
	cout << endl;

	// Function Overloading 
	// Function overloading does not differs from return type, 
	// compile time error will be shown.
	FunctionOverload *a = new FunctionOverload();
	a->Add(4, 5);
	//a->Add(4, 5.8); // Compile time error.
	a->Add(4, 5);

	vector<double>dbl;
	dbl.push_back(2.2);
	dbl.push_back(4.2);
	dbl.push_back(6.2);
	dbl.push_back(8.2);
	a->Add(dbl[0], dbl[1], dbl[2], dbl[3]); // This will give warning:warning C4244: 'argument': conversion from 'double' to 'int', possible loss of data

	delete a;

	//  

	cout << "Main:End" << endl;
	return 0;
}