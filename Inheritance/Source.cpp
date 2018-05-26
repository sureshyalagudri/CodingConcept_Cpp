#include <stdio.h>
#include <string.h>
#include <iostream>
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
	//  a->Add(4, 5.8); // Compile time error.
	a->Add(4, 5);
	delete a;

	//  

	cout << "Main:End" << endl;
	return 0;
}