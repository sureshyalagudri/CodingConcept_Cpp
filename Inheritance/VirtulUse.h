#pragma once
#include <stdio.h>
#include <iostream>

using namespace std;
class VirtulUse
{
public:
	VirtulUse();
	virtual ~VirtulUse();

	virtual void printData() { cout << "VirtulUse::printData" << endl; }
	virtual int Add(int a, int b) { cout << "VirtulUse::Add" << endl; return a + b; }
};

class DerivedofVirtual:public VirtulUse
{
public:
	DerivedofVirtual() { cout << "DerivedofVirtual" << endl; };
	~DerivedofVirtual() { cout << "~DerivedofVirtual" << endl; };

	void printData() { cout << "DerivedofVirtual::printData" << endl; }
	int Add(double a, double b) { cout << "DerivedofVirtual::Add" << endl; return a + b; return a + b; }
};

