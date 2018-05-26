#pragma once
#include <stdio.h>
#include <iostream>

using namespace std;
class AbstractClass
{
public:
	AbstractClass();
	~AbstractClass();

	virtual void PrintData() = 0;
	int Add(int a, int b);
};


class DerivedOfAbstract: public AbstractClass
{
public:
	DerivedOfAbstract() { cout << "DerivedOfAbstract" << endl; };
	~DerivedOfAbstract() { cout << "~DerivedOfAbstract" << endl; };

	virtual void PrintData() { cout << "DerivedOfAbstract:PrintData" << endl; }
};